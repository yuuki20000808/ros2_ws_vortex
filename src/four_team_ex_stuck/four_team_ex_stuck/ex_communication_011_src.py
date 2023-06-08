# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run single_ex_sim_pkg ex_communication_000

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

from geometry_msgs.msg import Vector3
from sensor_msgs.msg import JointState

crawler_vy = 0
crawler_vx = 0
swing = 0
boom = 0
arm = 0
bucket = 0

# Setting communication IP and Ports
config = configparser.ConfigParser()
#config.read('src/multi_du_udpcomm_02_pkg/config/config.ini')
config.read('src/four_team_ex_stuck/config/config.ini')

UDP_IP_VORTEX = config['IP']['ip_vortex_001']
UDP_IP_ROS = config['IP']['ip_ex_001']
UDP_SEND_PORT = int(config['IP']['port_vortex_001'])
UDP_RECEIVE_PORT = int(config['IP']['port_ex_001'])

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
        super().__init__('ex_communication_001')
        
        # Publishers
        self.pose_pub = self.create_publisher(Pose, 'ex_001/pose', 100)
                
        # Timers            
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        
        # Subscribers
        self.subscription_joint = self.create_subscription(JointState, 'ex_001/cmd_joint', self.subscription_joint_callback, 10)
        self.subscription = self.create_subscription(Twist, 'ex_001/cmd_vel', self.subscription_callback, 10)
        
    def timer_callback(self):
        # Recieve UDP communication
        receiveddata_udp = socketreceive.recvfrom(1024) # buffer size is 1024 bytes       
        datastructure = unpack('d', receiveddata_udp[0])

        pose_tmp = Pose()
        pose_tmp.x = datastructure[0]
        self.pose_pub.publish(pose_tmp)
        
        ds = struct.pack('<dddddd', crawler_vy, crawler_vx, swing, boom, arm, bucket)
        socketsend.sendto(ds, (UDP_IP_VORTEX, UDP_SEND_PORT))  

    def subscription_callback(self, cmd_vel):       
        global crawler_vy, crawler_vx
        crawler_vy = cmd_vel.linear.x
        crawler_vx = cmd_vel.linear.y

    def subscription_joint_callback(self, cmd_joint):        
        global swing, boom, arm, bucket
        print(cmd_joint.position)
        swing = cmd_joint.position[0]
        boom = cmd_joint.position[1]
        arm = cmd_joint.position[2]
        bucket = cmd_joint.position[3]

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

