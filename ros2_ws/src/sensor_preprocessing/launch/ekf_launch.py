from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='robot_localization',
            executable='ekf_node',
            name='ekf_filter_node',
            output='screen',
            parameters=[
                '/home/varun/ros2_ws/src/sensor_preprocessing/config/ekf.yaml'  # Full path to ekf.yaml
            ]
        )
    ])

