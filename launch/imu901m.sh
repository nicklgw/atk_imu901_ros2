#!/bin/bash

export ROS_DOMAIN_ID=5
source /opt/ros/humble/setup.bash
export ROS_LOCALHOST_ONLY=1
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp

mkdir -m a=rwx -p /var/log/bzlrobot/ros2_imu
export ROS_LOG_DIR="/var/log/bzlrobot/ros2_imu"

/usr/bin/python3 /opt/ros/humble/bin/ros2 launch ros2_imu imu901m.launch.py
