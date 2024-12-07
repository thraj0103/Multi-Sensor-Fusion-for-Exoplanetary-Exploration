#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from functools import partial # this allows us to add more arguments to callback

from example_interfaces.srv import AddTwoInts


class AddTwoIntsClientNode(Node):
    def __init__(self):
        super().__init__("add_two_ints_client")
        self.call_add_two_ints_server(6, 8)
        self.call_add_two_ints_server(5, 7)
        self.call_add_two_ints_server(9, 6)


    def call_add_two_ints_server(self, a, b):
        client = self.create_client(AddTwoInts, "add_two_ints")   # Creating a client with server type and name
        while not client.wait_for_service(1.0):                   # if the service is available after 1 second client.wait_for_service(1) returns true
            self.get_logger().warn("Waiting for server Add Two Ints...")


        request = AddTwoInts.Request()  #creating an instance of requests of the server
        request.a = a
        request.b = b   


        future = client.call_async(request)  # Calling the server here or sending request
        future.add_done_callback(partial(self.callback_call_add_two_ints, a=a , b=b   )  )    # We use this to wait until we recieve message from server , since we called it async(client doesnt wait for reply and goes to next step) we use this
        
    def callback_call_add_two_ints(self,future, a, b):   #The call back function the above line waits for
        try:
            response = future.result()                    #adding future.results into response
            self.get_logger().info(str(a) + " + " + str(b) + " = " + str(response.sum) ) #This message is shown as output, we can do other stuff we want to manipulate the data with here

        except Exception as e:
            self.get_logger().error("Service call failed %r" %(e, ))    


def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClientNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "_main_":
    main()