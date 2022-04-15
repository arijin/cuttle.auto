#!/usr/bin/env python3

import sys
import os
import numpy as np
from collections import deque
import geopy as gp

import rospy
import rosbag
# sensor data message
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


def write_poses(index, pose_msg):
    '''pose format per line row: 
        a b c d e f g h i j k l
        from a flattened 4x4 homogeneous pose matrix
        a b c d
        e f g h
        i j k l
        0 0 0 1
    '''
    def get_pose_label(transform_msg):
        x = transform_msg.translation.x
        y = transform_msg.translation.y
        z = transform_msg.translation.z
        qx = transform_msg.rotation.x
        qy = transform_msg.rotation.y
        qz = transform_msg.rotation.z
        qw = transform_msg.rotation.w
        rpy = gp.quart_to_rpy(qx, qy, qz, qw)
        roll = rpy[0]
        pitch = rpy[1]
        yaw = rpy[2]
        # print(f"{yaw}, {pitch}, {roll}")
        Rotate = gp.euler_to_Rmatrix(yaw, pitch, roll)
        Trans = gp.transform_from_rot_trans(Rotate, np.array([x, y, z]))

        pose_label = f"{Trans[0, 0]:f} {Trans[0, 1]:f} {Trans[0, 2]:f} {Trans[0, 3]:f}" \
            + f" {Trans[1, 0]:f} {Trans[1, 1]:f} {Trans[1, 2]:f} {Trans[1, 3]:f}" \
            + f" {Trans[2, 0]:f} {Trans[2, 1]:f} {Trans[2, 2]:f} {Trans[2, 3]:f}\n"
        return pose_label

    poses_file = os.path.join(seq_dir, 'poses.txt')
    pose_label = get_pose_label(pose_msg.transforms[0].transform)
    print(f"pose: {pose_label}")
    if index == 0:
        with open(poses_file, 'w') as f:
            f.write(pose_label)
    else:
        with open(poses_file, 'a') as f:
            f.write(pose_label)


def write_velodyne(index, velodyne_msg):
    velodyne_dir = os.path.join(seq_dir, 'velodyne')
    if not os.path.exists(velodyne_dir):
        os.makedirs(velodyne_dir)
    velodyne_filename = os.path.join(velodyne_dir, '%06d.bin' % (index))

    # 要不要过滤nan？？？不过滤是标准的16*1800=28800个点，过滤后大概为12000个点
    vely_pc = list(point_cloud2.read_points(
        velodyne_msg, field_names=("x", "y", "z"), skip_nans=True))
    vely_pc = np.array(vely_pc)
    # to 4 dims
    vely_pc = np.hstack([vely_pc, np.ones((vely_pc.shape[0], 1))])
    print(velodyne_filename, ", velodyne pointcloud size: ", vely_pc.shape)
    vely_pc = vely_pc.astype(np.float32)  # 设置float32数据类型，与KITTI保持一致
    vely_pc.tofile(velodyne_filename)  # 保存成bin文件时注意数据格式


def collect(index, pose_msg, lidar_msg):
    pose_ts = pose_msg.transforms[0].header.stamp.to_sec()
    lidar_ts = lidar_msg.header.stamp.to_sec()
    child_frame = pose_msg.transforms[0].child_frame_id
    print(
        f"[{index}], lidar time: {lidar_ts}, pose time: {pose_ts}, pose frame: ({child_frame} <-- {child_frame})")

    write_velodyne(index, lidar_msg)
    write_poses(index, pose_msg)


def write_dataset(bag_name, output_bag_name):
    index = 0
    pose_msg_ram = deque()
    lidar_msg_ram = deque()
    for topic, msg, t in rosbag.Bag(os.path.join(raw_dir, bag_name)).read_messages():
        if topic == "/tf" and msg.transforms:
            pose_msg_ram.append(msg)
            # print(f"[{t.to_sec()}]: tf---{msg.transforms[0].header.stamp.to_sec()}")
        elif topic == "/kitti/velo/pointcloud":
            lidar_msg_ram.append(msg)
            # print(f"[{t.to_sec()}]: {topic}---{msg.header.stamp.to_sec()}")
        while len(pose_msg_ram) > 0 and len(lidar_msg_ram) > 0:
            pose_ts = pose_msg_ram[0].transforms[0].header.stamp.to_sec()
            lidar_ts = lidar_msg_ram[0].header.stamp.to_sec()
            if(abs(pose_ts - lidar_ts) < 0.05):
                collect(index, pose_msg_ram[0], lidar_msg_ram[0])
                index += 1
                pose_msg_ram.popleft()
                lidar_msg_ram.popleft()
            else:
                front_msg = np.argmin([pose_ts, lidar_ts])
                if front_msg == 0:
                    pose_msg_ram.popleft()
                elif front_msg == 1:
                    lidar_msg_ram.popleft()
    print("Finished!")


if __name__ == '__main__':
    bag_name = '2022-04-03-19-58-18.bag'
    otuput_bag_name = 'ndt_2022-04-03-19-58-18.bag'
    write_dataset(bag_name, otuput_bag_name)
