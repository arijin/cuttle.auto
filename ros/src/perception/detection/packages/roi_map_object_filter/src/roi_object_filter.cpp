/*
 * Copyright 2018 Autoware Foundation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * use tf api in https://github.com/davheld/tf/blob/master/include/tf/transform_datatypes.h
 ********************
 *  v1.0: amc-nu (abrahammonrroy@yahoo.com)
 *
 * roi_object_filter.cpp
 *
 *  Created on: October, 23rd, 2018
 */

#include "roi_object_filter/roi_object_filter.h"

/**
 * @brief publish Objects' 3D OBB and velocity arrow
 * @param publisher
 * @param header
 * @param color
 * @param objects
 * @param trans
 */
static void publishObjectsMarkers(
    const ros::Publisher &publisher,
    const std_msgs::Header &header,
    const std_msgs::ColorRGBA &color,
    const vision_msgs::Detection3DArray &objects_array)
{
  // clear all markers before
  visualization_msgs::MarkerArray empty_markers;
  visualization_msgs::Marker clear_marker;
  clear_marker.header = header;
  clear_marker.ns = "objects";
  clear_marker.id = 0;
  clear_marker.action = clear_marker.DELETEALL;
  clear_marker.lifetime = ros::Duration();
  empty_markers.markers.push_back(clear_marker);
  publisher.publish(empty_markers);

  if (objects_array.detections.size() <= 0)
  {
    ROS_WARN("Publish empty object marker.");
    return;
  }
  else
  {
    ROS_INFO("Publishing %lu objects markers.", objects_array.detections.size());
  }

  visualization_msgs::MarkerArray object_markers;
  for (size_t obj = 0u; obj < objects_array.detections.size(); ++obj)
  {
    /*
         * @note Apollo's Object Coordinate
         *          |x
         *      C   |   D-----------
         *          |              |
         *  y---------------     length
         *          |              |
         *      B   |   A-----------
         */
    vision_msgs::Detection3D object = objects_array.detections[obj];
    Eigen::Vector3d center(object.bbox.center.position.x, object.bbox.center.position.y, object.bbox.center.position.z);
    const double yaw = tf::getYaw(object.bbox.center.orientation);
    const double &length = object.bbox.size.x;
    const double &width = object.bbox.size.y;
    const double &height = object.bbox.size.z;

    Eigen::Vector3d ldir(cos(yaw), sin(yaw), 0);
    Eigen::Vector3d odir(-ldir[1], ldir[0], 0);
    Eigen::Vector3d bottom_quad[8];
    double half_l = length / 2;
    double half_w = width / 2;
    double h = height;
    // A(-half_l, -half_w)
    bottom_quad[0] = center + ldir * -half_l + odir * -half_w;
    // B(-half_l, half_w)
    bottom_quad[1] = center + ldir * -half_l + odir * half_w;
    // C(half_l, half_w)
    bottom_quad[2] = center + ldir * half_l + odir * half_w;
    // D(half_l, -half_w)
    bottom_quad[3] = center + ldir * half_l + odir * -half_w;
    // top 4 vertices
    bottom_quad[4] = bottom_quad[0];
    bottom_quad[4](2) += h;
    bottom_quad[5] = bottom_quad[1];
    bottom_quad[5](2) += h;
    bottom_quad[6] = bottom_quad[2];
    bottom_quad[6](2) += h;
    bottom_quad[7] = bottom_quad[3];
    bottom_quad[7](2) += h;

    Eigen::MatrixXf OBB(8, 3);
    OBB << bottom_quad[0](0), bottom_quad[0](1), bottom_quad[0](2),
        bottom_quad[1](0), bottom_quad[1](1), bottom_quad[1](2),
        bottom_quad[2](0), bottom_quad[2](1), bottom_quad[2](2),
        bottom_quad[3](0), bottom_quad[3](1), bottom_quad[3](2),
        bottom_quad[4](0), bottom_quad[4](1), bottom_quad[4](2),
        bottom_quad[5](0), bottom_quad[5](1), bottom_quad[5](2),
        bottom_quad[6](0), bottom_quad[6](1), bottom_quad[6](2),
        bottom_quad[7](0), bottom_quad[7](1), bottom_quad[7](2);

    visualization_msgs::Marker box, dir_arrow;
    box.header = dir_arrow.header = header;
    box.ns = dir_arrow.ns = "objects";
    box.id = obj;
    dir_arrow.id = obj + objects_array.detections.size();
    box.type = visualization_msgs::Marker::LINE_LIST;
    dir_arrow.type = visualization_msgs::Marker::ARROW;
    geometry_msgs::Point p[24];
    // Ground side
    // A->B
    p[0].x = OBB(0, 0);
    p[0].y = OBB(0, 1);
    p[0].z = OBB(0, 2);
    p[1].x = OBB(1, 0);
    p[1].y = OBB(1, 1);
    p[1].z = OBB(1, 2);
    // B->C
    p[2].x = OBB(1, 0);
    p[2].y = OBB(1, 1);
    p[2].z = OBB(1, 2);
    p[3].x = OBB(2, 0);
    p[3].y = OBB(2, 1);
    p[3].z = OBB(2, 2);
    // C->D
    p[4].x = OBB(2, 0);
    p[4].y = OBB(2, 1);
    p[4].z = OBB(2, 2);
    p[5].x = OBB(3, 0);
    p[5].y = OBB(3, 1);
    p[5].z = OBB(3, 2);
    // D->A
    p[6].x = OBB(3, 0);
    p[6].y = OBB(3, 1);
    p[6].z = OBB(3, 2);
    p[7].x = OBB(0, 0);
    p[7].y = OBB(0, 1);
    p[7].z = OBB(0, 2);

    // Top side
    // E->F
    p[8].x = OBB(4, 0);
    p[8].y = OBB(4, 1);
    p[8].z = OBB(4, 2);
    p[9].x = OBB(5, 0);
    p[9].y = OBB(5, 1);
    p[9].z = OBB(5, 2);
    // F->G
    p[10].x = OBB(5, 0);
    p[10].y = OBB(5, 1);
    p[10].z = OBB(5, 2);
    p[11].x = OBB(6, 0);
    p[11].y = OBB(6, 1);
    p[11].z = OBB(6, 2);
    // G->H
    p[12].x = OBB(6, 0);
    p[12].y = OBB(6, 1);
    p[12].z = OBB(6, 2);
    p[13].x = OBB(7, 0);
    p[13].y = OBB(7, 1);
    p[13].z = OBB(7, 2);
    // H->E
    p[14].x = OBB(7, 0);
    p[14].y = OBB(7, 1);
    p[14].z = OBB(7, 2);
    p[15].x = OBB(4, 0);
    p[15].y = OBB(4, 1);
    p[15].z = OBB(4, 2);

    // Around side
    // A->E
    p[16].x = OBB(0, 0);
    p[16].y = OBB(0, 1);
    p[16].z = OBB(0, 2);
    p[17].x = OBB(4, 0);
    p[17].y = OBB(4, 1);
    p[17].z = OBB(4, 2);
    // B->F
    p[18].x = OBB(1, 0);
    p[18].y = OBB(1, 1);
    p[18].z = OBB(1, 2);
    p[19].x = OBB(5, 0);
    p[19].y = OBB(5, 1);
    p[19].z = OBB(5, 2);
    // C->G
    p[20].x = OBB(2, 0);
    p[20].y = OBB(2, 1);
    p[20].z = OBB(2, 2);
    p[21].x = OBB(6, 0);
    p[21].y = OBB(6, 1);
    p[21].z = OBB(6, 2);
    // D->H
    p[22].x = OBB(3, 0);
    p[22].y = OBB(3, 1);
    p[22].z = OBB(3, 2);
    p[23].x = OBB(7, 0);
    p[23].y = OBB(7, 1);
    p[23].z = OBB(7, 2);

    for (size_t pi = 0u; pi < 24; ++pi)
    {
      box.points.push_back(p[pi]);
    }
    box.scale.x = 0.15;
    box.color = color;
    object_markers.markers.push_back(box);
  }

  publisher.publish(object_markers);
}

geometry_msgs::Point
RosRoiObjectFilterApp::TransformPoint(const geometry_msgs::Point &in_point, const tf::Transform &in_tf)
{
  tf::Point tf_point;
  tf::pointMsgToTF(in_point, tf_point);

  tf_point = in_tf * tf_point;

  geometry_msgs::Point ros_point;
  tf::pointTFToMsg(tf_point, ros_point);

  return ros_point;
}

tf::StampedTransform
RosRoiObjectFilterApp::FindTransform(const std::string &in_target_frame, const std::string &in_source_frame)
{
  tf::StampedTransform transform;

  try
  {
    transform_listener_->lookupTransform(in_target_frame, in_source_frame, ros::Time(0), transform);
  }
  catch (tf::TransformException &ex)
  {
    ROS_ERROR("%s", ex.what());
    return transform;
  }

  return transform;
}

bool RosRoiObjectFilterApp::CheckPointInGrid(const grid_map::GridMap &in_grid_map,
                                             const cv::Mat &in_grid_image,
                                             const geometry_msgs::Point &in_point)
{
  // calculate out_grid_map position
  grid_map::Position map_pos = in_grid_map.getPosition();
  double origin_x_offset = in_grid_map.getLength().x() / 2.0 - map_pos.x();
  double origin_y_offset = in_grid_map.getLength().y() / 2.0 - map_pos.y();
  // coordinate conversion for cv image
  double cv_x = (in_grid_map.getLength().y() - origin_y_offset - in_point.y) / in_grid_map.getResolution();
  double cv_y = (in_grid_map.getLength().x() - origin_x_offset - in_point.x) / in_grid_map.getResolution();

  // check coords are inside the gridmap
  if (cv_x < 0 || cv_x > in_grid_image.cols || cv_y < 0 || cv_y > in_grid_image.rows)
  {
    return false;
  }

  //GRID_OCCUPANCY_ROAD if road(free water)
  if (in_grid_image.at<uchar>(cv_y, cv_x) == GRID_OCCUPANCY_ROAD) // 128
  {
    return true;
  }

  return false;
}

void RosRoiObjectFilterApp::SyncedDetectionsCallback(const vision_msgs::Detection3DArray::ConstPtr &in_detections,
                                                     const autoware_msgs::GridMapInfo::ConstPtr &in_gridmap)
{
  if (nullptr == in_detections || nullptr == in_gridmap)
  {
    ROS_INFO("[%s] Empty input messages, for details check the topics.", __APP_NAME__);
    return;
  }
  ROS_INFO_STREAM("Filter Callback.");

  grid_map::GridMap current_grid;
  grid_map::GridMapRosConverter::fromMessage((*in_gridmap).map, current_grid);

  if (!current_grid.exists(wayarea_layer_name_))
  {
    ROS_INFO("[%s] No wayarea layer '%s' in gridmap, for details check the wayarea published package.", __APP_NAME__,
             wayarea_layer_name_.c_str());
    roi_objects_publisher_.publish(*in_detections);
    return;
  }

  cv::Mat grid_wayarea_image;
  grid_map::GridMapCvConverter::toImage<unsigned char, 1>(current_grid,
                                                          wayarea_layer_name_,
                                                          CV_8UC1,
                                                          GRID_MIN_VALUE,
                                                          GRID_MAX_VALUE,
                                                          grid_wayarea_image);

  // Transform
  tf::StampedTransform wayarea2map_transform_;
  wayarea2map_transform_.frame_id_ = "/map";
  wayarea2map_transform_.child_frame_id_ = current_grid.getFrameId();
  wayarea2map_transform_.setOrigin(tf::Vector3(in_gridmap->trans.translation.x, in_gridmap->trans.translation.y, in_gridmap->trans.translation.z));
  wayarea2map_transform_.setRotation(tf::Quaternion(in_gridmap->trans.rotation.x, in_gridmap->trans.rotation.y, in_gridmap->trans.rotation.z, in_gridmap->trans.rotation.w));

  tf::StampedTransform sensor2map_transform;
  // while (true)
  // {
  //   sensor2map_transform = FindTransform("/map", in_detections->header.frame_id);
  //   if (abs(in_detections->header.stamp.toSec() - sensor2map_transform.stamp_.toSec()) < 0.1)
  //     break;
  // }
  sensor2map_transform = FindTransform("/map", in_detections->header.frame_id);
  ROS_INFO_STREAM("cloud time: " << std::fixed << std::setprecision(5) << in_detections->header.stamp.toSec() << ", "
                                 << "tf time:" << std::fixed << std::setprecision(5) << sensor2map_transform.stamp_.toSec());

  tf::Transform sensor2wayarea_transform = wayarea2map_transform_.inverse() * sensor2map_transform;

  // object filter
  vision_msgs::Detection3DArray in_roi_objects;
  vision_msgs::Detection3DArray out_roi_objects;

  in_roi_objects.header = in_detections->header;
  out_roi_objects.header = in_detections->header;

  // #pragma omp for
  int in_nums = 0, out_nums = 0;
  for (unsigned int i = 0; i < in_detections->detections.size(); i++)
  {
    vision_msgs::Detection3D object = in_detections->detections[i];

    geometry_msgs::Point center = object.bbox.center.position;
    const double yaw = tf::getYaw(object.bbox.center.orientation);
    const double &length = object.bbox.size.x;
    const double &width = object.bbox.size.y;
    const double &height = object.bbox.size.z;

    Eigen::Vector3d center_vector(center.x, center.y, center.z);
    Eigen::Vector3d ldir(cos(yaw), sin(yaw), 0);
    Eigen::Vector3d odir(-ldir[1], ldir[0], 0);
    Eigen::Vector3d bottom_quad[4];
    double half_l = length / 2;
    double half_w = width / 2;
    // A(-half_l, -half_w)
    bottom_quad[0] = center_vector + ldir * -half_l + odir * -half_w;
    // B(-half_l, half_w)
    bottom_quad[1] = center_vector + ldir * -half_l + odir * half_w;
    // C(half_l, half_w)
    bottom_quad[2] = center_vector + ldir * half_l + odir * half_w;
    // D(half_l, -half_w)
    bottom_quad[3] = center_vector + ldir * half_l + odir * -half_w;

    int in_num = 0;
    std::vector<geometry_msgs::Point> bottom_quad_vector(4);
    for (unsigned int j = 0; j < bottom_quad_vector.size(); j++)
    {
      bottom_quad_vector[j].x = bottom_quad[j](0);
      bottom_quad_vector[j].y = bottom_quad[j](1);
      bottom_quad_vector[j].z = bottom_quad[j](2);
      bottom_quad_vector[j] = TransformPoint(bottom_quad_vector[j], sensor2wayarea_transform);
      if (CheckPointInGrid(current_grid, grid_wayarea_image, bottom_quad_vector[j]))
        in_num++;
    }

    bool object_in_wayarea = false;
    if (in_num >= 3)
      object_in_wayarea = true;

    if (object_in_wayarea)
    {
      in_nums++;
      in_roi_objects.detections.push_back(object);
    }
    else
    {
      out_nums++;
      out_roi_objects.detections.push_back(object);
    }
  }

  ROS_INFO("[%s] %d objects in water area, %d objects was filtered.", __APP_NAME__, in_nums, out_nums);
  roi_objects_publisher_.publish(in_roi_objects);
  publishObjectsMarkers(objects_markers_publisher_, in_detections->header, GREEN.rgbA, in_roi_objects);

  wayarea_gridmap_ = nullptr;
  object_detections_ = nullptr;
}

void RosRoiObjectFilterApp::DetectionsCallback(const vision_msgs::Detection3DArray::ConstPtr &in_detections)
{
  // ROS_INFO_STREAM("detection callback.");
  if (!processing_ && !in_detections->detections.empty())
  {
    processing_ = true;
    object_detections_ = in_detections;
    SyncedDetectionsCallback(in_detections, wayarea_gridmap_);
    processing_ = false;
  }
}

void RosRoiObjectFilterApp::WayAreaGridMapCallback(const autoware_msgs::GridMapInfo::ConstPtr &in_message)
{
  // ROS_INFO_STREAM("wayarea callback.");
  if (!processing_)
  {
    processing_ = true;
    wayarea_gridmap_ = in_message;
    processing_ = false;
  }
}

void RosRoiObjectFilterApp::InitializeRosIo(ros::NodeHandle &in_private_handle)
{
  std::string objects_topic_str, wayarea_gridmap_topic_, roi_objects_topic_str, roi_objects_markers_topic_src;
  in_private_handle.param<std::string>("wayarea_topic_src", wayarea_gridmap_topic_, "grid_map_wayarea");
  ROS_INFO("[%s] wayarea_topic_src: %s", __APP_NAME__, wayarea_gridmap_topic_.c_str());

  in_private_handle.param<std::string>("wayarea_layer_name", wayarea_layer_name_, "wayarea");
  ROS_INFO("[%s] wayarea_layer_name: %s", __APP_NAME__, wayarea_layer_name_.c_str());

  in_private_handle.param<std::string>("objects_topic_src", objects_topic_str, "/segmenter/lidar_objects");
  ROS_INFO("[%s] objects_src_topic: %s", __APP_NAME__, objects_topic_str.c_str());

  in_private_handle.param<std::string>("roi_objects_topic_src", roi_objects_topic_str, "/segmenter/objects_filtered");

  in_private_handle.param<std::string>("roi_objects_markers_topic_src", roi_objects_markers_topic_src, "/segmenter/objects_filtered_markers");

  detections_range_subscriber_ = node_handle_.subscribe(objects_topic_str, 1,
                                                        &RosRoiObjectFilterApp::DetectionsCallback, this);

  wayarea_gridmap_subscriber_ = node_handle_.subscribe(wayarea_gridmap_topic_, 1,
                                                       &RosRoiObjectFilterApp::WayAreaGridMapCallback, this);

  roi_objects_publisher_ = node_handle_.advertise<vision_msgs::Detection3DArray>(roi_objects_topic_str, 1);
  ROS_INFO("[%s] Publishing filtered objects in %s", __APP_NAME__, roi_objects_topic_str.c_str());

  objects_markers_publisher_ = node_handle_.advertise<visualization_msgs::MarkerArray>(roi_objects_markers_topic_src, 1);
}

void RosRoiObjectFilterApp::Run()
{
  ros::NodeHandle private_node_handle("~");

  tf::TransformListener transform_listener;
  transform_listener_ = &transform_listener;

  InitializeRosIo(private_node_handle);

  ROS_INFO("[%s] Ready. Waiting for data...", __APP_NAME__);

  ros::spin();

  ROS_INFO("[%s] END", __APP_NAME__);
}

RosRoiObjectFilterApp::RosRoiObjectFilterApp()
{
  processing_ = false;
}
