/*
 * Copyright (C) 2019 by AutoSense Organization. All rights reserved.
 * Gary Chan <chenshj35@mail2.sysu.edu.cn>
 */
#include "segmenters/scan_line_run_segmenter.hpp"

#include <pcl/filters/extract_indices.h>  // pcl::ExtractIndices
#include <ros/ros.h>

#include "common/time.hpp"  // common::Clock

namespace autosense {
namespace segmenter {

ScanLineRunSegmenter::ScanLineRunSegmenter() {}

ScanLineRunSegmenter::ScanLineRunSegmenter(const SegmenterParams &params)
    : params_(params) {}

ScanLineRunSegmenter::~ScanLineRunSegmenter() {}

void ScanLineRunSegmenter::segment(
    const PointICloud &cloud_in, std::vector<PointICloudPtr> &cloud_clusters) {
    if (cloud_in.empty()) {
        ROS_WARN_STREAM("Empty non-ground for segmentation, do nonthing.");
        return;
    }

    if (!cloud_in.isOrganized()) {
        ROS_WARN_STREAM(
            "Cloud is not organized. Can't process the scan-line run "
            "segmenter.");
        return;
    }

    // Clear segments.
    cloud_clusters.clear();

    common::Clock clock;
    ROS_INFO("Starting Euclidean segmentation.");

    PointICloudPtr cloud(new PointICloud);
    *cloud = cloud_in;

    std::vector<pcl::PointIndices> cluster_indices;

    // // extract clusters
    // euclidean_cluster_extractor_.setInputCloud(cloud);
    // euclidean_cluster_extractor_.extract(cluster_indices);

    // if (cluster_indices.size() > 0) {
    //     for (size_t cluster_idx = 0u; cluster_idx < cluster_indices.size();
    //          ++cluster_idx) {
    //         PointICloudPtr cluster_cloud(new PointICloud);
    //         pcl::copyPointCloud(*cloud, cluster_indices[cluster_idx],
    //                             *cluster_cloud);
    //         cloud_clusters.push_back(cluster_cloud);
    //     }
    // }

    ROS_INFO_STREAM("Segmentation complete. Took " << clock.takeRealTime()
                                                   << "ms.");
}

}  // namespace segmenter
}  // namespace autosense
