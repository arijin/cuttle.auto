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
 ********************
 *  v1.0: amc-nu (abrahammonrroy@yahoo.com)
 *
 * roi_object_filter.h
 *
 *  Created on: October, 23rd, 2018
 */

#ifndef PROJECT_ROI_OBJECT_FILTER_H
#define PROJECT_ROI_OBJECT_FILTER_H

#define __APP_NAME__ "roi_object_filter"

#include <string>
#include <vector>

#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>

#include <geometry_msgs/Point.h>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_msgs/GridMap.h>
#include <grid_map_cv/grid_map_cv.hpp>

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/core/version.hpp>

#include <Eigen/Core>
#include <Eigen/Geometry>

#include <yaml-cpp/yaml.h>

#include <autoware_msgs/GridMapInfo.h>
#include <vision_msgs/Detection3DArray.h>   // vision_msgs::Detection3DArray
#include <visualization_msgs/MarkerArray.h> // visualization_msgs::MarkerArray

struct Color
{
  Color(float r, float g, float b)
  {
    rgbA.r = r;
    rgbA.g = g;
    rgbA.b = b;
    rgbA.a = 1.0;
  }

  std_msgs::ColorRGBA rgbA;
};

const struct Color BLACK(0.0, 0.0, 0.0);
const struct Color WHITE(1.0, 1.0, 1.0);
const struct Color RED(1.0, 0.0, 0.0);
const struct Color DARKRED(0.5, 0.0, 0.0);
const struct Color GREEN(0.0, 1.0, 0.0);
const struct Color DARKGREEN(0.0, 0.5, 0.0);
const struct Color BLUE(0.0, 0.0, 1.0);
const struct Color DARKBLUE(0.0, 0.0, 0.5);
const struct Color MAGENTA(1.0, 0.0, 1.0);
const struct Color DARKMAGENTA(0.5, 0.0, 0.5);
const struct Color CYAN(0.0, 1.0, 1.0);
const struct Color DARKCYAN(0.0, 0.5, 0.5);
const struct Color YELLOW(1.0, 1.0, 0.0);
const struct Color BROWN(0.5, 0.5, 0.0);

class RosRoiObjectFilterApp
{
  ros::NodeHandle node_handle_;
  friend class RoiFilterTestClass;

  ros::Subscriber detections_range_subscriber_, wayarea_gridmap_subscriber_;
  ros::Publisher roi_objects_publisher_, objects_markers_publisher_;
  std::string wayarea_layer_name_;
  tf::TransformListener *transform_listener_;

  bool processing_;

  autoware_msgs::GridMapInfo::ConstPtr wayarea_gridmap_;
  vision_msgs::Detection3DArray::ConstPtr object_detections_;

  const int GRID_MAX_VALUE = 255;
  const int GRID_MIN_VALUE = 0;
  const int GRID_OCCUPANCY_ROAD = 128;

  tf::StampedTransform FindTransform(const std::string &in_target_frame, const std::string &in_source_frame);

  geometry_msgs::Point TransformPoint(const geometry_msgs::Point &in_point, const tf::Transform &in_tf);

  bool CheckPointInGrid(const grid_map::GridMap &in_grid_map, const cv::Mat &in_grid_image,
                        const geometry_msgs::Point &in_point);

  void SyncedDetectionsCallback(const vision_msgs::Detection3DArray::ConstPtr &in_detections,
                                const autoware_msgs::GridMapInfo::ConstPtr &in_gridmap);

  void DetectionsCallback(const vision_msgs::Detection3DArray::ConstPtr &in_detections);

  void WayAreaGridMapCallback(const autoware_msgs::GridMapInfo::ConstPtr &in_message);

  void InitializeRosIo(ros::NodeHandle &in_private_handle);

public:
  void Run();

  RosRoiObjectFilterApp();
};

#endif //PROJECT_ROI_OBJECT_FILTER_H
