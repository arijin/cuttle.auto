#!/usr/bin/env python3

import rospy
import rosbag
import sys
import os
# root
ROOT_DIR = '/home/arijin'
# raw
raw_dir = os.path.join(ROOT_DIR, 'dataset/inWater/raw')


def write_dataset(bag_name, output_bag_name):
    # with rosbag.Bag('output.bag', 'w') as outbag:
    for topic, msg, t in rosbag.Bag(os.path.join(raw_dir, bag_name)).read_messages():
        # This also replaces tf timestamps under the assumption
        # that all transforms in the message share the same timestamp
        if topic == "/tf" and msg.transforms:
            print(f"[{t.to_sec()}]: tf---{msg.transforms[0].header.stamp.to_sec()}")
            # outbag.write(topic, msg, msg.transforms[0].header.stamp)
        else:
            print(f"[{t.to_sec()}]: {topic}---{msg.header.stamp.to_sec()}")
            # outbag.write(
            #     topic, msg, msg.header.stamp if msg._has_header else t)


if __name__ == '__main__':
    bag_name = '2022-04-03-19-58-18.bag'
    otuput_bag_name = 'ndt_2022-04-03-19-58-18.bag'
    write_dataset(bag_name, otuput_bag_name)
