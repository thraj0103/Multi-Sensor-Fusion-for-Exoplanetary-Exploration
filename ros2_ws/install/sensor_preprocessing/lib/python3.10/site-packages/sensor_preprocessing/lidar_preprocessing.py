
#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
import numpy as np

class LidarPreprocessor(Node):
    def __init__(self):
        super().__init__('lidar_preprocessor')
        self.subscription = self.create_subscription(
            LaserScan,
            '/scan',  # Input LiDAR topic
            self.lidar_callback,
            10
        )
        self.publisher = self.create_publisher(
            LaserScan,
            '/filtered_scan',  # Output topic for filtered data
            10
        )
        self.get_logger().info("LiDAR Preprocessing Node Started!")

    def lidar_callback(self, msg):
        # Filter LiDAR data: Remove invalid values (e.g., Inf or NaN)
        filtered_ranges = np.array(msg.ranges)
        filtered_ranges[np.isinf(filtered_ranges)] = msg.range_max
        filtered_ranges[np.isnan(filtered_ranges)] = msg.range_max

        # Create a new LaserScan message
        filtered_msg = LaserScan()
        filtered_msg.header = msg.header
        filtered_msg.angle_min = msg.angle_min
        filtered_msg.angle_max = msg.angle_max
        filtered_msg.angle_increment = msg.angle_increment
        filtered_msg.time_increment = msg.time_increment
        filtered_msg.scan_time = msg.scan_time
        filtered_msg.range_min = msg.range_min
        filtered_msg.range_max = msg.range_max
        filtered_msg.ranges = filtered_ranges.tolist()
        filtered_msg.intensities = msg.intensities

        # Publish the filtered message
        self.publisher.publish(filtered_msg)
        self.get_logger().info("Published filtered scan data!")

def main(args=None):
    rclpy.init(args=args)
    node = LidarPreprocessor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
