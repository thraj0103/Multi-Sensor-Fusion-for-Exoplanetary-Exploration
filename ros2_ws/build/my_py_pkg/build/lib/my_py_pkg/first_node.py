#!/usr/bin/env python3
import rclpy       #import rclpy to use ROS2 functionalities
from rclpy.node import Node


class MyNode(Node):                  #Create a class with node name and make it inherit from Node object of rclpy
    
    def __init__(self):              #Write the constructor of the class
        super().__init__("py_test")  #call __init__ function from node and give it the name of node

        
        
    #Write the Code related to application here(example)
    #-------------------------------------------------------
        self.counter_ = 0
        self.get_logger().info("Hello ROS2!")
        self.create_timer(0.5, self.timer_callback)
        

    
    def timer_callback(self):
        self.counter_ += 1
        self.get_logger().info("Hello" + str(self.counter_) + '!@#$')
        pass
    #--------------------------------------------------------

def main(args=None):
    rclpy.init(args=args)     #intialise ROS2 communication
    node = MyNode()           #Calling the object of node class we created
    rclpy.spin(node)          #The program is live continuosly
    rclpy.shutdown()          #last line of program to shut it down
    pass

if __name__ == "__main__":
    main()


