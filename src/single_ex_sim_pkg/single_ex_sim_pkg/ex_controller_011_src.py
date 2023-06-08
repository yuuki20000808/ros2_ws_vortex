# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run single_ex_sim_pkg ex_controller_000

#!/usr/bin/env python3
import rclpy
import sys

from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from sensor_msgs.msg import Joy
from sensor_msgs.msg import JointState

class MinimalPubSubCont(Node):        
    def __init__(self):   
        # Initialization
        super().__init__('ex_controller_001') #node name
               
        # Publishers
        self.cmd_vel_pub = self.create_publisher(Twist, 'ex_001/cmd_vel', 100)
        self.cmd_joint_pub = self.create_publisher(JointState, 'ex_001/cmd_joint', 100)
               
        # Joy Subscribers
        self.joy_sub = self.create_subscription(Joy, 'ex_001/joy',  self.joy_sub_callback, 10)       
        
    def joy_sub_callback(self, joy_tmp):
        #print("joy_def")
        cmd_vel_tmp = Twist()
        cmd_joint_tmp = JointState()
        
        swing = 0.0
        boom = 0.0 
        arm = 0.0
        bucket = 0.0       
        
        
        """
        cmd_vel_tmp.linear.x = float(joy_tmp.axes[7])
        cmd_vel_tmp.linear.y = float(joy_tmp.axes[6])       
        
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
        """
        
        cmd_vel_tmp.linear.x = -1*float(joy_tmp.axes[0])
        cmd_vel_tmp.linear.y = float(joy_tmp.axes[1])       
                
        if joy_tmp.buttons[1] == 1:#maru:turn right
            swing = 1.0
        elif joy_tmp.buttons[3] == 1:#shikaku:turn left
            swing = -1.0
       
        elif joy_tmp.buttons[0] == 1:#batu:down arm
            boom = 1.0                     
        elif joy_tmp.buttons[2] == 1:#sankaku:up arm
            boom = -1.0       
            
        elif joy_tmp.buttons[7] == 1:#R1:stretch
            arm = 1.0                     
        elif joy_tmp.buttons[5] == 1:#R2:bend
            arm = -1.0
        
        elif joy_tmp.buttons[6] == 1:#L1:release
            bucket = 1.0                     
        elif joy_tmp.buttons[4] == 1:#L2:dig
            bucket = -1.0

        
        cmd_joint_tmp.name = ['swing', 'boom', 'arm', 'bucket']
        cmd_joint_tmp.position = [swing, boom, arm, bucket]
                
        print(cmd_joint_tmp.position[0])
        
        self.cmd_vel_pub.publish(cmd_vel_tmp)
        self.cmd_joint_pub.publish(cmd_joint_tmp)
    
def main():
    rclpy.init(args=sys.argv)
    
    pubsub = MinimalPubSubCont()
    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
