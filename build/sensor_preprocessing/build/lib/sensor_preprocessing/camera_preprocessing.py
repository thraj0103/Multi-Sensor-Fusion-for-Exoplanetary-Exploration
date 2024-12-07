#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class CameraPreprocessor(Node):
    def __init__(self):
        super().__init__('camera_preprocessor')
        self.bridge = CvBridge()
        self.subscription = self.create_subscription(
            Image,
            '/camera/image_raw',  # Input raw camera topic
            self.camera_callback,
            10
        )
        self.publisher = self.create_publisher(
            Image,
            '/processed_image',  # Output processed image topic
            10
        )
        self.get_logger().info("Camera Preprocessing Node Started!")

    def camera_callback(self, msg):
        # Convert ROS Image to OpenCV format
        cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')

        # Apply Gaussian blur to reduce noise
        processed_image = cv2.GaussianBlur(cv_image, (5, 5), 0)

        # Convert processed OpenCV image back to ROS Image
        processed_msg = self.bridge.cv2_to_imgmsg(processed_image, 'bgr8')
        self.publisher.publish(processed_msg)
        self.get_logger().info("Published processed camera image!")

def main(args=None):
    rclpy.init(args=args)
    node = CameraPreprocessor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
