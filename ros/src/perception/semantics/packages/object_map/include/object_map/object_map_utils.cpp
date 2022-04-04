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
 *
 */

#include "object_map/object_map_utils.hpp"

namespace object_map
{
	geometry_msgs::Point TransformPoint(const geometry_msgs::Point &in_point, const tf::Transform &in_tf)
	{
		tf::Point tf_point;
		tf::pointMsgToTF(in_point, tf_point);

		tf_point = in_tf * tf_point;

		geometry_msgs::Point out_point;
		tf::pointTFToMsg(tf_point, out_point);

		return out_point;
	}

	void PublishGridMap(const grid_map::GridMap &in_gridmap, const ros::Publisher &in_publisher)
	{
		grid_map_msgs::GridMap message;
		grid_map::GridMapRosConverter::toMessage(in_gridmap, message);
		in_publisher.publish(message);
	}

	void PublishGridMapMsg(const grid_map::GridMap &in_gridmap, const ros::Publisher &in_publisher, const std::string &frame_id, tf::Transform &in_tf)
	{
		grid_map_msgs::GridMap map_message;
		grid_map::GridMapRosConverter::toMessage(in_gridmap, map_message);

		autoware_msgs::GridMapInfo gridmapinfo_message;
		gridmapinfo_message.header.stamp = ros::Time::now();
		gridmapinfo_message.header.frame_id = frame_id;
		gridmapinfo_message.map = map_message;
		gridmapinfo_message.trans.translation.x = in_tf.getOrigin().x();
		gridmapinfo_message.trans.translation.y = in_tf.getOrigin().y();
		gridmapinfo_message.trans.translation.z = in_tf.getOrigin().z();
		gridmapinfo_message.trans.rotation.x = in_tf.getRotation().x();
		gridmapinfo_message.trans.rotation.y = in_tf.getRotation().y();
		gridmapinfo_message.trans.rotation.z = in_tf.getRotation().z();
		gridmapinfo_message.trans.rotation.w = in_tf.getRotation().w();
		in_publisher.publish(gridmapinfo_message);
	}

	void PublishOccupancyGrid(const grid_map::GridMap &in_gridmap,
							  const ros::Publisher &in_publisher,
							  const std::string &in_layer,
							  double in_min_value,
							  double in_max_value,
							  double in_height)
	{
		nav_msgs::OccupancyGrid message;
		grid_map::GridMapRosConverter::toOccupancyGrid(in_gridmap, in_layer, in_min_value, in_max_value, message);
		message.info.origin.position.z = in_height;
		in_publisher.publish(message);
	}

	tf::StampedTransform FindTransform(const std::string &in_target_frame, const std::string &in_source_frame,
									   const tf::TransformListener &in_tf_listener)
	{
		tf::StampedTransform transform;

		try
		{
			in_tf_listener.lookupTransform(in_target_frame, in_source_frame, ros::Time(0), transform);
		}
		catch (tf::TransformException ex)
		{
			ROS_ERROR("%s", ex.what());
		}

		return transform;
	}

	std::vector<geometry_msgs::Point>
	SearchAreaPoints(const vector_map::Area &in_area, const vector_map::VectorMap &in_vectormap)
	{
		std::vector<geometry_msgs::Point> area_points;
		std::vector<geometry_msgs::Point> area_points_empty;

		if (in_area.aid == 0)
			return area_points_empty;

		vector_map_msgs::Line line = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Line>(in_area.slid));
		// must set beginning line
		if (line.lid == 0 || line.blid != 0)
			return area_points_empty;

		// Search all lines in in_area
		while (line.flid != 0)
		{
			vector_map_msgs::Point bp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.bpid));
			if (bp.pid == 0)
				return area_points_empty;

			vector_map_msgs::Point fp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.fpid));
			if (fp.pid == 0)
				return area_points_empty;

			// 2 points of line
			area_points.push_back(vector_map::convertPointToGeomPoint(bp));
			area_points.push_back(vector_map::convertPointToGeomPoint(fp));

			line = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Line>(line.flid));
			if (line.lid == 0)
				return area_points_empty;
		}

		vector_map_msgs::Point bp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.bpid));
		vector_map_msgs::Point fp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.fpid));
		if (bp.pid == 0 || fp.pid == 0)
			return area_points_empty;

		area_points.push_back(vector_map::convertPointToGeomPoint(bp));
		area_points.push_back(vector_map::convertPointToGeomPoint(fp));

		return area_points;
	}

	std::vector<geometry_msgs::Point>
	SearchLinePoints(const vector_map::Line &in_line, const vector_map::VectorMap &in_vectormap, const int end_id)
	{
		std::vector<geometry_msgs::Point> line_points;
		std::vector<geometry_msgs::Point> line_points_empty;

		vector_map_msgs::Line line = in_line;
		// must set beginning line
		if (line.lid == 0)
			return line_points_empty;

		// Search all lines in linked in_line
		while (line.flid != 0 && line.lid != end_id)
		{
			vector_map_msgs::Point bp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.bpid));
			if (bp.pid == 0)
				return line_points_empty;

			vector_map_msgs::Point fp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.fpid));
			if (fp.pid == 0)
				return line_points_empty;

			// 2 points of line
			line_points.push_back(vector_map::convertPointToGeomPoint(bp));
			line_points.push_back(vector_map::convertPointToGeomPoint(fp));

			line = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Line>(line.flid));
			if (line.lid == 0)
				return line_points_empty;
		}

		vector_map_msgs::Point bp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.bpid));
		vector_map_msgs::Point fp = in_vectormap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.fpid));
		if (bp.pid == 0 || fp.pid == 0)
			return line_points_empty;

		line_points.push_back(vector_map::convertPointToGeomPoint(bp));
		line_points.push_back(vector_map::convertPointToGeomPoint(fp));

		return line_points;
	}

	void FillPolygonAreas(grid_map::GridMap &out_grid_map, const std::vector<std::vector<geometry_msgs::Point>> &in_area_points,
						  const std::string &in_grid_layer_name, const int in_layer_background_value,
						  const int in_layer_min_value, const int in_fill_color, const int in_layer_max_value,
						  const std::string &in_tf_target_frame, const std::string &in_tf_source_frame,
						  const tf::TransformListener &in_tf_listener) // 255 128 0 255
	{
		// std::cout << in_layer_background_value << " " << in_layer_min_value << " " << in_fill_color << " " << in_layer_max_value << std::endl;
		if (!out_grid_map.exists(in_grid_layer_name))
		{
			out_grid_map.add(in_grid_layer_name);
		}
		out_grid_map[in_grid_layer_name].setConstant(in_layer_background_value);

		cv::Mat original_image;
		grid_map::GridMapCvConverter::toImage<unsigned char, 1>(out_grid_map,
																in_grid_layer_name,
																CV_8UC1,
																in_layer_min_value,
																in_layer_max_value,
																original_image);

		cv::Mat filled_image = original_image.clone();

		// sensor_frame_, map_frame_
		tf::StampedTransform tf = FindTransform(in_tf_target_frame, in_tf_source_frame, in_tf_listener);

		// calculate out_grid_map position
		grid_map::Position map_pos = out_grid_map.getPosition();
		double origin_x_offset = out_grid_map.getLength().x() / 2.0 - map_pos.x();
		double origin_y_offset = out_grid_map.getLength().y() / 2.0 - map_pos.y();

		// passed area
		for (const auto &points : in_area_points)
		{
			std::vector<cv::Point> cv_points;

			for (const auto &p : points)
			{
				// transform to GridMap coordinate
				geometry_msgs::Point tf_point = TransformPoint(p, tf);

				// coordinate conversion for cv image
				double cv_x = (out_grid_map.getLength().y() - origin_y_offset - tf_point.y) / out_grid_map.getResolution();
				double cv_y = (out_grid_map.getLength().x() - origin_x_offset - tf_point.x) / out_grid_map.getResolution();
				cv_points.emplace_back(cv::Point(cv_x, cv_y));
			}

			cv::fillConvexPoly(filled_image, cv_points.data(), cv_points.size(), cv::Scalar(in_fill_color));
		}

		// convert to ROS msg
		grid_map::GridMapCvConverter::addLayerFromImage<unsigned char, 1>(filled_image,
																		  in_grid_layer_name,
																		  out_grid_map,
																		  in_layer_min_value,
																		  in_layer_max_value);
	}

	void FillPolygonRiverAreas(grid_map::GridMap &out_grid_map, const std::vector<std::vector<geometry_msgs::Point>> &in_area_points,
							   const std::vector<std::vector<geometry_msgs::Point>> &in_unpassed_area_points,
							   const std::string &in_grid_layer_name, const int in_layer_background_value,
							   const int in_layer_min_value, const int in_fill_color, const int in_layer_max_value,
							   const std::string &in_tf_target_frame, const std::string &in_tf_source_frame,
							   const tf::TransformListener &in_tf_listener, tf::StampedTransform &transform)
	{
		// std::cout << in_layer_background_value << " " << in_layer_min_value << " " << in_fill_color << " " << in_layer_max_value << std::endl;
		if (!out_grid_map.exists(in_grid_layer_name))
		{
			out_grid_map.add(in_grid_layer_name);
		}
		out_grid_map[in_grid_layer_name].setConstant(in_layer_background_value);

		cv::Mat original_image;
		grid_map::GridMapCvConverter::toImage<unsigned char, 1>(out_grid_map,
																in_grid_layer_name,
																CV_8UC1,
																in_layer_min_value,
																in_layer_max_value,
																original_image);

		cv::Mat filled_image = original_image.clone();

		// sensor_frame_, map_frame_
		tf::StampedTransform tf = FindTransform(in_tf_target_frame, in_tf_source_frame, in_tf_listener);
		transform = FindTransform(in_tf_source_frame, in_tf_target_frame, in_tf_listener);

		// calculate out_grid_map position
		grid_map::Position map_pos = out_grid_map.getPosition();
		double origin_x_offset = out_grid_map.getLength().x() / 2.0 - map_pos.x();
		double origin_y_offset = out_grid_map.getLength().y() / 2.0 - map_pos.y();

		// passed area
		for (const auto &points : in_area_points)
		{
			std::vector<cv::Point> cv_points;

			for (const auto &p : points)
			{
				// transform to GridMap coordinate
				geometry_msgs::Point tf_point = TransformPoint(p, tf);

				// coordinate conversion for cv image
				double cv_x = (out_grid_map.getLength().y() - origin_y_offset - tf_point.y) / out_grid_map.getResolution();
				double cv_y = (out_grid_map.getLength().x() - origin_x_offset - tf_point.x) / out_grid_map.getResolution();
				cv_points.emplace_back(cv::Point(cv_x, cv_y));
			}

			cv::fillConvexPoly(filled_image, cv_points.data(), cv_points.size(), cv::Scalar(in_fill_color));
		}

		// unpassed area
		for (const auto &points : in_unpassed_area_points)
		{
			std::vector<cv::Point> cv_points;

			for (const auto &p : points)
			{
				// transform to GridMap coordinate
				geometry_msgs::Point tf_point = TransformPoint(p, tf);

				// coordinate conversion for cv image
				double cv_x = (out_grid_map.getLength().y() - origin_y_offset - tf_point.y) / out_grid_map.getResolution();
				double cv_y = (out_grid_map.getLength().x() - origin_x_offset - tf_point.x) / out_grid_map.getResolution();
				cv_points.emplace_back(cv::Point(cv_x, cv_y));
			}

			cv::fillConvexPoly(filled_image, cv_points.data(), cv_points.size(), cv::Scalar(in_layer_background_value));
		}

		// convert to ROS msg
		grid_map::GridMapCvConverter::addLayerFromImage<unsigned char, 1>(filled_image,
																		  in_grid_layer_name,
																		  out_grid_map,
																		  in_layer_min_value,
																		  in_layer_max_value);
	}

	void LoadRoadAreasFromVectorMap(ros::NodeHandle &in_private_node_handle,
									std::vector<std::vector<geometry_msgs::Point>> &out_area_points)
	{
		vector_map::VectorMap vmap;
		vmap.subscribe(in_private_node_handle,
					   vector_map::Category::POINT | vector_map::Category::LINE | vector_map::Category::AREA |
						   vector_map::Category::WAY_AREA,
					   10);

		std::vector<vector_map_msgs::WayArea> way_areas =
			vmap.findByFilter([](const vector_map_msgs::WayArea &way_area) {
				return true;
			});

		if (way_areas.empty())
		{
			ROS_WARN_STREAM("No WayArea...");
			return;
		}

		for (const auto &way_area : way_areas)
		{
			vector_map_msgs::Area area = vmap.findByKey(vector_map::Key<vector_map::Area>(way_area.aid));
			out_area_points.emplace_back(SearchAreaPoints(area, vmap));
		}
	}

	void LoadWharfAreasFromVectorMap(ros::NodeHandle &in_private_node_handle,
									 std::vector<std::vector<geometry_msgs::Point>> &out_area_points)
	{
		vector_map::VectorMap vmap;
		vmap.subscribe(in_private_node_handle,
					   vector_map::Category::POINT | vector_map::Category::LINE | vector_map::Category::AREA |
						   vector_map::Category::CROSS_WALK,
					   10);

		std::vector<vector_map_msgs::CrossWalk> way_areas =
			vmap.findByFilter([](const vector_map_msgs::CrossWalk &way_area) {
				return true;
			});

		if (way_areas.empty())
		{
			ROS_WARN_STREAM("No Wharf WayArea...");
			return;
		}

		for (const auto &way_area : way_areas)
		{
			vector_map_msgs::Area area = vmap.findByKey(vector_map::Key<vector_map::Area>(way_area.aid));
			out_area_points.emplace_back(SearchAreaPoints(area, vmap));
		}
	}

	void LoadWaterAreasFromVectorMap(ros::NodeHandle &in_private_node_handle,
									 std::vector<std::vector<geometry_msgs::Point>> &out_area_points)
	{
		vector_map::VectorMap vmap;
		vmap.subscribe(in_private_node_handle,
					   vector_map::Category::POINT | vector_map::Category::LINE |
						   vector_map::Category::WATER_AREA,
					   10);

		std::vector<vector_map_msgs::WaterArea> area_edges =
			vmap.findByFilter([](const vector_map_msgs::WaterArea &area_edge) {
				return true;
			});

		if (area_edges.empty())
		{
			ROS_WARN_STREAM("No AreaEdge...");
			return;
		}

		// line passed range
		for (auto it = area_edges.begin(); it != area_edges.end(); it++)
		{
			std::vector<geometry_msgs::Point> area_points;
			vector_map_msgs::WaterArea area_edge_first = *it;
			vector_map_msgs::WaterArea area_edge_second = area_edges[(*it).connectid - 1];

			vector_map_msgs::Line line = vmap.findByKey(vector_map::Key<vector_map::Line>(area_edge_first.slid));
			std::vector<geometry_msgs::Point> line_points = SearchLinePoints(line, vmap, area_edge_second.elid);
			area_points.insert(area_points.end(), line_points.begin(), line_points.end());

			line = vmap.findByKey(vector_map::Key<vector_map::Line>(area_edge_second.slid));
			line_points = SearchLinePoints(line, vmap, area_edge_first.elid);
			area_points.insert(area_points.end(), line_points.begin(), line_points.end());

			out_area_points.emplace_back(area_points);
		}
		// intersection range
		int count = 0;
		int current_kid = 0;
		for (auto it = area_edges.begin(); it != area_edges.end(); it++)
		{
			if ((*it).kid != current_kid)
			{
				if (count > 2)
				{
					std::vector<geometry_msgs::Point> area_points;
					for (int i = 1; i < (count + 1); i++)
					{
						vector_map_msgs::WaterArea area_edge = *(it - i);
						vector_map_msgs::Line line = vmap.findByKey(vector_map::Key<vector_map::Line>(area_edge.slid));
						vector_map_msgs::Point bp = vmap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.bpid));
						area_points.push_back(vector_map::convertPointToGeomPoint(bp));
					}
					out_area_points.emplace_back(area_points);
				}
				count = 1;
				current_kid = (*it).kid;
			}
			else
			{
				count++;
			}
		}
		if (count > 2)
		{
			std::vector<geometry_msgs::Point> area_points;
			auto it = area_edges.end();
			for (int i = 1; i < (count + 1); i++)
			{
				vector_map_msgs::WaterArea area_edge = *(it - i);
				vector_map_msgs::Line line = vmap.findByKey(vector_map::Key<vector_map::Line>(area_edge.slid));
				vector_map_msgs::Point bp = vmap.findByKey(vector_map::Key<vector_map_msgs::Point>(line.bpid));
				area_points.push_back(vector_map::convertPointToGeomPoint(bp));
			}
			out_area_points.emplace_back(area_points);
		}
	}

} // namespace object_map
