from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import os


def generate_launch_description():
    # Get the package's launch directory
    launch_dir = os.path.join('/home/varun/ros2_ws/src/sensor_preprocessing/launch')

    # Include EKF launch file
    ekf_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_dir, 'ekf_launch.py'))
    )

    # Include SLAM Toolbox
    slam_toolbox_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource('/opt/ros/humble/share/slam_toolbox/launch/online_async_launch.py')
    )

    # Include TurtleBot3 Gazebo launch file
    gazebo_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource('/opt/ros/humble/share/turtlebot3_gazebo/launch/turtlebot3_world.launch.py')
    )

    # RViz2 node
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', os.path.join('/home/varun/ros2_ws', 'rviz_config.rviz')]  # Replace with your RViz config path if needed
    )

    return LaunchDescription([
        gazebo_launch,
        ekf_launch,
        slam_toolbox_launch,
        rviz_node
    ])
