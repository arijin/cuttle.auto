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


def write_image(index, ros_image, camera_number):
    image_dir = os.path.join(seq_dir, f'image_{camera_number}')
    if not os.path.exists(image_dir):
        os.makedirs(image_dir)
    image_filename = os.path.join(image_dir, '%06d.png' % (index))

    rgb_image = CvBridge().imgmsg_to_cv2(ros_image, desired_encoding="bgr8")
    cv2.imwrite(image_filename, rgb_image)


def write_velodyne(index, ros_velodyne):
    velodyne_dir = os.path.join(seq_dir, 'velodyne')
    if not os.path.exists(velodyne_dir):
        os.makedirs(velodyne_dir)
    velodyne_filename = os.path.join(velodyne_dir, '%06d.bin' % (index))

    vely_pc = list(point_cloud2.read_points(
        ros_velodyne, field_names=("x", "y", "z"), skip_nans=True))
    vely_pc = np.array(vely_pc)
    # to 4 dims
    vely_pc = np.hstack([vely_pc, np.ones((vely_pc.shape[0], 1))])
    # print(velodyne_filename, ", velodyne pointcloud size: ", vely_pc.shape)
    # vely_pc = vely_pc[:, :3]
    vely_pc = vely_pc.astype(np.float32)  # 设置数据类型，与KITTI保持一致
    vely_pc.tofile(velodyne_filename)  # 保存成bin文件时注意数据格式


initial_pose_msg = None
initial_time = None


def write_poses_times(index, gps_pose_msg):
    '''pose format per line row: 
        a b c d e f g h i j k l
        from a flattened 4x4 homogeneous pose matrix
        a b c d
        e f g h
        i j k l
        0 0 0 1
    '''
    poses_file = os.path.join(seq_dir, 'poses.txt')
    times_file = os.path.join(seq_dir, 'times.txt')

    if index == 0:
        global initial_pose_msg
        initial_pose_msg = gps_pose_msg
        gps_pose_label = get_pose_label(gps_pose_msg, initial_pose_msg)
        with open(poses_file, 'w') as f:
            f.write(gps_pose_label)
        # time
        global initial_time
        initial_time = gps_pose_msg.header.stamp.to_sec()
        with open(times_file, 'w') as f:
            current_time = gps_pose_msg.header.stamp.to_sec() - initial_time
            f.write(f"{current_time:f}\n")
    else:
        gps_pose_label = get_pose_label(gps_pose_msg, initial_pose_msg)
        with open(poses_file, 'a') as f:
            f.write(gps_pose_label)
        # time
        with open(times_file, 'a') as f:
            current_time = gps_pose_msg.header.stamp.to_sec() - initial_time
            f.write(f"{current_time:f}\n")


def get_pose_label(pose_msg, initial_pose_msg):
    m2wTrans = gp.ros2Trans(pose_msg)
    i2wTrans = gp.ros2Trans(initial_pose_msg)
    m2iTrans = np.dot(gp.inverse_rigid_trans(i2wTrans), m2wTrans)

    pose_label = f"{m2iTrans[0, 0]:f} {m2iTrans[0, 1]:f} {m2iTrans[0, 2]:f} {m2iTrans[0, 3]:f}" \
        + f" {m2iTrans[1, 0]:f} {m2iTrans[1, 1]:f} {m2iTrans[1, 2]:f} {m2iTrans[1, 3]:f}" \
        + f" {m2iTrans[2, 0]:f} {m2iTrans[2, 1]:f} {m2iTrans[2, 2]:f} {m2iTrans[2, 3]:f}\n"
    return pose_label


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


def write_dataset(bag_name):
    index = 0
    gps_pose_msg_ram = deque()
    camera_msg_ram = deque()
    velodyne_msg_ram = deque()
    # topic:就是发布的topic msg:该topic在当前时间点下的message t:消息记录时间(非header)
    # read_messages内可以指定的某个topic
    for topic, msg, t in rosbag.Bag(os.path.join(raw_dir, bag_name)).read_messages():
        if topic == '/gps_data_rectified':
            # gps_pose_timestamp = msg.header.stamp.to_sec()
            # print(f"t:{t}, gps_time:{gps_pose_timestamp}")
            gps_pose_msg = GenerateGPSPoseMsg(msg)
            gps_pose_msg_ram.append(gps_pose_msg)
        elif topic == '/usb_cam/image_raw':
            # camera_timestamp = msg.header.stamp.to_sec()
            # print(f"t:{t}, cam_time:{camera_timestamp}")
            camera_msg_ram.append(msg)
        elif topic == '/rslidar_points':
            # velodyne_timestamp = msg.header.stamp.to_sec()
            # print(f"t:{t}, velo_time:{velodyne_timestamp}")
            velodyne_msg_ram.append(msg)
        # print(
        #     f"{len(gps_pose_msg_ram)}, {len(camera_msg_ram)}, {len(velodyne_msg_ram) }")
        # get data
        while len(gps_pose_msg_ram) > 0 and len(camera_msg_ram) > 0 and len(velodyne_msg_ram) > 0:
            gps_pose_ts = gps_pose_msg_ram[0].header.stamp.to_sec()
            camera_ts = camera_msg_ram[0].header.stamp.to_sec()
            velodyne_ts = velodyne_msg_ram[0].header.stamp.to_sec()
            if abs(gps_pose_ts - camera_ts) < 0.1 and abs(gps_pose_ts - velodyne_ts) < 0.1 and abs(velodyne_ts - camera_ts) < 0.1:
                if index % 2 == 0:
                    collect(
                        index/2, velodyne_msg_ram[0],  camera_msg_ram[0], gps_pose_msg_ram[0])
                index += 1
                velodyne_msg_ram.popleft()
                camera_msg_ram.popleft()
                gps_pose_msg_ram.popleft()
            else:
                front_msg = np.argmin([velodyne_ts, camera_ts, gps_pose_ts])
                if front_msg == 0:
                    velodyne_msg_ram.popleft()
                elif front_msg == 1:
                    camera_msg_ram.popleft()
                elif front_msg == 2:
                    gps_pose_msg_ram.popleft()

    # rospy.loginfo("Index: %d, velo time: %s, camera time: %s, gps time: %s.",
    #               index, velodyne_timestamp, camera_timestamp, gps_pose_timestamp)

    print("Finished!")


def collect(index, velodyne_msg, rgb_msg, gps_pose_msg):
    velodyne_ts = velodyne_msg.header.stamp.to_sec()
    camera_ts = rgb_msg.header.stamp.to_sec()
    gps_pose_ts = gps_pose_msg.header.stamp.to_sec()
    print(
        f"Index: {index}, velo time: {velodyne_ts}, camera time: {camera_ts}, gps time: {gps_pose_ts}, gps: ({gps_pose_msg.pose.position.x}, {gps_pose_msg.pose.position.y})")

    # write_calib(index, camera_info)
    # TO ADD: imu state -- ctime_mystate, vtime_mystate, ltime_mystate

    write_image(index, rgb_msg, 2)
    write_velodyne(index, velodyne_msg)
    write_poses_times(index, gps_pose_msg)


def rewrite_syncbag(bag_name, output_bag_name):
    '''from http://wiki.ros.org/rosbag/Cookbook
    '''
    with rosbag.Bag(output_bag_name, 'w') as outbag:
        for topic, msg, t in rosbag.Bag(bag_name).read_messages():
            # This also replaces tf timestamps under the assumption
            # that all transforms in the message share the same timestamp
            if topic == "/tf" and msg.transforms:
                outbag.write(topic, msg, msg.transforms[0].header.stamp)
            else:
                outbag.write(
                    topic, msg, msg.header.stamp if msg._has_header else t)


if __name__ == '__main__':
    bag_name = '2021-07-06-15-28-42.bag'
    write_dataset(bag_name)
