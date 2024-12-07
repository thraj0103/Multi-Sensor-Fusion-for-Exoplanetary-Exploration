#!/usr/bin/env python3

import rclpy
import math
from rclpy.node import Node
from turtlesim.msg import Pose
from functools import partial
from geometry_msgs.msg import Twist
from catchall_interfaces.msg import Turtle
from catchall_interfaces.msg import TurtleArray
from catchall_interfaces.srv import CatchTurtle


class turtle_controllerNode(Node): 
    def __init__(self):
        super().__init__("turtle_controller") 
        
        #variables     
        self.pose = None
        self.target_turtle = None
        
        #Subscriber(s)
        self.pose_subscriber_ = self.create_subscription(Pose,"turtle1/pose", self.callback_turtle1_pose,10)
        self.get_logger().info("turtle pose subscriber has been started")
        self.alive_turtles_subscriber = self.create_subscription(TurtleArray, "alive_turtles", self.callback_alive_turtles,10 )

        #Publisher(s)
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.timer = self.create_timer(0.01, self.control_loop) #100 hz
        self.get_logger().info("Velocities are published")  

       
    def callback_alive_turtles(self,msg):
        if len(msg.turtles) > 0:
           self.target_turtle = msg.turtles[0]
           self.target_x = self.target_turtle.x 
           self.target_y = self.target_turtle.y   
    
    def control_loop(self):
        if self.pose == None or self.target_turtle == None:
            return

        msg = Twist() #creating a msg instance of Twist

        #Translation    Distance robot has to travel in x,y = target_Position(x,y) - robot current position(x,y)
        dist_x = self.target_x - self.pose.x
        dist_y = self.target_y - self.pose.y
        distance = math.sqrt(dist_x*dist_x + dist_y*dist_y)

        #Orientation   minimizing the robot orientation of target and current along the path
        goal_theta = math.atan2(dist_y,dist_x)
        diff = goal_theta - self.pose.theta
         # to remove the weird poses
        if diff > math.pi:
            diff -= 2*math.pi
        elif diff < -math.pi:
            diff += 2*math.pi
            
                           
        #Control logic making the turtle reach the point by making the distance 0 i.e, difference between target point and current point is zero
        if distance > 0.05: #error tolerance           
            #position
            msg.linear.x = 2*distance
            #orientation
            msg.angular.z = 6*diff

        else: #if robot is in the tolerance zone no need to move so zero velocities
            msg.linear.x = 0.0
            msg.angular.z = 0.0
            self.catch_turtle_client(self.target_turtle.name)
            self.target_turtle = None
    
        self.cmd_vel_publisher_.publish(msg)

    def callback_turtle1_pose(self,msg):
        self.pose = msg 
# ___________Service client for killing the turtle ______________    
    def catch_turtle_client(self,name):
        client = self.create_client( CatchTurtle, "catch_turtle")   # Creating a client with server type and name
        while not client.wait_for_service(1.0):                   # if the service is available after 1 second client.wait_for_service(1) returns true
            self.get_logger().warn("Waiting for server ...")

        request = CatchTurtle.Request() #creating an instance of requests of the srv type
        request.name = name
        
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_catch_turtle, name=name ))

    def callback_call_catch_turtle(self,future,name) :
        try:
            response = future.result()
            if not response.success:
                self.get_logger().error("turtle " + str(name) + "could not be caught")
        except Exception as e:
            self.get_logger().error("Service call failed %r" %(e, ))  
#___________________________________________________________________        
        

    
        
            
        
        
def main(args=None):
    rclpy.init(args=args)
    node = turtle_controllerNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "_main_":
    main()