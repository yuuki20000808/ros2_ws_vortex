# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run single_ex_sim_pkg ex_controller_000

#!/usr/bin/env python3
import rclpy
import sys
import time
import math
import random

from rclpy.node import Node
from geometry_msgs.msg import Twist

from turtlesim.msg import Pose
from sensor_msgs.msg import Joy
from sensor_msgs.msg import JointState

from std_msgs.msg import Float32
from std_msgs.msg import Int8


mode = 0
state = 0
ko_state = 0

global status_boom, status_swing, status_arm, status_bucket

class MinimalPubSubCont(Node):        

    sand_list = []
    swing_rand_target = 0.0
    swing_diff_target = 30.0

    def __init__(self):   
        # Initialization
        super().__init__('ex_controller_test') #node name
               
        # Publishers
        self.cmd_vel_pub = self.create_publisher(Twist, 'ex_000/cmd/body/vel', 100)
        self.cmd_swing_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/swing/ang', 100)
        self.cmd_boom_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/boom/ang', 100)
        self.cmd_arm_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/arm/ang', 100)
        self.cmd_bucket_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/bucket/ang', 100)
               
        # Joy Subscribers
        self.status_joint_sub = self.create_subscription(JointState, 'ex_000/status/joint/ang',  self.status_joint_callback, 10)
        self.cmd_joy_sub = self.create_subscription(Joy, 'ex_000/cmd/joy',  self.cmd_joy_callback, 10)
        self.ex_soilmass_sub = self.create_subscription(Float32, 'ex_000/soilmass', self.ex_soilmass_callback, 100)

    def status_joint_callback(self, joint_tmp):
        global status_boom, status_swing, status_arm, status_bucket
        status_swing = joint_tmp.position[0]
        status_boom = joint_tmp.position[1]
        status_arm = joint_tmp.position[2]
        status_bucket = joint_tmp.position[3]

    def ex_soilmass_callback(self, soilmass_tmp):
        global soilmass
        soilmass = soilmass_tmp.data

    def cmd_joy_callback(self, joy_tmp):
        
        crawler_vx = 0.0
        crawler_vy = 0.0
        swing = 0.0
        boom = 0.0 
        arm = 0.0
        bucket = 0.0

        global mode, state, ko_state

        # mode change
        if joy_tmp.buttons[9] == 1:
            mode = 0
        elif joy_tmp.buttons[10] == 1:
            mode = 1
        
        # remote mode
        if mode == 0:

            crawler_vx = joy_tmp.axes[6]
            crawler_vy = joy_tmp.axes[7]
            
            if joy_tmp.buttons[1] == 1:
                swing = 1.0
                
            elif joy_tmp.buttons[3] == 1:
                swing = -1.0
                
            elif joy_tmp.buttons[0] == 1:
                boom = 1.0                     
            elif joy_tmp.buttons[2] == 1:
                boom = -1.0       
            
            elif joy_tmp.buttons[5] == 1:
                arm = 1.0                     
            elif joy_tmp.buttons[7] == 1:
                arm = -1.0
        
            elif joy_tmp.buttons[4] == 1:
                bucket = 1.0                     
            elif joy_tmp.buttons[6] == 1:
                bucket = -1.0
        
        
        # auto mode
        elif mode == 1:

            # print("state:", state, ko_state)        

            if state == 0:
                arm_target = -25

                if status_arm >= arm_target:
                    arm = -2.0
                elif status_arm < arm_target:
                    arm = 0.0
                    ko_state = ko_state + 1       

            if state == 1:
                swing_target = self.swing_diff_target

                if status_swing <= swing_target:
                    swing = 2.0
                elif status_swing > swing_target:
                    swing = 0.0
                    ko_state = ko_state + 1       

            if state == 2:
                boom_target = -20

                if status_boom >= boom_target:
                    boom = -2.0
                elif status_boom < boom_target:
                    boom = 0.0
                    ko_state = ko_state + 1

            if state == 3:
                boom_target = 10

                if status_boom <= boom_target:
                    boom = 2.0
                elif status_boom > boom_target:
                    boom = 0.0
                    ko_state = ko_state + 1

            if state == 4:
                bucket_target = 150

                if status_bucket <= bucket_target:
                    bucket = 3.0
                elif status_bucket > bucket_target:
                    bucket = 0.0
                    ko_state = ko_state + 1

            if state == 5:
                boom_target = -40

                if status_boom >= boom_target:
                    boom = -2.0
                elif status_boom < boom_target:
                    boom = 0.0
                    ko_state = ko_state + 1

            if state == 6:
                arm_target = -30

                if status_arm >= arm_target:
                    arm = -2.0
                elif status_arm < arm_target:
                    arm = 0.0
                    ko_state = ko_state + 1

            if state == 7:
                swing_target = -60

                if status_swing >= swing_target:
                    swing = -2.0
                elif status_swing < swing_target:
                    swing = 0.0
                    ko_state = ko_state + 1

            if state == 8:
                bucket_target = 0

                if status_bucket >= bucket_target:
                    bucket = -3.0
                elif status_bucket < bucket_target:
                    bucket = 0.0
                    ko_state = ko_state + 1

            if ko_state == 10:
                state = state + 1
                ko_state = 0

                if state == 1:
                    self.swing_diff_target -= 5.0

                elif state == 7:
                    self.sand_list.append(soilmass)

                elif state == 9:
                    state = 0
                    print('times:',len(self.sand_list))
                    print(self.sand_list)

        cmd_vel_tmp = Twist()
        cmd_vel_tmp.linear.x = float(crawler_vx)
        cmd_vel_tmp.linear.y = float(crawler_vy)

        cmd_swing_ang_tmp = Float32()
        cmd_swing_ang_tmp.data = swing

        cmd_boom_ang_tmp = Float32()
        cmd_boom_ang_tmp.data = boom

        cmd_arm_ang_tmp = Float32()
        cmd_arm_ang_tmp.data = arm

        cmd_bucket_ang_tmp = Float32()
        cmd_bucket_ang_tmp.data = bucket

        """
        cmd_joint_tmp.name = ['swing', 'boom', 'arm', 'bucket']
        cmd_joint_tmp.position = [swing, boom, arm, bucket]
        """
        
        self.cmd_vel_pub.publish(cmd_vel_tmp)
        self.cmd_boom_ang_pub.publish(cmd_boom_ang_tmp)
        self.cmd_arm_ang_pub.publish(cmd_arm_ang_tmp)
        self.cmd_swing_ang_pub.publish(cmd_swing_ang_tmp)
        self.cmd_bucket_ang_pub.publish(cmd_bucket_ang_tmp)

    
def main():
    rclpy.init(args=sys.argv)
    
    pubsub = MinimalPubSubCont()
    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
