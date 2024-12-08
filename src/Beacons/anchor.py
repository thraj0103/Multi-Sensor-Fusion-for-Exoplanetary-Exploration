#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped, Pose
from gazebo_msgs.srv import SpawnEntity
from tf2_ros import TransformBroadcaster
from std_msgs.msg import Header

class UwbAnchorSpawner(Node):
    def __init__(self, node_name='uwb_anchor_spawner'):
        super().__init__(node_name)

        # Declare and fetch parameters
        self.declare_parameter('anchors', [
            "name=uwb_anchor_1,x=0.0,y=0.0,z=1.0",
            "name=uwb_anchor_2,x=2.0,y=2.0,z=1.0",
            "name=uwb_anchor_3,x=-2.0,y=-2.0,z=1.0",
            "name=uwb_anchor_4,x=1.0,y=-1.0,z=1.0"  # Added fourth anchor
        ])
        self.anchors = self.parse_anchors(self.get_parameter('anchors').value)

        # Transform Broadcaster
        self.tf_broadcaster = TransformBroadcaster(self)

        # Create publishers for each anchor pose
        self.pose_publishers = {}
        for anchor in self.anchors:
            anchor_name = anchor['name']
            self.pose_publishers[anchor_name] = self.create_publisher(Pose, f'/uwb/{anchor_name}/pose', 10)

        # Spawn physical UWB anchors in Gazebo
        self.spawn_gazebo_anchors()

        # Timer for broadcasting logical transforms and publishing poses
        self.timer = self.create_timer(0.1, self.broadcast_and_publish_poses)

    def parse_anchors(self, anchors_param):
        anchors = []
        for anchor_str in anchors_param:
            parts = anchor_str.split(',')
            anchor = {}
            for part in parts:
                key, value = part.split('=')
                if key in ['x', 'y', 'z']:
                    anchor[key] = float(value)  # Parse numeric values
                else:
                    anchor[key] = value  # Keep names as strings
            anchors.append(anchor)
        return anchors

    def spawn_gazebo_anchors(self):
        """Spawn physical UWB anchors in Gazebo."""
        for anchor in self.anchors:
            name = anchor['name']
            position = [anchor['x'], anchor['y'], anchor['z']]

            self.get_logger().info(f'Spawning {name} at {position}')

            # Call the Gazebo service to spawn the anchor
            client = self.create_client(SpawnEntity, '/spawn_entity')
            while not client.wait_for_service(timeout_sec=5.0):
                self.get_logger().warn('/spawn_entity service not available. Waiting...')

            request = SpawnEntity.Request()
            request.name = name
            request.xml = self.generate_box_model(name)
            request.robot_namespace = name
            request.initial_pose = Pose()
            request.initial_pose.position.x = position[0]
            request.initial_pose.position.y = position[1]
            request.initial_pose.position.z = position[2]
            request.reference_frame = 'world'

            # Send the service request
            future = client.call_async(request)
            rclpy.spin_until_future_complete(self, future)
            if future.result() is not None:
                self.get_logger().info(f'{name} spawned successfully.')
            else:
                self.get_logger().error(f'Failed to spawn {name}: {future.exception()}')

    def generate_box_model(self, model_name):
        """Generate XML for a box model."""
        return f"""
        <sdf version="1.6">
            <model name="{model_name}">
                <static>true</static>
                <link name="link">
                    <visual name="visual">
                        <geometry>
                            <box>
                                <size>0.2 0.2 0.5</size>
                            </box>
                        </geometry>
                        <material>
                            <script>
                                <uri>file://media/materials/scripts/gazebo.material</uri>
                                <name>Gazebo/Red</name>
                            </script>
                        </material>
                    </visual>
                </link>
            </model>
        </sdf>
        """

    def broadcast_and_publish_poses(self):
        """Broadcast logical UWB transforms and publish poses for each anchor."""
        for anchor in self.anchors:
            name = anchor['name']
            position = [anchor['x'], anchor['y'], anchor['z']]

            # Broadcast transform
            t = TransformStamped()
            t.header.stamp = self.get_clock().now().to_msg()
            t.header.frame_id = 'map'
            t.child_frame_id = name
            t.transform.translation.x = position[0]
            t.transform.translation.y = position[1]
            t.transform.translation.z = position[2]
            t.transform.rotation.x = 0.0
            t.transform.rotation.y = 0.0
            t.transform.rotation.z = 0.0
            t.transform.rotation.w = 1.0
            self.tf_broadcaster.sendTransform(t)

            # Publish pose
            pose = Pose()
            pose.position.x = position[0]
            pose.position.y = position[1]
            pose.position.z = position[2]
            pose.orientation.x = 0.0
            pose.orientation.y = 0.0
            pose.orientation.z = 0.0
            pose.orientation.w = 1.0
            self.pose_publishers[name].publish(pose)
            self.get_logger().info(f"Published pose for {name}")


def main(args=None):
    rclpy.init(args=args)
    node = UwbAnchorSpawner()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
