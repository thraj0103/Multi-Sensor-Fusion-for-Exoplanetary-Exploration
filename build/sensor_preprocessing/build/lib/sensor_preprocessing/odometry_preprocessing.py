#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry

class OdomPreprocessor(Node):
    def __init__(self):
        super().__init__('odom_preprocessor')
        self.subscription = self.create_subscription(
            Odometry,
            '/odom',  # Input topic for raw odometry
            self.odom_callback,
            10
        )
        self.publisher = self.create_publisher(
            Odometry,
            '/filtered_odom',  # Output topic for filtered odometry
            10
        )
        self.get_logger().info("Odometry Preprocessing Node Started!")

    def odom_callback(self, msg):
        # Filter noisy velocity data (e.g., smoothing or applying thresholds)
        filtered_msg = Odometry()
        filtered_msg.header = msg.header

        # Copy position and orientation directly
        filtered_msg.pose = msg.pose

        # Filter the velocity (example: scale it down slightly)
        filtered_msg.twist.twist.linear.x = msg.twist.twist.linear.x * 0.95
        filtered_msg.twist.twist.linear.y = msg.twist.twist.linear.y * 0.95
        filtered_msg.twist.twist.linear.z = msg.twist.twist.linear.z * 0.95
        filtered_msg.twist.twist.angular.x = msg.twist.twist.angular.x
        filtered_msg.twist.twist.angular.y = msg.twist.twist.angular.y
        filtered_msg.twist.twist.angular.z = msg.twist.twist.angular.z * 0.95

        # Publish the filtered odometry
        self.publisher.publish(filtered_msg)
        self.get_logger().info("Published filtered odometry!")

def main(args=None):
    rclpy.init(args=args)
    node = OdomPreprocessor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
