#!/usr/bin/env python3

import math
import rclpy
from rclpy.node import Node
from tf2_ros import Buffer, TransformListener, TransformException
from std_msgs.msg import Float64MultiArray
from geometry_msgs.msg import Pose


class UwbTagNode(Node):
    def __init__(self):
        super().__init__('uwb_tag_node')

        # Declare parameters
        self.declare_parameter('anchor_topics', [
            '/uwb/uwb_anchor_1/pose',
            '/uwb/uwb_anchor_2/pose',
            '/uwb/uwb_anchor_3/pose',
            '/uwb/uwb_anchor_4/pose'
        ])
        self.declare_parameter('robot_frame', 'base_link')  # Robot's TF frame

        # Retrieve parameters
        self.anchor_topics = self.get_parameter('anchor_topics').value
        self.robot_frame = self.get_parameter('robot_frame').value

        # Store anchor poses
        self.anchor_poses = {}  # {topic_name: Pose}

        # TF2 Buffer and Listener
        self.tf_buffer = Buffer(cache_time=rclpy.duration.Duration(seconds=20))  # Increase TF cache time
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # Subscriber for anchor poses
        for topic in self.anchor_topics:
            self.create_subscription(Pose, topic, self.create_anchor_callback(topic), 10)

        # Publisher for distances
        self.distance_publisher = self.create_publisher(Float64MultiArray, '/uwb/tag_distances', 10)

        # Timer for calculating distances
        self.timer = self.create_timer(0.2, self.calculate_distances)

    def create_anchor_callback(self, topic_name):
        """Create a subscription callback for a specific topic."""
        def anchor_pose_callback(msg: Pose):
            """Callback to store the anchor pose."""
            self.anchor_poses[topic_name] = msg
            self.get_logger().info(f"Updated pose for {topic_name}: ({msg.position.x}, {msg.position.y}, {msg.position.z})")
        return anchor_pose_callback

    def calculate_distances(self):
        """Calculate distances between the robot's current position and all anchors."""
        distances = Float64MultiArray()
        distances.data = []

        try:
            # Get the robot's current position in the 'map' frame
            transform = self.tf_buffer.lookup_transform(
                'map', self.robot_frame, rclpy.time.Time(), timeout=rclpy.duration.Duration(seconds=0.2)
            )
            robot_x = transform.transform.translation.x
            robot_y = transform.transform.translation.y
            robot_z = transform.transform.translation.z

        except TransformException as ex:
            self.get_logger().warn(f"Could not get robot position: {ex}")
            return

        for topic, pose in self.anchor_poses.items():
            # Calculate Euclidean distance
            distance = self.calculate_distance(robot_x, robot_y, robot_z, pose.position.x, pose.position.y, pose.position.z)
            distances.data.append(distance)
            self.get_logger().info(f"Distance to {topic}: {distance:.2f} meters")

        # Publish distances
        self.distance_publisher.publish(distances)

    @staticmethod
    def calculate_distance(x1, y1, z1, x2, y2, z2):
        """Calculate Euclidean distance between two 3D points."""
        return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2)


def main(args=None):
    rclpy.init(args=args)
    node = UwbTagNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
