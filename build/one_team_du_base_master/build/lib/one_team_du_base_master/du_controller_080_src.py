# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run multi_du_udpcomm_02_pkg du_controller_080 --ros-args --params-file src/multi_du_udpcomm_02_pkg/config/params_080.yaml

#!/usr/bin/env python3
import rclpy
import sys

from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import String
from sensor_msgs.msg import JointState

class MinimalPubSubCont(Node):
    turtlePos = [0.0, 0.0, 0.0]
    x_maps = [-65.0, 65.0]
    y_maps = [-20.0, 20.0]
    mode = 0.0
    
    def __init__(self):   
        # Initialization
        super().__init__('du_controller_080') #node name
                      
        # Publishers
        self.twist_pub = self.create_publisher(Twist, 'du_080/cmd_vel', 100)
        self.cmd_joint_pub = self.create_publisher(JointState, 'du_080/cmd_joint', 100)
                
        # Timers
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        
        # Subscribers
        self.subscription = self.create_subscription(Pose, 'du_080/pose',  self.subsc_callback, 10)

    def timer_callback(self):
        twist_tmp = Twist()
        cmd_joint_tmp = JointState()
        
        piston1 = 0.0
        piston2 = 0.0
                
        # initial value
        twist_tmp.linear.x = 0.0 # target speed
        twist_tmp.angular.z = 0.0 # target angle
                
        
        if self.x_maps[0] < self.turtlePos[0] < self.x_maps[1]:
            twist_tmp.linear.x = 12.0
            #print(self.turtlePos[0])

            if (self.y_maps[0]+self.y_maps[1])//2 > self.turtlePos[1]:
                if self.y_maps[0] > self.turtlePos[1]:
                    twist_tmp.angular.z = 5.0
                else:
                    twist_tmp.angular.z = -5.0
            else:
                if self.y_maps[1] > self.turtlePos[1]:
                    twist_tmp.angular.z = -5.0
                else:
                    twist_tmp.angular.z = 5.0
        elif self.x_maps[1] < self.turtlePos[0]:
            twist_tmp.angular.z = 15.0
            twist_tmp.linear.x = 8.0
        elif self.x_maps[0] > self.turtlePos[0]:
            twist_tmp.angular.z = 15.0
            twist_tmp.linear.x = 8.0

        if self.mode == 0.0:
            twist_tmp.linear.x = 0.0
            twist_tmp.angular.z = 0.0
            
        cmd_joint_tmp.name = ['piston1', 'piston2']
        cmd_joint_tmp.position = [piston1, piston2]
        
        print(self.turtlePos[0])           
        self.twist_pub.publish(twist_tmp)
        self.cmd_joint_pub.publish(cmd_joint_tmp)
    
    def subsc_callback(self, pose):        
        self.turtlePos[0] = pose.x
        self.turtlePos[1] = pose.y
        self.turtlePos[2] = pose.theta       
        #print(pose.x)

    
def main():
    rclpy.init(args=sys.argv)
    
    pubsub = MinimalPubSubCont()
    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
