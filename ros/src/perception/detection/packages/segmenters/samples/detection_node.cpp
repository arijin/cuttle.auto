/*
 * Copyright (C) 2019 by AutoSense Organization. All rights reserved.
 * Gary Chan <chenshj35@mail2.sysu.edu.cn>
 */

#include <pcl_conversions/pcl_conversions.h>  // pcl::fromROSMsg
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <std_msgs/Header.h>
#include <visualization_msgs/MarkerArray.h>

#include <memory>

#include "common/color.hpp"
#include "common/parameter.hpp"  // common::getSegmenterParams
#include "common/publisher.hpp"  // common::publishCloud
#include "common/time.hpp"       // common::Clock
#include "common/types/type.h"   // PointICloudPtr
#include "object_builders/object_builder_manager.hpp"
#include "roi_filters/roi.hpp"               // roi::applyROIFilter
#include "segmenters/segmenter_manager.hpp"  // segmenter::createGroundSegmenter

using namespace autosense;  // NOLINT

const std::string param_ns_prefix_ = "detect";  // NOLINT
std::string frame_id_ = "";                     // NOLINT
bool use_noise_filter_;
NoiseParams params_noise_;
bool use_roi_filter_;
ROIParams params_roi_;
bool use_ground_remover_;
bool use_non_ground_segmenter_;
bool is_object_builder_open_;
bool use_object_model_filter_;
VolumetricModelParams params_volumetric_model;

// ROS Subscriber
ros::Subscriber pointcloud_sub_;
// ROS Publisher
ros::Publisher ground_pub_;
ros::Publisher nonground_pub_;
ros::Publisher pc_filtered_pub_;
ros::Publisher clusters_pub_;
ros::Publisher objects_pub_;
ros::Publisher objects_msg_pub_;
/// @note Core components
std::unique_ptr<segmenter::BaseSegmenter> ground_remover_;
std::unique_ptr<segmenter::BaseSegmenter> segmenter_;
std::unique_ptr<object_builder::BaseObjectBuilder> object_builder_;

void OnPointCloud(const sensor_msgs::PointCloud2ConstPtr& ros_pc2) {
    common::Clock clock;

    PointICloudPtr cloud_in(new PointICloud);
    pcl::fromROSMsg(*ros_pc2, *cloud_in);
    // ROS_INFO_STREAM(" Cloud inputs: #" << cloud_in->size() << " Points");

    std_msgs::Header header = ros_pc2->header;

    // removeNaNFromPointCloud函数会打乱cloud的保存格式width*height
    // std::vector<int> indices;
    PointICloudPtr cloud(new PointICloud);
    // pcl::removeNaNFromPointCloud(*cloud_in, *cloud, indices);
    *cloud = *cloud_in;

    ROS_INFO_STREAM(" Height" << cloud->height << " ,Width: " << cloud->width);

    if (use_noise_filter_) {
        roi::applyNoiseFilter<PointI>(params_noise_,
                                      cloud);  // remove tail noises
    }
    common::publishCloud<PointI>(pc_filtered_pub_, header, *cloud);
    if (use_roi_filter_) {
        roi::applyROIFilter<PointI>(params_roi_, cloud, true);
    }

    std::vector<PointICloudPtr> cloud_clusters;
    PointICloudPtr cloud_ground(new PointICloud);
    PointICloudPtr cloud_nonground(new PointICloud);

    if (use_ground_remover_) {
        ground_remover_->segment(*cloud, cloud_clusters);
        *cloud_ground = *cloud_clusters[0];
        *cloud_nonground = *cloud_clusters[1];
    } else {
        // water scene with no ground.
        *cloud_nonground = *cloud;
    }

    // reset clusters
    cloud_clusters.clear();
    if (use_non_ground_segmenter_) {
        segmenter_->segment(*cloud_nonground, cloud_clusters);
        common::publishClustersCloud<PointI>(clusters_pub_, header,
                                             cloud_clusters);
    }

    common::publishCloud<PointI>(ground_pub_, header, *cloud_ground);
    common::publishCloud<PointI>(nonground_pub_, header, *cloud_nonground);

    if (is_object_builder_open_) {
        std::vector<autosense::ObjectPtr> objects;
        object_builder_->build(cloud_clusters, &objects);
        if (use_object_model_filter_) {
            objects = roi::applyVolumetricModelFilter(params_volumetric_model,
                                                      objects);
        }
        autosense::common::publishObjectsMarkers(
            objects_pub_, header, autosense::common::MAGENTA.rgbA, objects);
        autosense::common::publishObjectsMsg(objects_msg_pub_, header, objects);
    }

    ROS_INFO_STREAM("\n");
    // ROS_INFO_STREAM("Cloud processed. Took " << clock.takeRealTime()
    //                                          << "ms.\n");
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "detection_node");

    // Node handle
    ros::NodeHandle nh = ros::NodeHandle(), private_nh = ros::NodeHandle("~");

    /// @brief Load ROS parameters from rosparam server
    private_nh.getParam(param_ns_prefix_ + "/frame_id", frame_id_);

    std::string sub_pc_topic, pub_pc_ground_topic, pub_pc_nonground_topic,
        pub_pc_filtered_topic, pub_pc_clusters_topic, pub_object_topic;
    int sub_pc_queue_size;
    private_nh.getParam(param_ns_prefix_ + "/sub_pc_topic", sub_pc_topic);
    private_nh.getParam(param_ns_prefix_ + "/sub_pc_queue_size",
                        sub_pc_queue_size);
    private_nh.getParam(param_ns_prefix_ + "/pub_pc_ground_topic",
                        pub_pc_ground_topic);
    private_nh.getParam(param_ns_prefix_ + "/pub_pc_nonground_topic",
                        pub_pc_nonground_topic);
    private_nh.getParam(param_ns_prefix_ + "/pub_pc_filtered_topic",
                        pub_pc_filtered_topic);
    private_nh.getParam(param_ns_prefix_ + "/pub_pc_clusters_topic",
                        pub_pc_clusters_topic);
    private_nh.getParam(param_ns_prefix_ + "/pub_object_topic",
                        pub_object_topic);

    // Pointcloud Process Params
    private_nh.param<bool>(param_ns_prefix_ + "/use_noise_filter",
                           use_noise_filter_, false);
    params_noise_ = common::getNoiseParams(private_nh, param_ns_prefix_);

    /// @note Important to use roi filter for "Ground remover"
    private_nh.param<bool>(param_ns_prefix_ + "/use_roi_filter",
                           use_roi_filter_, false);
    params_roi_ = common::getRoiParams(private_nh, param_ns_prefix_);

    private_nh.param<bool>(param_ns_prefix_ + "/use_ground_remover",
                           use_ground_remover_, false);
    private_nh.param<bool>(param_ns_prefix_ + "/use_non_ground_segmenter",
                           use_non_ground_segmenter_, false);

    // Ground remover & non-ground segmenter
    std::string ground_remover_type, non_ground_segmenter_type;
    private_nh.param<std::string>(param_ns_prefix_ + "/ground_remover_type",
                                  ground_remover_type,
                                  "GroundPlaneFittingSegmenter");

    private_nh.param<std::string>(
        param_ns_prefix_ + "/non_ground_segmenter_type",
        non_ground_segmenter_type, "RegionEuclideanSegmenter");
    SegmenterParams param =
        common::getSegmenterParams(private_nh, param_ns_prefix_);

    if (use_ground_remover_) {
        param.segmenter_type = ground_remover_type;
        ground_remover_ = segmenter::createGroundSegmenter(param);
    }

    if (use_non_ground_segmenter_) {
        param.segmenter_type = non_ground_segmenter_type;
        segmenter_ = segmenter::createNonGroundSegmenter(param);
    }

    // Object Process Params
    private_nh.param<bool>(param_ns_prefix_ + "/is_object_builder_open",
                           is_object_builder_open_, false);
    if (is_object_builder_open_) {
        object_builder_ = object_builder::createObjectBuilder();
        if (nullptr == object_builder_) {
            ROS_FATAL("Failed to create object_builder_.");
            return -1;
        }

        private_nh.param<bool>(param_ns_prefix_ + "/use_object_model_filter",
                               use_object_model_filter_, false);
        params_volumetric_model =
            common::getVolumetricModelParams(private_nh, param_ns_prefix_);

        std::string pub_objects_segmented_topic;
        private_nh.getParam(param_ns_prefix_ + "/pub_objects_segmented_topic",
                            pub_objects_segmented_topic);
        objects_pub_ = nh.advertise<visualization_msgs::MarkerArray>(
            pub_objects_segmented_topic, 1);
    }

    // Subscribe & Publish
    ground_pub_ =
        nh.advertise<sensor_msgs::PointCloud2>(pub_pc_ground_topic, 1);
    nonground_pub_ =
        nh.advertise<sensor_msgs::PointCloud2>(pub_pc_nonground_topic, 1);
    pc_filtered_pub_ =
        nh.advertise<sensor_msgs::PointCloud2>(pub_pc_filtered_topic, 1);
    clusters_pub_ =
        nh.advertise<sensor_msgs::PointCloud2>(pub_pc_clusters_topic, 1);
    objects_msg_pub_ =
        nh.advertise<vision_msgs::Detection3DArray>(pub_object_topic, 1);

    pointcloud_sub_ = nh.subscribe<sensor_msgs::PointCloud2>(
        sub_pc_topic, sub_pc_queue_size, OnPointCloud);

    ROS_INFO("detection_node started...");

    ros::Rate fps(40);
    while (ros::ok()) {
        ros::spinOnce();
        fps.sleep();
    }

    ROS_INFO("detection_node exited...");

    return 0;
}
