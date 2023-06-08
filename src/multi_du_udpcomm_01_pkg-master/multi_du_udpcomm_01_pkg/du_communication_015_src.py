# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run multi_du_udpcomm_02_pkg du_communication_012 --ros-args --params-file src/multi_du_udpcomm_02_pkg/config/params_012.yaml

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

# Setting communication IP and Ports
config = configparser.ConfigParser()
config.read('/home/swarm/ros2_udpcomm01_ws/src/multi_du_udpcomm_01_pkg-master/config/config.ini')

UDP_IP_VORTEX = config['IP']['ip_vortex_015']
UDP_IP_ROS = config['IP']['ip_du_015']
UDP_SEND_PORT = int(config['IP']['port_vortex_015'])
UDP_RECEIVE_PORT = int(config['IP']['port_du_015'])

# Create a socket
try:
   socketsend = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
   socketreceive = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
except socket.error:
   print("Failed to create socket")
 
# Bind receiving port
socketreceive.bind((UDP_IP_ROS, UDP_RECEIVE_PORT))

# Set the socket to blocking
socketreceive.setblocking(True)

print("Communication setting initialization completed!")


class MinimalPubSubComm(Node):
    def __init__(self):
        # Initialization
        super().__init__('du_communication_015')       
        
        self.declare_parameter('param_turtlePublish_communication', 'du_015/pose')
        self.declare_parameter('param_turtleSubsc_communication', 'du_015/cmd_vel')
        self.declare_parameter('param_timer_period', 0.1)    
                
        turtlePublish = self.get_parameter('param_turtlePublish_communication').value
        turtleSubsc = self.get_parameter('param_turtleSubsc_communication').value
        self.timer_period = self.get_parameter('param_timer_period').value
        #print(self.get_parameter('param_timer_period').value)
        
        # Publishers
        self.pose_pub = self.create_publisher(Pose, turtlePublish, 100)
                
        # Timers            
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        #self.timer = self.create_timer(self.timer_period, self.timer_callback)
        
        # Subscribers
        #self.subscription = self.create_subscription(Twist, 'du_012/cmd_vel', self.subscription_callback, 10)
        self.subscription = self.create_subscription(Twist, turtleSubsc, self.subscription_callback, 10)
        self.subscription  # prevent unused variable warning
        
    def timer_callback(self):
        # Recieve UDP communication
        receiveddata_udp = socketreceive.recvfrom(1024) # buffer size is 1024 bytes       
        datastructure = unpack('ddd', receiveddata_udp[0])

        pose_tmp = Pose()
        pose_tmp.x = datastructure[0]
        pose_tmp.y = datastructure[1]
        pose_tmp.theta = datastructure[2]           
        self.pose_pub.publish(pose_tmp)
        #print('pose_tmp:', pose_tmp.x, pose_tmp.y)  

    def subscription_callback(self, cmd_vel):        
        # Send UDP communication
        ds = struct.pack('<dd', cmd_vel.linear.x, cmd_vel.angular.z)
        socketsend.sendto(ds, (UDP_IP_VORTEX, UDP_SEND_PORT))

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

