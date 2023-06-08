# from dump_messages.srv import AddThreeInts       # CHANGE
# import sys
# import rclpy
# from rclpy.node import Node


# class MinimalClientAsync(Node):

#     def __init__(self):
#         super().__init__('minimal_client_async')
#         self.cli = self.create_client(AddThreeInts, 'add_three_ints')       # CHANGE
#         while not self.cli.wait_for_service(timeout_sec=1.0):
#             self.get_logger().info('service not available, waiting again...')
#         self.req = AddThreeInts.Request()                                   # CHANGE

#         timer_period = 0.01
#         self.timer = self.create_timer(timer_period, self.timer_callback) 

#     def send_request(self):
#         self.req.a = 1
#         self.req.b = 2
#         self.req.c = 3               # CHANGE
#         self.future = self.cli.call_async(self.req)


# def main(args=None):
#     rclpy.init(args=args)

#     minimal_client = MinimalClientAsync()
#     minimal_client.send_request()

#     while rclpy.ok():
#         rclpy.spin_once(minimal_client)
#         if minimal_client.future.done():
#             try:
#                 response = minimal_client.future.result()
#             except Exception as e:
#                 minimal_client.get_logger().info(
#                     'Service call failed %r' % (e,))
#             else:
#                 minimal_client.get_logger().info(
#                     'Result of add_three_ints: for %d + %d + %d = %d' %                               # CHANGE
#                     (minimal_client.req.a, minimal_client.req.b, minimal_client.req.c, response.sum)) # CHANGE
#             break

#     minimal_client.destroy_node()
#     rclpy.shutdown()


# if __name__ == '__main__':
#     main()

# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run multi_du_udpcomm_02_pkg du_communication_080 --ros-args --params-file src/multi_du_udpcomm_02_pkg/config/params_080.yaml

#!/usr/bin/env python3
import socket
import time
import struct
import rclpy
import math
import sys
import configparser

from struct import *
from contextlib import closing
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import Bool
from sensor_msgs.msg import JointState

from dump_messages.srv import Dumpbool
from std_srvs.srv import SetBool

track_vy = 0.0
track_vx = 0.0
track_wz = 0.0
piston1 = 0.0
piston2 = 0.0

test_flag = False


# Setting communication IP and Ports
'''
config = configparser.ConfigParser()
config.read('src/multi_du_udpcomm_02_pkg/config/config.ini')

UDP_IP_VORTEX = config['IP']['ip_vortex_080']
UDP_IP_ROS = config['IP']['ip_du_080']
UDP_SEND_PORT = int(config['IP']['port_vortex_080'])
UDP_RECEIVE_PORT = int(config['IP']['port_du_080'])
'''

# Create a socket
try:
   socketsend = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
   socketreceive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
except socket.error:
   print("Failed to create socket")
 
# Bind receiving port
'''
socketreceive.bind((UDP_IP_ROS, UDP_RECEIVE_PORT))
'''

# Set the socket to blocking
'''
socketreceive.setblocking(True)
'''

print("Communication setting initialization completed!")


class MinimalPubSubComm(Node):
    test_flag = False

    def __init__(self):
        # Initialization
        super().__init__('du_communication_080')       
        
        self.declare_parameter('param_turtlePublish_communication', 'du_080/pose')
        self.declare_parameter('param_turtleSubsc_communication', 'du_080/cmd_vel')
        self.declare_parameter('param_timer_period', 0.1)    
                
        turtlePublish = self.get_parameter('param_turtlePublish_communication').value
        turtleSubsc = self.get_parameter('param_turtleSubsc_communication').value
        self.timer_period = self.get_parameter('param_timer_period').value
        #print(self.get_parameter('param_timer_period').value)
        
        # Publishers
        self.pose_pub = self.create_publisher(Pose, turtlePublish, 100)
                
        # Timers            
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        #self.timer = self.create_timer(self.timer_period, self.timer_callback)
        
        # Subscribers
        #self.subscription = self.create_subscription(Twist, 'du_010/cmd_vel', self.subscription_callback, 10)
        self.subscription = self.create_subscription(Twist, turtleSubsc, self.subscription_callback, 10)
        self.subscription_joint = self.create_subscription(JointState, 'du_080/cmd_joint', self.subscription_joint_callback, 10)
        self.test_sub = self.create_subscription(Bool,'test_communication',self.test_callback,100)

        # Service
        self.srv = self.create_service(SetBool,'bool_test',self.bool_test_callback)

    def timer_callback(self):
        '''
        # Recieve UDP communication
        receiveddata_udp = socketreceive.recvfrom(1024) # buffer size is 1024 bytes       
        datastructure = unpack('ddd', receiveddata_udp[0])

        pose_tmp = Pose()
        pose_tmp.x = datastructure[0]
        pose_tmp.y = datastructure[1]
        pose_tmp.theta = datastructure[2]           
        self.pose_pub.publish(pose_tmp)
        #print('pose_tmp:', pose_tmp.x, pose_tmp.y)
        
        ds = struct.pack('<dddd', track_vy, track_wz, piston1, piston2)
        socketsend.sendto(ds, (UDP_IP_VORTEX, UDP_SEND_PORT))
        '''
        if self.test_flag:
            re_test_tmp = Bool()
            re_test_tmp.data = True
            self.re_test_pub.publish(re_test_tmp)
            print('publish')

    def bool_test_callback(self,request,response):
        print("x")
        if request.data == True:
            response.success = True
            response.message ="a"
            print('req is True')
        else:
            response.success = False
            response.message ="a"
            print('req is False')
        print(response.success)
        return response

    def subscription_callback(self, cmd_vel):        
        global track_vy, track_vx, track_wz
        track_vy = cmd_vel.linear.x
        track_vx = cmd_vel.linear.y
        track_wz = cmd_vel.angular.z
    
    def subscription_joint_callback(self, cmd_joint):        
        global piston1, piston2
        piston1 = cmd_joint.position[0]
        piston2 = cmd_joint.position[1]

    def test_callback(self,flag):
        self.test_flag = flag.data
        self.re_test_pub = self.create_publisher(Bool,'re_test_communication',100)

   
    
    """
    def subscription_callback(self, cmd_vel):        
        # Send UDP communication
        ds = struct.pack('<dd', cmd_vel.linear.x, cmd_vel.angular.z)
        socketsend.sendto(ds, (UDP_IP_VORTEX, UDP_SEND_PORT))
        """

def main(args=None):
    rclpy.init(args=args)
              
    #Published the position of the cafe
    sim_udp_comm = MinimalPubSubComm()
    rclpy.spin(sim_udp_comm)
    sim_udp_comm.destroy_node()    

    #Close processing         
    rclpy.shutdown()        

if __name__ == '__main__':
    main()

