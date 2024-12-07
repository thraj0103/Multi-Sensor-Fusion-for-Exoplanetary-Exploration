#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
import numpy as np

class ImuPreprocessor(Node):
    def __init__(self):
        super().__init__('imu_preprocessor')
        self.subscription = self.create_subscription(
            Imu,
            '/imu',  # Input topic
            self.imu_callback,
            10
        )
        self.publisher = self.create_publisher(
            Imu,
            '/filtered_imu',  # Output topic
            10
        )
        self.get_logger().info("IMU Preprocessing Node Started!")

    def imu_callback(self, msg):
        # Apply low-pass filter to angular velocity and linear acceleration
        alpha = 0.9  # Low-pass filter constant
        filtered_msg = Imu()
        filtered_msg.header = msg.header

        # Filter angular velocity
        filtered_msg.angular_velocity.x = alpha * msg.angular_velocity.x
        filtered_msg.angular_velocity.y = alpha * msg.angular_velocity.y
        filtered_msg.angular_velocity.z = alpha * msg.angular_velocity.z

        # Filter linear acceleration
        filtered_msg.linear_acceleration.x = alpha * msg.linear_acceleration.x
        filtered_msg.linear_acceleration.y = alpha * msg.linear_acceleration.y
        filtered_msg.linear_acceleration.z = alpha * msg.linear_acceleration.z

        # Copy orientation directly (no filtering applied here)
        filtered_msg.orientation = msg.orientation

        # Publish the filtered IMU message
        self.publisher.publish(filtered_msg)
        self.get_logger().info("Published filtered IMU data!")

def main(args=None):
    rclpy.init(args=args)
    node = ImuPreprocessor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
