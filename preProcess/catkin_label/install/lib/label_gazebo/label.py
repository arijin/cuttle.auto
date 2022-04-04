#!/usr/bin/env python3

from sympy import Idx
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
from gazebo_msgs.msg import ModelState
from gazebo_msgs.srv import SetModelState, GetModelState
from geometry_msgs.msg import Point
from water_msgs.msg import ShipState
# sensor data message
from sensor_msgs.msg import Image, CameraInfo
from sensor_msgs.msg import PointCloud2, PointCloud
from sensor_msgs import point_cloud2


basedir = os.path.abspath(os.path.dirname(__file__))
split = "training"  # or "testing"
ROOT_DIR = '/home/qiaolei'
root_dir = os.path.join(ROOT_DIR, 'dataset/inWater/object')
split_dir = os.path.join(root_dir, split)


class raw_object(object):
    def __init__(self):
        self.type = None
        self.tx = None
        self.ty = None
        self.tz = None

        self.pos_sx = None
        self.neg_sx = None
        self.pos_sy = None
        self.neg_sy = None
        self.h = None

        self.tyaw = None

        self.tlinearx = None
        self.tangularz = None

        self.timestamp = None

    def read_target_from_state(self, type, objectstate):
        self.type = type
        self.tx = objectstate.modelstate.pose.position.x
        self.ty = objectstate.modelstate.pose.position.y
        self.tz = objectstate.modelstate.pose.position.z

        qx = objectstate.modelstate.pose.orientation.x
        qy = objectstate.modelstate.pose.orientation.y
        qz = objectstate.modelstate.pose.orientation.z
        qw = objectstate.modelstate.pose.orientation.w
        self.tyaw = gp.quart_to_rpy(qx, qy, qz, qw)[2]

        self.tlinearx = objectstate.modelstate.twist.linear.x
        self.tangularz = objectstate.modelstate.twist.angular.z

        self.timestamp = objectstate.header.stamp

    def read_target_from_param(self, type, tx, ty, global_yaw):
        self.type = type
        self.tx = tx
        self.ty = ty
        self.tz = 0

        if type == "cone_buoy" or type == "sphere_buoy":
            self.tyaw = 0
        else:
            self.tyaw = global_yaw

        self.tlinearx = 0
        self.tangularz = 0
        self.timestamp = 0

    def read_basicinfos(self, type, subtype):
        ship_size = rospy.get_param(f"{type}/{subtype}/size")
        self.pos_sx = ship_size[0]
        self.neg_sx = ship_size[1]
        self.pos_sy = ship_size[2]
        self.neg_sy = ship_size[3]
        self.h = ship_size[4]

    def get_labelline(self):
        line = f"{self.type} {self.tx} {self.ty} {self.tz} {self.tyaw} {self.tlinearx} {self.tangularz} " +\
            f"{self.pos_sx} {self.neg_sx} {self.pos_sy} {self.neg_sy} {self.h} {self.timestamp}\n"
        return line


def get_model_state(name):
    # time = rospy.get_time()
    global g_get_state

    try:
        model_state = g_get_state(model_name=name)
    except Exception as e:
        rospy.logerr('Error on calling service: %s', str(e))
        return
    time_now = rospy.get_time()  # 获取到的是gazebo中的仿真时间，区分仿真时间和当前时间
    # dur_time = rospy.get_time() - time
    # print(f"read {name} cost {dur_time}s.")
    header = Header()
    header.stamp = time_now
    header.frame_id = "world"
    latest_state = ShipState()
    latest_state.header = header
    latest_state.modelstate = model_state
    return latest_state


def get_mystate():
    my_ship_state = get_model_state("wamv")
    return my_ship_state


def get_objectstate(my_ship_state):
    my_x = my_ship_state.modelstate.pose.position.x
    my_y = my_ship_state.modelstate.pose.position.y
    objectsList = list()

    # ships
    ships_type = rospy.get_param(f"ships/total_ships_type")
    # get all ship states
    for ship_type in ships_type:
        total_ships_name = rospy.get_param(
            f"ships/{ship_type}/ships_name")
        for ship_name in total_ships_name:
            obj_ship_state = get_model_state(ship_name)
            obj_x = obj_ship_state.modelstate.pose.position.x
            obj_y = obj_ship_state.modelstate.pose.position.y
            dis = gp.euclid_distance(my_x, my_y, obj_x, obj_y)
            if dis > 200:
                continue
            else:
                ship_object = raw_object()
                ship_object.read_target_from_state('ship', obj_ship_state)
                ship_object.read_basicinfos('ships', ship_type)
                objectsList.append(ship_object)
    # objects
    objects_type = rospy.get_param(f"objects/total_objects_type")
    # get all object states
    for object_type in objects_type:
        global_position = rospy.get_param(
            f"objects/{object_type}/global_position")
        global_yaw = rospy.get_param(
            f"objects/{object_type}/global_yaw")
        relative_positions = rospy.get_param(
            f"objects/{object_type}/relative_position")
        for object_position in relative_positions:
            obj_x = global_position[0] + object_position[0] * \
                np.cos(global_yaw) - object_position[1] * np.sin(global_yaw)
            obj_y = global_position[1] + object_position[0] * \
                np.sin(global_yaw) + object_position[1] * np.cos(global_yaw)
            dis = gp.euclid_distance(my_x, my_y, obj_x, obj_y)
            if dis > 180:
                continue
            else:
                object = raw_object()
                object.read_target_from_param(
                    object_type, obj_x, obj_y, global_yaw)
                object.read_basicinfos('objects', object_type)
                objectsList.append(object)
    return objectsList


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


def write_calib(index, camera_info):
    calib_dir = os.path.join(split_dir, 'calib')
    calib_filename = os.path.join(calib_dir, '%06d.txt' % (index))
    with open(calib_filename, 'w') as f:
        f.write(linestr('image_height', camera_info.height))
        f.write(linestr('image_width', camera_info.width))
        camera_info_P = np.array(camera_info.P).reshape([3, 4])
        camera_info_P[0, 3] = 0
        camera_info_P[1, 3] = 0
        f.write(linestr('P', camera_info_P))  # 3x4
        # 激光雷达和相机的外参
        # 相机
        crpy = rospy.get_param(f"cameraTF/rpy_radian")
        ctrans = rospy.get_param(f"cameraTF/translation")
        cT = gp.transform_from_rot_trans(gp.euler_to_Rmatrix(
            crpy[2], crpy[1], crpy[0]), np.array(ctrans))
        f.write(linestr('Tr_cam_to_base', cT[0:3, :]))
        # Velodyne
        vrpy = rospy.get_param(f"velodyneTF/rpy_radian")
        vtrans = rospy.get_param(f"velodyneTF/translation")
        vT = gp.transform_from_rot_trans(gp.euler_to_Rmatrix(
            vrpy[2], vrpy[1], vrpy[0]), np.array(vtrans))
        f.write(linestr('Tr_velo_to_base', vT[0:3, :]))
        # Livox
        lrpy = rospy.get_param(f"livoxTF/rpy_radian")
        ltrans = rospy.get_param(f"livoxTF/translation")
        lT = gp.transform_from_rot_trans(gp.euler_to_Rmatrix(
            lrpy[2], lrpy[1], lrpy[0]), np.array(ltrans))
        f.write(linestr('Tr_livox_to_base', lT[0:3, :]))


def write_image(index, ros_image, camera_info, camera_number):
    image_dir = os.path.join(split_dir, f'image_{camera_number}')
    image_filename = os.path.join(image_dir, '%06d.png' % (index))
    rgb_image = CvBridge().imgmsg_to_cv2(ros_image, desired_encoding="bgr8")
    camera_info_K = np.array(camera_info.K).reshape([3, 3])
    camera_info_D = np.array(camera_info.D)
    camera_info_P = np.array(camera_info.P).reshape([3, 4])
    camera_info_P[0, 3] = 0  # 不影响畸变矫正结果
    camera_info_P[1, 3] = 0
    rgb_undist = cv2.undistort(
        rgb_image, camera_info_K, camera_info_D, None, camera_info_P)
    cv2.imwrite(image_filename, rgb_undist)


def write_velodyne(index, ros_velodyne):
    velodyne_dir = os.path.join(split_dir, 'velodyne_raw')
    velodyne_filename = os.path.join(velodyne_dir, '%06d.bin' % (index))
    vely_pc = list(point_cloud2.read_points(
        ros_velodyne, field_names=("x", "y", "z"), skip_nans=True))
    vely_pc = np.array(vely_pc)
    # print(velodyne_filename, ", velodyne pointcloud size: ", vely_pc.shape)
    # vely_pc = vely_pc[:, :3]
    vely_pc.tofile(velodyne_filename)  # 保存成bin文件时注意数据格式


def write_livox(index, ros_livox):
    livox_dir = os.path.join(split_dir, 'livox_raw')
    livox_filename = os.path.join(livox_dir, '%06d.bin' % (index))
    pointcloud = list()
    for point in ros_livox.points:
        pointcloud.append([point.x, point.y, point.z])
    livox_pc = np.array(pointcloud)
    # print("livox pointcloud size: ", livox_pc.shape)
    livox_pc.tofile(livox_filename)


def write_raw_label(index, object_list):
    raw_label_dir = os.path.join(split_dir, 'label_2_raw')
    raw_label_filename = os.path.join(raw_label_dir, '%06d.txt' % (index))
    with open(raw_label_filename, 'w') as f:
        for object in object_list:
            f.write(object.get_labelline())


def get_motion_label(mystate):

    mx = mystate.modelstate.pose.position.x
    my = mystate.modelstate.pose.position.y
    mz = mystate.modelstate.pose.position.z
    mqx = mystate.modelstate.pose.orientation.x
    mqy = mystate.modelstate.pose.orientation.y
    mqz = mystate.modelstate.pose.orientation.z
    mqw = mystate.modelstate.pose.orientation.w
    mrpy = gp.quart_to_rpy(mqx, mqy, mqz, mqw)
    mroll = mrpy[0]
    mpitch = mrpy[1]
    myaw = mrpy[2]

    mlinearx = mystate.modelstate.twist.linear.x
    mangularz = mystate.modelstate.twist.angular.z

    mtimestamp = mystate.header.stamp
    motion_label = f"{mx} {my} {mz} {mroll} {mpitch} {myaw} {mlinearx} {mangularz} {mtimestamp}"

    return motion_label


def write_basic_infos(index, ctime_mystate, vtime_mystate, ltime_mystate, camera_timestamp, velodyne_timestamp, livox_timestamp):
    info_dir = os.path.join(split_dir, 'info')
    info_filename = os.path.join(info_dir, '%06d.txt' % (index))

    ctime_motion_label = get_motion_label(ctime_mystate)
    vtime_motion_label = get_motion_label(vtime_mystate)
    ltime_motion_label = get_motion_label(ltime_mystate)

    with open(info_filename, 'w') as f:
        f.write(linestr('camera_timestamp', camera_timestamp))
        f.write(linestr('velodyne_timestamp', velodyne_timestamp))
        f.write(linestr('livox_timestamp', livox_timestamp))
        f.write(linestr('ctime_motion', ctime_motion_label))
        f.write(linestr('vtime_motion', vtime_motion_label))
        f.write(linestr('ltime_motion', ltime_motion_label))


rgb_ram = None
camera_info_ram = None
velodyne_ram = None
velodyne_mystate = None
livox_ram = None
livox_mystate = None

need_velo = False
need_livox = False
write = False

index = 0


def collect(rgb_msg, camera_info, velo_msg, livox_msg, vtime_mystate, ltime_mystate):
    global index
    rospy.loginfo("Write once! Index: %d\ncamera time: %s, velo time: %s, livox time: %s.", index, rgb_msg.header.stamp.to_sec(
    ), velo_msg.header.stamp.to_sec(), livox_msg.header.stamp.to_sec())
    camera_timestamp = rgb_msg.header.stamp.to_sec()
    velodyne_timestamp = velo_msg.header.stamp.to_sec()
    livox_timestamp = livox_msg.header.stamp.to_sec()
    ctime_mystate = get_mystate()
    objectstate_list = get_objectstate(ctime_mystate)
    write_calib(index, camera_info)
    write_image(index, rgb_msg, camera_info, 2)
    write_velodyne(index, velo_msg)
    write_livox(index, livox_msg)
    write_raw_label(index, objectstate_list)
    write_basic_infos(index, ctime_mystate, vtime_mystate, ltime_mystate, camera_timestamp,
                      velodyne_timestamp, livox_timestamp)
    index += 1


last_collect_time = 0


def callback(rgb_msg, camera_info):
    # rospy.loginfo("camera collecting time: %s", rgb_msg.header.stamp.to_sec())
    ros_time = rospy.get_time()
    # print(f"real time: {time.time()}",
    #       f"sim time: {rgb_msg.header.stamp.to_sec()}", ", camera come.")
    global last_collect_time

    global rgb_ram
    global camera_info_ram
    global velodyne_ram
    global velodyne_mystate
    global livox_ram
    global livox_mystate

    global need_velo
    global need_livox
    global write

    if write == True and need_velo == False and need_livox == False:
        velo_time = velodyne_ram.header.stamp.to_sec()
        livox_time = livox_ram.header.stamp.to_sec()
        # print(
        #     f"c_ltime:{rgb_last_time}, c_ctime:{rgb_current_time}, vtime:{velo_time}, ltime:{livox_time}")
        min_time = min(velo_time, livox_time)
        max_time = max(velo_time, livox_time)
        durrent_time = max_time - min_time
        if durrent_time < 0.05:
            collect(rgb_msg, camera_info, velodyne_ram,
                    livox_ram, velodyne_mystate, livox_mystate)
            write = False
        else:
            print("waiting...")
            if velo_time < livox_time:
                need_velo = True
            else:
                need_livox = True
    # ======== shoting采集模式 ============
    # if write == False:
    #     rgb_image = CvBridge().imgmsg_to_cv2(rgb_msg, desired_encoding="bgr8")
    #     cv2.imshow("w", rgb_image)
    #     key = cv2.waitKey(50)
    #     if key == 115:
    #         write = True
    # ========== 连续采集模式 =============
    if write == False and ros_time - last_collect_time > 0.5:
        write = True
        last_collect_time = ros_time
    # ===================================
    if write == True and need_velo == False and need_livox == False:
        print("ready.")
        need_velo = True
        need_livox = True
    rgb_ram = rgb_msg
    camera_info_ram = camera_info


def velodyne_callback(velodyne_msg):
    # ros_time = rospy.get_time()
    # print(f"real time: {time.time()}",
    #       f"sim time: {velodyne_msg.header.stamp.to_sec()}", ", velodyne come.")
    global velodyne_ram
    global velodyne_mystate
    global need_velo
    if need_velo == True:
        velodyne_mystate = get_mystate()
        velodyne_ram = velodyne_msg
        need_velo = False


def livox_callback(livox_msg):
    # ros_time = rospy.get_time()
    # print(f"real time: {time.time()}",
    #       f"sim time: {livox_msg.header.stamp.to_sec()}", ", livox come.")
    global livox_ram
    global livox_mystate
    global need_livox
    if need_livox == True:
        livox_mystate = get_mystate()
        livox_ram = livox_msg
        need_livox = False


def ros_init():
    rospy.wait_for_service("/gazebo/get_model_state")
    global g_get_state
    g_get_state = rospy.ServiceProxy(
        "/gazebo/get_model_state", GetModelState)

    image_L_sub = message_filters.Subscriber(
        '/wamv/sensors/cameras/front_left_camera/image_raw', Image)
    # image_R_sub = message_filters.Subscriber(
    #     '/wamv/sensors/cameras/front_right_camera/image_raw', Image)
    info_L_sub = message_filters.Subscriber(
        '/wamv/sensors/cameras/front_left_camera/camera_info', CameraInfo)
    # info_R_sub = message_filters.Subscriber(
    #     '/wamv/sensors/cameras/front_right_camera/camera_info', CameraInfo)

    rospy.Subscriber('/wamv/sensors/lidars/lidar_wamv/points',
                     PointCloud2, velodyne_callback, queue_size=5)
    rospy.Subscriber('/scan',
                     PointCloud, livox_callback, queue_size=5)

    # publish which sensors
    ts = message_filters.TimeSynchronizer(
        [image_L_sub, info_L_sub], 1)
    ts.registerCallback(callback)
    global last_collect_time
    last_collect_time = rospy.get_time()


if __name__ == '__main__':
    rospy.init_node('collect_and_label', anonymous=True)
    ros_init()

    rospy.spin()

    # closing all open windows
    cv2.destroyAllWindows()
