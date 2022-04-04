/*
 * Copyright 2018-2019 Autoware Foundation. All rights reserved.
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
 * road_occupancy_processor.cpp
 *
 *  Created on: Jan 29, 2018
 */

#include "road_occupancy_processor/road_occupancy_processor.h"

void ROSRoadOccupancyProcessorApp::PublishGridMap(grid_map::GridMap &in_grid_map, const std::string &in_layer_publish)
{
	if (in_grid_map.exists(in_layer_publish))
	{
		grid_map_msgs::GridMap ros_gridmap_message;
		nav_msgs::OccupancyGrid ros_occupancygrid_message;
		grid_map::GridMapRosConverter::toMessage(in_grid_map, ros_gridmap_message);
		grid_map::GridMapRosConverter::toOccupancyGrid(in_grid_map,
													   in_layer_publish,
													   grid_min_value_,
													   grid_max_value_,
													   ros_occupancygrid_message);
		publisher_grid_map_.publish(ros_gridmap_message);			  // 加了一个图层
		publisher_occupancy_grid_.publish(ros_occupancygrid_message); // 应该只publish了占有图
	}
	else
	{
		ROS_INFO("[%s] Empty GridMap. It might still be loading or it does not contain valid data.", __APP_NAME__);
	}
}

bool ROSRoadOccupancyProcessorApp::LoadRoadLayerFromMat(grid_map::GridMap &in_grid_map, cv::Mat &in_grid_image)
{
	if (!in_grid_image.empty())
	{
		grid_map::GridMapCvConverter::addLayerFromImage<unsigned char, 1>(in_grid_image,
																		  output_layer_name_,
																		  in_grid_map,
																		  grid_min_value_,
																		  grid_max_value_); // "road_status" layer

		return true;
	}

	ROS_INFO("[%s] Empty Image received.", __APP_NAME__);
	return false;
}

void ROSRoadOccupancyProcessorApp::Convert3dPointToOccupancy(grid_map::GridMap &in_grid_map,
															 const geometry_msgs::Point &in_point, cv::Point &out_point)
{
	// calculate position
	grid_map::Position map_pos = in_grid_map.getPosition();
	double origin_x_offset = in_grid_map.getLength().x() / 2.0 - map_pos.x();
	double origin_y_offset = in_grid_map.getLength().y() / 2.0 - map_pos.y();
	// coordinate conversion for cv image
	out_point.x = (in_grid_map.getLength().y() - origin_y_offset - in_point.y) / in_grid_map.getResolution();
	out_point.y = (in_grid_map.getLength().x() - origin_x_offset - in_point.x) / in_grid_map.getResolution();
}

void ROSRoadOccupancyProcessorApp::SetPointInGridMap(grid_map::GridMap &in_grid_map, cv::Mat &in_grid_image,
													 const geometry_msgs::Point &in_point, uchar in_value)
{
	// calculate position
	cv::Point cv_point;
	Convert3dPointToOccupancy(in_grid_map, in_point, cv_point);

	cv::Rect rect(cv::Point(), in_grid_image.size());

	if (!rect.contains(cv_point))
		return;

	if (in_grid_image.at<uchar>(cv_point.y, cv_point.x) != OCCUPANCY_NO_ROAD)
	{
		const int radius = 2;
		const int fill = -1;
		cv::circle(in_grid_image, cv::Point(cv_point.x, cv_point.y), radius, cv::Scalar(in_value), fill);
	}
}

void ROSRoadOccupancyProcessorApp::ConvertPointCloud(const pcl::PointCloud<pcl::PointXYZI> &in_pointcloud,
													 const std::string &in_targetframe,
													 pcl::PointCloud<pcl::PointXYZI> &out_pointcloud)
{
	//check that both pointcloud and grid are in the same frame, otherwise transform
	tf::StampedTransform map2sensor_transform;
	while (true)
	{
		map2sensor_transform = FindTransform("/map", in_pointcloud.header.frame_id);
		if (abs(in_pointcloud.header.stamp / 1000000.0 - map2sensor_transform.stamp_.toSec()) < 0.1)
			break;
	}

	// ROS_INFO_STREAM("cloud time: " << std::fixed << std::setprecision(5) << in_pointcloud.header.stamp / 1000000.0 << ", "
	// 							   << "tf time:" << std::fixed << std::setprecision(5) << map2sensor_transform.stamp_.toSec());
	pcl::PointCloud<pcl::PointXYZI> map_pointcloud;
	pcl_ros::transformPointCloud(in_pointcloud, map_pointcloud, map2sensor_transform);
	pcl_ros::transformPointCloud(map_pointcloud, out_pointcloud, transform_.inverse());
};

void ROSRoadOccupancyProcessorApp::GridMapCallback(const autoware_msgs::GridMapInfo &in_message)
{
	grid_map::GridMap input_grid;
	grid_map::GridMapRosConverter::fromMessage(in_message.map, input_grid);

	grid_map::GridMapCvConverter::toImage<unsigned char, 1>(input_grid,
															wayarea_layer_name_,
															CV_8UC1,
															grid_min_value_,
															grid_max_value_,
															road_wayarea_original_mat_);

	input_gridmap_frame_ = input_grid.getFrameId();
	input_gridmap_length_ = input_grid.getLength();
	input_gridmap_resolution_ = input_grid.getResolution();
	input_gridmap_position_ = input_grid.getPosition();

	transform_.frame_id_ = "/map";
	transform_.child_frame_id_ = sensor_frame_;
	transform_.setOrigin(tf::Vector3(in_message.trans.translation.x, in_message.trans.translation.y, in_message.trans.translation.z));
	transform_.setRotation(tf::Quaternion(in_message.trans.rotation.x, in_message.trans.rotation.y, in_message.trans.rotation.z, in_message.trans.rotation.w));
}

void ROSRoadOccupancyProcessorApp::PointsCallback(const sensor_msgs::PointCloud2::ConstPtr &in_no_ground_cloud_msg)
{

	if (road_wayarea_original_mat_.empty())
		return;

	// timer start
	// auto start = std::chrono::system_clock::now();
	pcl::PointCloud<pcl::PointXYZI>::Ptr in_no_ground_cloud(new pcl::PointCloud<pcl::PointXYZI>);
	pcl::PointCloud<pcl::PointXYZI>::Ptr final_no_ground_cloud(new pcl::PointCloud<pcl::PointXYZI>);
	pcl::fromROSMsg(*in_no_ground_cloud_msg, *in_no_ground_cloud);
	//check that both pointcloud and grid are in the same frame, otherwise transform
	ConvertPointCloud(*in_no_ground_cloud, sensor_frame_, *final_no_ground_cloud);

	cv::Mat current_road_mat = road_wayarea_original_mat_.clone();
	cv::Mat original_road_mat = current_road_mat.clone();

	grid_map::GridMap output_gridmap;
	output_gridmap.setFrameId(sensor_frame_); //  input_gridmap_frame_
	output_gridmap.setGeometry(input_gridmap_length_,
							   input_gridmap_resolution_,
							   input_gridmap_position_);

	//process obstacle points
	for (const auto &point : final_no_ground_cloud->points)
	{
		geometry_msgs::Point sensor_point;
		sensor_point.x = point.x;
		sensor_point.y = point.y;
		sensor_point.z = point.z;
		SetPointInGridMap(output_gridmap, current_road_mat, sensor_point, OCCUPANCY_ROAD_OCCUPIED);
	}

	// visualize test
	//cv::imshow("result", current_road_mat);
	//cv::waitKey(10);

	LoadRoadLayerFromMat(output_gridmap, current_road_mat);
	PublishGridMap(output_gridmap, output_layer_name_);
	tf_broadcaster_.sendTransform(transform_); // must after the OccupancyGrid msg published

	// timer end
	// auto end = std::chrono::system_clock::now();
	// auto usec = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	// std::cout << "time: " << usec / 1000.0 << " [msec]" << std::endl;
}

void ROSRoadOccupancyProcessorApp::InitializeROSIo(ros::NodeHandle &in_private_handle)
{
	//get params
	std::string points_no_ground_topic_str, wayarea_topic_str;

	in_private_handle.param<std::string>("points_no_ground_src", points_no_ground_topic_str, "points_no_ground");
	ROS_INFO("[%s] points_no_ground_src: %s", __APP_NAME__, points_no_ground_topic_str.c_str());

	in_private_handle.param<std::string>("wayarea_topic_src", wayarea_topic_str, "grid_map_wayarea");
	ROS_INFO("[%s] wayarea_topic_src: %s", __APP_NAME__, wayarea_topic_str.c_str());

	in_private_handle.param<std::string>("wayarea_layer_name", wayarea_layer_name_, "wayarea");
	ROS_INFO("[%s] wayarea_layer_name: %s", __APP_NAME__, wayarea_layer_name_.c_str());

	in_private_handle.param<std::string>("output_layer_name", output_layer_name_, "road_status");
	ROS_INFO("[%s] output_layer_name: %s", __APP_NAME__, output_layer_name_.c_str());

	in_private_handle.param<std::string>("sensor_frame", sensor_frame_, "velodyne_road_status");
	ROS_INFO("[%s] output_layer_name: %s", __APP_NAME__, sensor_frame_.c_str());
	// value definition
	in_private_handle.param<int>("road_unknown_value", OCCUPANCY_ROAD_UNKNOWN, 128);
	ROS_INFO("[%s] road_unknown_value: %d", __APP_NAME__, OCCUPANCY_ROAD_UNKNOWN);

	in_private_handle.param<int>("road_free_value", OCCUPANCY_ROAD_FREE, 75);
	ROS_INFO("[%s] road_free_value: %d", __APP_NAME__, OCCUPANCY_ROAD_FREE);

	in_private_handle.param<int>("road_occupied_value", OCCUPANCY_ROAD_OCCUPIED, 0);
	ROS_INFO("[%s] road_occupied_value: %d", __APP_NAME__, OCCUPANCY_ROAD_OCCUPIED);

	in_private_handle.param<int>("no_road_value", OCCUPANCY_NO_ROAD, 255);
	ROS_INFO("[%s] no_road_value: %d", __APP_NAME__, OCCUPANCY_NO_ROAD);

	//generate subscribers or sychronizers
	cloud_no_ground_subscriber_ = node_handle_.subscribe(points_no_ground_topic_str, 1,
														 &ROSRoadOccupancyProcessorApp::PointsCallback, this);
	ROS_INFO("[%s] Subscribing to... %s", __APP_NAME__, points_no_ground_topic_str.c_str());

	/*gridmap_subscriber_ = new message_filters::Subscriber<grid_map_msgs::GridMap>(node_handle_,
	                                                                              wayarea_topic_str, 1);
	gridmap_subscriber_->registerCallback(boost::bind(&ROSRoadOccupancyProcessorApp::PointsCallback, this));*/
	gridmap_subscriber_ = node_handle_.subscribe(wayarea_topic_str, 1,
												 &ROSRoadOccupancyProcessorApp::GridMapCallback, this);
	ROS_INFO("[%s] Subscribing to... %s", __APP_NAME__, wayarea_topic_str.c_str());

	//register publishers
	publisher_grid_map_ = node_handle_.advertise<grid_map_msgs::GridMap>("gridmap_road_status", 1);
	ROS_INFO("[%s] Publishing GridMap in gridmap_road_status", __APP_NAME__);

	publisher_occupancy_grid_ = node_handle_.advertise<nav_msgs::OccupancyGrid>("occupancy_road_status", 1);
	ROS_INFO("[%s] Publishing Occupancy grid in occupancy_road_status", __APP_NAME__);
}

tf::StampedTransform
ROSRoadOccupancyProcessorApp::FindTransform(const std::string &in_target_frame, const std::string &in_source_frame)
{
	tf::StampedTransform transform;

	try
	{
		transform_listener_->lookupTransform(in_target_frame, in_source_frame, ros::Time(0), transform);
	}
	catch (tf::TransformException ex)
	{
		ROS_ERROR("%s", ex.what());
	}
	return transform;
}

geometry_msgs::Point
ROSRoadOccupancyProcessorApp::TransformPoint(const geometry_msgs::Point &in_point, const tf::Transform &in_transform)
{
	tf::Point tf_point;
	tf::pointMsgToTF(in_point, tf_point);

	tf_point = in_transform * tf_point;

	geometry_msgs::Point geometry_point;
	tf::pointTFToMsg(tf_point, geometry_point);

	return geometry_point;
}

void ROSRoadOccupancyProcessorApp::Run()
{
	ros::NodeHandle private_node_handle("~");
	tf::TransformListener transform_listener;

	transform_listener_ = &transform_listener;

	InitializeROSIo(private_node_handle);

	ROS_INFO("[%s] Ready. Waiting for data...", __APP_NAME__);

	ros::spin();

	ROS_INFO("[%s] END", __APP_NAME__);
}

ROSRoadOccupancyProcessorApp::ROSRoadOccupancyProcessorApp()
{
}