from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()


    turtlesimNode =Node(
        package = "turtlesim",
        executable = "turtlesim_node"
    )

    turtle_spawner_node =Node(
        package = "catchall_py_pkg",
        executable = "turtle_controller"
    )

    turtle_controller_node =Node(
        package = "catchall_py_pkg",
        executable = "turtle_spawner"
    )
    


    ld.add_action(turtlesimNode)
    ld.add_action(turtle_spawner_node)
    ld.add_action(turtle_controller_node)
    return ld