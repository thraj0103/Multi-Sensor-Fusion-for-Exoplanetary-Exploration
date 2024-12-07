#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from functools import partial
import random
import math
from turtlesim.srv import Spawn
from turtlesim.srv import Kill
from catchall_interfaces.msg import Turtle
from catchall_interfaces.msg import TurtleArray
from catchall_interfaces.srv import CatchTurtle



class TurtleSpawnerNode(Node): 
    def __init__(self):
        super().__init__("turtle_spawner")
        
        #variables
        self.turtle_prefix = "turtle"
        self.turtle_number = 1
        self.alive_turtles = []

        #Publisher for publishing alive turtles
        self.alive_publisher = self.create_publisher ( TurtleArray, "alive_turtles", 10)   
        #Timer to continuously spawn turtles
        self.spawn_turtle_timer = self.create_timer(1, self.spawn_new_turtle)

        #Service
        self.catch_turtle_server = self.create_service(CatchTurtle ,"catch_turtle", self.callback_catch_turtle)


    def callback_catch_turtle(self,request,response):
        name = request.name 
        self.call_kill_turtle(name)
        response.success = True 
        return response 

    def publish_alive_turtles(self):
        msg = TurtleArray()
        msg.turtles = self.alive_turtles
        self.alive_publisher.publish(msg)    

    def spawn_new_turtle(self):
        self.turtle_number += 1
        self.name = self.turtle_prefix + str(self.turtle_number)
        self.x = random.uniform(0.0,11.0)
        self.y = random.uniform(0.0, 11.0)
        self.theta = random.uniform(0, 2*math.pi)
        self.call_spawn(self.x,self.y,self.theta,self.name)

# ___________________Service client for spawning the turtles________             
    
    def call_spawn(self, x, y, theta, name):
        client = self.create_client(Spawn, "spawn")   # Creating a client with server type and name
        while not client.wait_for_service(1.0):                   # if the service is available after 1 second client.wait_for_service(1) returns true
            self.get_logger().warn("Waiting for server ...")

        request = Spawn.Request() #creating an instance of requests of the srv type
        request.x = x
        request.y = y
        request.theta = theta
        request._name = name
        
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_spawn,x=x, y=y, theta=theta, name=name ))

    def callback_call_spawn(self,future,x,y,theta,name) :
        try:
            response = future.result()
            if response.name != "":
               self.get_logger().info("Turtle " + str(response.name) + " is alive ")
            new_turtle = Turtle()
            new_turtle.name = response.name
            new_turtle.x = x
            new_turtle.y = y
            new_turtle.theta = theta
            self.alive_turtles.append(new_turtle)
            self.publish_alive_turtles()

        except Exception as e:
            self.get_logger().error("Service call failed %r" %(e, ))


# ___________Service client for killing the turtle ______________    
    def call_kill_turtle(self,name):
        client = self.create_client(Kill, "kill")   # Creating a client with server type and name
        while not client.wait_for_service(1.0):                   # if the service is available after 1 second client.wait_for_service(1) returns true
            self.get_logger().warn("Waiting for server ...")

        request = Kill.Request() #creating an instance of requests of the srv type
        request._name = name
        
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_kill, name=name ))

    def callback_call_kill(self,future,name) :
        try:
            future.result()
            for (i, turtle ) in enumerate(self.alive_turtles):
                if turtle.name == name:
                    del self.alive_turtles[i]
                    self.publish_alive_turtles()
                    break
        except Exception as e:
            self.get_logger().error("Service call failed %r" %(e, ))  
#___________________________________________________________________           
            
                           
        


def main(args=None):
    rclpy.init(args=args)
    node = TurtleSpawnerNode() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "_main_":
    main()