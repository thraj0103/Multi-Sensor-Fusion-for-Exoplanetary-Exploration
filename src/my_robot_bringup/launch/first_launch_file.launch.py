from launch import LaunchDescription
from launch_ros.actions import Node




def generate_launch_description():
    ld = LaunchDescription()

    news_station_node = Node(
         package = "my_py_pkg",
         executable= "robot_news_station"
    )


    smartphone_node = Node(
         package = "my_py_pkg",
         executable= "smartphone"
    )

    ld.add_action(smartphone_node)
    ld.add_action(news_station_node)
    return ld


