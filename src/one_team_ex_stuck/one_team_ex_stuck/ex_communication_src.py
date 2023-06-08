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

from std_msgs.msg import Float32

crawler_vy = 0
crawler_vx = 0
swing = 0
boom = 0
arm = 0
bucket = 0

# Setting communication IP and Ports
config = configparser.ConfigParser()
config.read('src/one_team_ex_stuck/config/config.ini')

UDP_IP_VORTEX = config['IP']['ip_vortex_000']
UDP_IP_ROS = config['IP']['ip_ex_000']
UDP_SEND_PORT = int(config['IP']['port_vortex_000'])
UDP_RECEIVE_PORT = int(config['IP']['port_ex_000'])

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
        super().__init__('ex_communication_test')
        
        # Publishers
        self.status_joint_pub = self.create_publisher(JointState, 'ex_000/status/joint/ang', 100)
        self.ex_soilmass_pub = self.create_publisher(Float32, 'ex_000/soilmass', 100)
                
        # Timers            
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        
        # Subscribers        
        self.subscription = self.create_subscription(Twist, 'ex_000/cmd/body/vel', self.subscription_callback, 10)
        self.cmd_swing_ang_sub = self.create_subscription(Float32, 'ex_000/cmd/swing/ang', self.cmd_swing_ang_callback, 10)
        self.cmd_boom_ang_sub = self.create_subscription(Float32, 'ex_000/cmd/boom/ang', self.cmd_boom_ang_callback, 10)
        self.cmd_arm_ang_sub = self.create_subscription(Float32, 'ex_000/cmd/arm/ang', self.cmd_arm_ang_callback, 10)
        self.cmd_bucket_ang_sub = self.create_subscription(Float32, 'ex_000/cmd/bucket/ang', self.cmd_bucket_ang_callback, 10)

    def timer_callback(self):
        # Recieve UDP communication
        receiveddata_udp = socketreceive.recvfrom(1024) # buffer size is 1024 bytes       
        datastructure = unpack('ddddd', receiveddata_udp[0])

        status_boom = datastructure[0]
        status_swing = datastructure[1]        
        status_arm = datastructure[2]
        status_bucket = datastructure[3]

        ex_soilmass_tmp = Float32()
        ex_soilmass_tmp.data = datastructure[4]
        self.ex_soilmass_pub.publish(ex_soilmass_tmp)

        status_joint_tmp = JointState()
        status_joint_tmp.name = ['swing','boom','arm','bucket']
        status_joint_tmp.position = [status_swing, status_boom, status_arm, status_bucket]
        self.status_joint_pub.publish(status_joint_tmp)
        
        ds = struct.pack('<dddddd', crawler_vy, crawler_vx, swing, boom, arm, bucket)
        socketsend.sendto(ds, (UDP_IP_VORTEX, UDP_SEND_PORT))  

    def subscription_callback(self, cmd_vel):       
        global crawler_vy, crawler_vx
        crawler_vx = cmd_vel.linear.x
        crawler_vy = cmd_vel.linear.y

    def cmd_swing_ang_callback(self, cmd_swing_ang):       
        global swing
        swing = cmd_swing_ang.data

    def cmd_boom_ang_callback(self, cmd_boom_ang):       
        global boom
        boom = cmd_boom_ang.data

    def cmd_arm_ang_callback(self, cmd_arm_ang):       
        global arm
        arm = cmd_arm_ang.data

    def cmd_bucket_ang_callback(self, cmd_bucket_ang):       
        global bucket
        bucket = cmd_bucket_ang.data

    """
    def subscription_joint_callback(self, cmd_joint):        
        global swing, boom, arm, bucket
        print(cmd_joint.position)
        swing = cmd_joint.position[0]
        boom = cmd_joint.position[1]
        arm = cmd_joint.position[2]
        bucket = cmd_joint.position[3]
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

