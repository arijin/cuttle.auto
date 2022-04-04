''' Helper class and functions for loading KITTI objects

Author: Ari Jin
Date: Jan. 2022
Reference: https://www.guyuehome.com/19226
'''
import numpy as np
import math

M_PI = 3.14159265359


def quart_to_rpy(x, y, z, w):
    roll = math.atan2(2 * (w * x + y * z), 1 - 2 * (x * x + y * y))
    pitch = math.asin(2 * (w * y - x * z))
    yaw = math.atan2(2 * (w * z + x * y), 1 - 2 * (z * z + y * y))
    return [roll, pitch, yaw]


def euler_to_quaternion(yaw, pitch, roll):
    ''' avoid 1/2=0 in python2 '''
    yaw, pitch, roll = float(yaw), float(pitch), float(roll)
    qx = np.sin(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) - \
        np.cos(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
    qy = np.cos(roll/2) * np.sin(pitch/2) * np.cos(yaw/2) + \
        np.sin(roll/2) * np.cos(pitch/2) * np.sin(yaw/2)
    qz = np.cos(roll/2) * np.cos(pitch/2) * np.sin(yaw/2) - \
        np.sin(roll/2) * np.sin(pitch/2) * np.cos(yaw/2)
    qw = np.cos(roll/2) * np.cos(pitch/2) * np.cos(yaw/2) + \
        np.sin(roll/2) * np.sin(pitch/2) * np.sin(yaw/2)
    return [qx, qy, qz, qw]


def euler_to_Rmatrix(yaw, pitch, roll):
    '''transform point from rotated coordinate into fixed world coordinate'''
    return np.dot(rotz(yaw), np.dot(roty(pitch), rotx(roll)))


def Rmatrix_to_euler(R):
    sy = math.sqrt(R[0, 0] * R[0, 0] + R[1, 0] * R[1, 0])
    singular = sy < 1e-6
    if not singular:
        x = math.atan2(R[2, 1], R[2, 2])
        y = math.atan2(-R[2, 0], sy)
        z = math.atan2(R[1, 0], R[0, 0])
    else:
        x = math.atan2(-R[1, 2], R[1, 1])
        y = math.atan2(-R[2, 0], sy)
        z = 0
    return [x, y, z]


def rotx(t):
    ''' 3D Rotation about the x-axis. '''
    c = np.cos(t)
    s = np.sin(t)
    return np.array([[1,  0,  0],
                     [0,  c, -s],
                     [0,  s,  c]])


def roty(t):
    ''' Rotation about the y-axis. '''
    c = np.cos(t)
    s = np.sin(t)
    return np.array([[c,  0,  s],
                     [0,  1,  0],
                     [-s, 0,  c]])


def rotz(t):
    ''' Rotation about the z-axis. '''
    c = np.cos(t)
    s = np.sin(t)
    return np.array([[c, -s,  0],
                     [s,  c,  0],
                     [0,  0,  1]])


def transform_from_rot_trans(R, t):
    ''' Transforation matrix from rotation matrix and translation vector. '''
    R = R.reshape(3, 3)
    t = t.reshape(3, 1)
    return np.vstack((np.hstack([R, t]), [0, 0, 0, 1]))  # 4*4


def inverse_rigid_rot(R):
    ''' Inverse a rigid body rotated matrix
    '''
    inv_R = np.transpose(R)
    return inv_R


def inverse_rigid_trans(Tr):
    ''' Inverse a rigid body transform matrix (3x4 as [R|t])
        [R'|-R't; 0|1]
    '''
    inv_Tr = np.zeros_like(Tr)  # 3x4
    inv_Tr[0:3, 0:3] = np.transpose(Tr[0:3, 0:3])
    inv_Tr[0:3, 3] = np.dot(-np.transpose(Tr[0:3, 0:3]), Tr[0:3, 3])
    return inv_Tr


def cart2hom(pts_3d):
    ''' Input: nx3 points in Cartesian
        Oupput: nx4 points in Homogeneous by pending 1
    '''
    n = pts_3d.shape[0]
    pts_3d_hom = np.hstack((pts_3d, np.ones((n, 1))))
    return pts_3d_hom


def ros2Trans(pose_msg):
    x = pose_msg.pose.position.x
    y = pose_msg.pose.position.y
    z = pose_msg.pose.position.z
    qx = pose_msg.pose.orientation.x
    qy = pose_msg.pose.orientation.y
    qz = pose_msg.pose.orientation.z
    qw = pose_msg.pose.orientation.w
    rpy = quart_to_rpy(qx, qy, qz, qw)
    roll = rpy[0]
    pitch = rpy[1]
    yaw = rpy[2]
    print(f"{yaw}, {pitch}, {roll}")
    Rotate = euler_to_Rmatrix(yaw, pitch, roll)
    Trans = transform_from_rot_trans(Rotate, np.array([x, y, z]))
    return Trans

# import tf
# def euler2q(roll, pitch, yaw):
#     quaternion = tf.transformations.quaternion_from_euler(roll, pitch, yaw)
#     return [quaternion[0], quaternion[1], quaternion[2], quaternion[3]]

# # math
# print(euler_to_quaternion(1, 0.1, -1.0))
# # ros tf
# print(euler2q(-1.0, 0.1, 1))


def euclid_distance(ax, ay, bx, by):
    dis = math.sqrt(math.pow(bx - ax, 2) + math.pow(by - ay, 2))
    return dis

# ========== Navigation =============
# static reference:  https://github.com/mikalhart/TinyGPSPlus


def distanceBetween(lat1, long1, lat2, long2):
    '''returns distance in meters between two positions, both specified
    as signed decimal-degrees latitude and longitude. Uses great-circle
    distance computation for hypothetical sphere of radius 6372795 meters.
    Because Earth is no exact sphere, rounding errors may be up to 0.5%.
    Courtesy of Maarten Lamers'''
    def radians(degree):
        rad = degree / 180 * M_PI
        return rad

    def square(x):
        return math.pow(x, 2)

    delta = radians(long1 - long2)
    sdlong = np.sin(delta)
    cdlong = np.cos(delta)

    lat1 = radians(lat1)
    lat2 = radians(lat2)
    slat1 = np.sin(lat1)
    clat1 = np.cos(lat1)
    slat2 = np.sin(lat2)
    clat2 = np.cos(lat2)

    delta = (clat1 * slat2) - (slat1 * clat2 * cdlong)
    delta = square(delta)
    delta += square(clat2 * sdlong)
    delta = math.sqrt(delta)
    denom = (slat1 * slat2) + (clat1 * clat2 * cdlong)
    delta = math.atan2(delta, denom)
    return delta * 6372795


def courseTo(lat1,  long1,  lat2,  long2):
    '''returns course in radians (North=0, West=270) from position 1 to position 2,
    both specified as signed decimal-degrees latitude and longitude.
    Because Earth is no exact sphere, calculated course may be off by a tiny fraction.
    Courtesy of Maarten Lamers.'''
    def radians(degree):
        rad = degree / 180 * M_PI
        return rad

    dlon = radians(long2 - long1)
    lat1 = radians(lat1)
    lat2 = radians(lat2)
    a1 = np.sin(dlon) * np.cos(lat2)
    a2 = np.sin(lat1) * np.cos(lat2) * np.cos(dlon)
    a2 = np.cos(lat1) * np.sin(lat2) - a2
    a2 = math.atan2(a1, a2)
    if a2 < 0.0:
        a2 += M_PI * 2
    return a2


def toXYCoordinate(lat1, long1, lat2, long2):
    radian = courseTo(lat1, long1, lat2, long2)
    distance = distanceBetween(lat1, long1, lat2, long2)
    y = np.cos(radian) * distance
    x = np.sin(radian) * distance
    return (x, y)
