import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():

    imu_cfg = os.path.join(get_package_share_directory('ros2_imu'), 'params', 'imu_cfg.yaml')

    # only for humble
    return LaunchDescription([
        Node(
            namespace='/', 
            package='ros2_imu', 
            executable='ros2_imu_node', 
            name='ros2_imu_node', 
            parameters=[imu_cfg], 
            output='screen'
        )
    ])
