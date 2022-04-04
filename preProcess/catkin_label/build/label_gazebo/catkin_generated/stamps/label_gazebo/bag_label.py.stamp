#!/usr/bin/env python

import cv2
import numpy as np
import os
import _thread
import math
import time
import geopy as gp
# ros
import rospy
import rospkg
import message_filters
from cv_bridge import CvBridge
# message
from std_msgs.msg import Header
from geometry_msgs.msg import Point
from geometry_msgs.msg import PoseStamped
# sensor data message
from sensor_msgs.msg import Image, CameraInfo
from sensor_msgs.msg import PointCloud2, PointCloud
from sensor_msgs import point_cloud2


basedir = os.path.abspath(os.path.dirname(__file__))
split = "training"  # or "testing"
ROOT_DIR = '/home/arijin'
root_dir = os.path.join(ROOT_DIR, 'dataset/inWater/object')
split_dir = os.path.join(root_dir, split)


def linestr(key, value):
    label = f"{key}:"
    if isinstance(value, int) or isinstance(value, float) or isinstance(value, str):
        label = f"{label}{value}\n"
        return label
    elif isinstance(value, list) or isinstance(value, tuple):
        length = len(value)
    elif type(value) is np.ndarray:
        value = value.reshape(-1)
        length = value.shape[0]
    else:
        label = f"{label} \n"
        return label
    if length == 0:
        label = f"{label} \n"
        return label
    for i in range(length-1):
        label = f"{label}{value[i]} "
    label = f"{label}{value[-1]}\n"
    return label


def get_pose_label(pose_msg):
    mx = pose_msg.pose.position.x
    my = pose_msg.pose.position.y
    mz = pose_msg.pose.position.z
    mqx = pose_msg.pose.orientation.x
    mqy = pose_msg.pose.orientation.y
    mqz = pose_msg.pose.orientation.z
    mqw = pose_msg.pose.orientation.w
    mrpy = gp.quart_to_rpy(mqx, mqy, mqz, mqw)
    mroll = mrpy[0]
    mpitch = mrpy[1]
    myaw = mrpy[2]

    pose_label = f"{mx} {my} {mz} {mroll} {mpitch} {myaw}"
    return pose_label

# ========
#   TO ADD
# ========
# def write_calib(index, camera_info):
#     pass


# def write_image_undistort(index, ros_image, camera_info, camera_number):
#     image_dir = os.path.join(split_dir, f'image_{camera_number}')
#     image_filename = os.path.join(image_dir, '%06d.png' % (index))
#     rgb_image = CvBridge().imgmsg_to_cv2(ros_image, desired_encoding="bgr8")
#     camera_info_K = np.array(camera_info.K).reshape([3, 3])
#     camera_info_D = np.array(camera_info.D)
#     camera_info_P = np.array(camera_info.P).reshape([3, 4])
#     camera_info_P[0, 3] = 0  # 不影响畸变矫正结果
#     camera_info_P[1, 3] = 0
#     rgb_undist = cv2.undistort(
#         rgb_image, camera_info_K, camera_info_D, None, camera_info_P)
#     cv2.imwrite(image_filename, rgb_undist)


def write_image(index, ros_image, camera_number):
    image_dir = os.path.join(split_dir, f'image_{camera_number}')
    image_filename = os.path.join(image_dir, '%06d.png' % (index))
    rgb_image = CvBridge().imgmsg_to_cv2(ros_image, desired_encoding="bgr8")
    cv2.imwrite(image_filename, rgb_image)


def write_velodyne(index, ros_velodyne):
    velodyne_dir = os.path.join(split_dir, 'velodyne_raw')
    velodyne_filename = os.path.join(velodyne_dir, '%06d.bin' % (index))
    vely_pc = list(point_cloud2.read_points(
        ros_velodyne, field_names=("x", "y", "z"), skip_nans=True))
    vely_pc = np.array(vely_pc)
    # print(velodyne_filename, ", velodyne pointcloud size: ", vely_pc.shape)
    # vely_pc = vely_pc[:, :3]
    vely_pc.tofile(velodyne_filename)  # 保存成bin文件时注意数据格式


def write_basic_infos(index, camera_timestamp, velodyne_timestamp, gps_pose_timestamp, gps_pose_msg):
    info_dir = os.path.join(split_dir, 'info')
    info_filename = os.path.join(info_dir, '%06d.txt' % (index))

    gps_pose_label = get_pose_label(gps_pose_msg)
    with open(info_filename, 'w') as f:
        f.write(linestr('camera_timestamp', camera_timestamp))
        f.write(linestr('velodyne_timestamp', velodyne_timestamp))
        f.write(linestr('gps_pose_timestamp', gps_pose_timestamp))
        f.write(linestr('gps_pose', gps_pose_label))


rgb_ram = None
rgb_mystate = None
velodyne_ram = None
velodyne_mystate = None
pose_ram = None
pose_mystate = None

index = 0

world_latitude = 31.5141625396
world_longitude = 121.132606168


def blinkpose_callback(gps_msg):
    # ===imuTODO===
    # global rgb_mystate
    # rgb_mystate = get_mystate()

    pose_msg = PoseStamped()
    pose_msg.header = gps_msg.header
    pose_msg.pose = gps_msg.pose  # Pose()
    pose_x, pose_y = gp.toXYCoordinate(world_latitude, world_longitude,
                                       gps_msg.SatCoordinate.latitude, gps_msg.SatCoordinate.longitude)
    pose_msg.pose.position.x = pose_x
    pose_msg.pose.position.y = pose_y
    pose_msg.pose.position.z = 0

    global pose_ram
    pose_ram = pose_msg


def image_callback(rgb_msg):
    # rospy.loginfo("camera collecting time: %s", rgb_msg.header.stamp.to_sec())
    ros_time = rospy.get_time()
    print(f"real time: {time.time()},{ros_time}",
          f"sim time: {rgb_msg.header.stamp.to_sec()}", ", camera come.")

    # ===imuTODO===
    # global rgb_mystate
    # rgb_mystate = get_mystate()

    global rgb_ram
    rgb_ram = rgb_msg

    time.sleep(1)


def velodyne_callback(velodyne_msg):
    # ros_time = rospy.get_time()
    # print(f"real time: {time.time()}",
    #       f"sim time: {velodyne_msg.header.stamp.to_sec()}", ", velodyne come.")

    # ===imuTODO===
    # global velodyne_mystate
    # velodyne_mystate = get_mystate()

    global velodyne_ram
    velodyne_ram = velodyne_msg

    global rgb_ram, pose_ram
    if rgb_ram != None and pose_ram != None:
        bag_collect(velodyne_ram, rgb_ram, pose_ram)


def bag_collect(velodyne_msg, rgb_msg, pose_msg):
    # ros_time = rospy.get_time() # maybe real time
    # print(f"real time: {time.time()}",
    #       f"sim time: {velodyne_msg.header.stamp.to_sec()}", ", velodyne come.")
    global index
    velodyne_timestamp = velodyne_msg.header.stamp.to_sec()
    camera_timestamp = rgb_msg.header.stamp.to_sec()
    gps_pose_timestamp = pose_msg.header.stamp.to_sec()
    # rospy.loginfo("Index: %d, velo time: %s, camera time: %s, gps time: %s.",
    #               index, velodyne_timestamp, camera_timestamp, gps_pose_timestamp)

    # write_calib(index, camera_info)
    # TO ADD: imu state -- ctime_mystate, vtime_mystate, ltime_mystate
    write_image(index, rgb_msg, 2)
    write_velodyne(index, velodyne_msg)
    write_basic_infos(index, camera_timestamp,
                      velodyne_timestamp, gps_pose_timestamp, pose_msg)
    index += 1


def ros_init():
    # GPS Topic
    rospy.Subscriber('/gps_data_rectified',
                     gpsPacket, blinkpose_callback, queue_size=1)

    # Image Topic
    rospy.Subscriber('/usb_cam/image_raw',
                     Image, image_callback, queue_size=100)

    # Lidar Topic
    # rospy.Subscriber('/rslidar_points',
    #                  PointCloud2, velodyne_callback, queue_size=1)

    global last_collect_time
    last_collect_time = rospy.get_time()


if __name__ == '__main__':
    rospy.init_node('bag_collect', anonymous=False)
    ros_init()

    rospy.spin()

    # closing all open windows
    cv2.destroyAllWindows()
