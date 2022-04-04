#!/usr/bin/env python3

import rospy
import rosbag
import sys
import os
from collections import deque
import cv2
import numpy as np
import compy as cp
import geopy as gp
import bag_label as bl
# message
from std_msgs.msg import Header
from gazebo_msgs.msg import ModelState
from gazebo_msgs.srv import SetModelState, GetModelState
from geometry_msgs.msg import Point
from geometry_msgs.msg import PoseStamped
from cv_bridge import CvBridge
from water_msgs.msg import ShipState
from water_msgs.msg import gpsPacket
# sensor data message
from sensor_msgs.msg import Imu
from sensor_msgs.msg import Image, CameraInfo
from sensor_msgs.msg import PointCloud2, PointCloud
from sensor_msgs import point_cloud2

basedir = os.path.abspath(os.path.dirname(__file__))
# root
ROOT_DIR = '/home/arijin'
root_dir = os.path.join(ROOT_DIR, 'dataset/inWater/object')
seq_root_dir = os.path.join(ROOT_DIR, 'dataset/inWater/sequences')
# split
split = "training"  # or "testing"
split_dir = os.path.join(root_dir, split)
# raw
raw_dir = os.path.join(ROOT_DIR, 'dataset/inWater/raw')
# seq
seq = "00"
seq_dir = os.path.join(seq_root_dir, seq)


world_latitude = 31.5141625396
world_longitude = 121.132606168


def GenerateGPSPoseMsg(gps_msg):
    pose_msg = PoseStamped()
    pose_msg.header = gps_msg.header
    pose_msg.pose = gps_msg.pose  # Pose()
    pose_x, pose_y = gp.toXYCoordinate(world_latitude, world_longitude,
                                       gps_msg.SatCoordinate.latitude, gps_msg.SatCoordinate.longitude)
    pose_msg.pose.position.x = pose_x
    pose_msg.pose.position.y = pose_y
    pose_msg.pose.position.z = 0
    return pose_msg


def write_dataset(bag_name, output_bag_name):
    index = 0
    gps_pose_msg_ram = deque()
    camera_msg_ram = deque()
    velodyne_msg_ram = deque()
    # topic:就是发布的topic msg:该topic在当前时间点下的message t:消息记录时间(非header)
    # read_messages内可以指定的某个topic
    with rosbag.Bag(os.path.join(raw_dir, output_bag_name), 'w') as outbag:
        for topic, msg, t in rosbag.Bag(os.path.join(raw_dir, bag_name)).read_messages():
            if topic == '/gps_data_rectified':
                gps_pose_msg_ram.append(msg)
            elif topic == '/usb_cam/image_raw':
                camera_msg_ram.append(msg)
            elif topic == '/rslidar_points':
                velodyne_msg_ram.append(msg)
            # get data
            while len(gps_pose_msg_ram) > 0 and len(camera_msg_ram) > 0 and len(velodyne_msg_ram) > 0:
                gps_pose_ts = gps_pose_msg_ram[0].header.stamp.to_sec()
                camera_ts = camera_msg_ram[0].header.stamp.to_sec()
                velodyne_ts = velodyne_msg_ram[0].header.stamp.to_sec()
                if abs(gps_pose_ts - camera_ts) < 0.1 and abs(gps_pose_ts - velodyne_ts) < 0.1 and abs(velodyne_ts - camera_ts) < 0.1:
                    if index % 2 == 0:
                        # Lidar
                        velodyne_msg_ram[0].header.frame_id = "velo_link"
                        outbag.write(
                            "/kitti/velo/pointcloud", velodyne_msg_ram[0], velodyne_msg_ram[0].header.stamp)
                        # Camera
                        outbag.write(
                            "/usb_cam/image_raw", camera_msg_ram[0], camera_msg_ram[0].header.stamp)
                        # IMU
                        imu_msg = Imu()
                        imu_msg.orientation = gps_pose_msg_ram[0].pose.orientation
                        imu_msg.header.frame_id = "imu_link"
                        imu_msg.header.stamp = gps_pose_msg_ram[0].header.stamp
                        outbag.write("/kitti/oxts/imu", imu_msg,
                                     imu_msg.header.stamp)
                        # NavSat/GPS
                        nav_sat_msg = gps_pose_msg_ram[0].SatCoordinate
                        nav_sat_msg.header.frame_id = "imu_link"
                        nav_sat_msg.header.stamp = gps_pose_msg_ram[0].header.stamp
                        outbag.write("/kitti/oxts/gps/fix",
                                     nav_sat_msg, nav_sat_msg.header.stamp)

                    index += 1
                    velodyne_msg_ram.popleft()
                    camera_msg_ram.popleft()
                    gps_pose_msg_ram.popleft()
                else:
                    front_msg = np.argmin(
                        [velodyne_ts, camera_ts, gps_pose_ts])
                    if front_msg == 0:
                        velodyne_msg_ram.popleft()
                    elif front_msg == 1:
                        camera_msg_ram.popleft()
                    elif front_msg == 2:
                        gps_pose_msg_ram.popleft()


if __name__ == '__main__':
    bag_name = '2021-07-06-15-28-42.bag'
    otuput_bag_name = 'kitti_2021-07-06-15-28-42.bag'
    write_dataset(bag_name, otuput_bag_name)
