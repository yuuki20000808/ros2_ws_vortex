# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run multi_du_udpcomm_02_pkg du_controller_012 --ros-args --params-file src/multi_du_udpcomm_02_pkg/config/params_012.yaml

#!/usr/bin/env python3
import rclpy
import sys

from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import String

class MinimalPubSubCont(Node):
    turtlePos = [0.0, 0.0, 0.0]
    x_maps = [-95,-15]
    y_maps = [660,690]
    x_stops = [-30, -25]
    y_stops = [660, 690]
    
    def __init__(self):   
        # Initialization
        super().__init__('du_controller_015') #node name
        
        self.declare_parameter('param_turtlePublish_controller', 'du_015/cmd_vel')
        self.declare_parameter('param_turtleSubsc_controller', 'du_015/pose')
        self.declare_parameter('param_timer_period', 0.1)
                
        turtlePublish = self.get_parameter('param_turtlePublish_controller').value
        turtleSubsc = self.get_parameter('param_turtleSubsc_controller').value
        self.timer_period = self.get_parameter('param_timer_period').value
               
        # Publishers
        self.twist_pub = self.create_publisher(Twist, turtlePublish, 100)
                
        # Timers
        self.timer = self.create_timer(self.timer_period, self.timer_callback)    
        
        # Subscribers
        #self.subscription = self.create_subscription(Pose, 'du_012/pose',  self.subsc_callback, 10)
        self.subscription = self.create_subscription(Pose, turtleSubsc,  self.subsc_callback, 10)
        self.subscription  # prevent unused variable warning       

    def timer_callback(self):
        twist_tmp = Twist()
        twist_tmp.linear.x = 12.0
        twist_tmp.angular.z = 0.0

        if self.x_stops[0] < self.turtlePos[0] < self.x_stops[1]:
            twist_tmp.linear.x = 0.0
            print(self.turtlePos[0])

        elif self.x_maps[0] < self.turtlePos[0] < self.x_maps[1]:
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
            twist_tmp.angular.z = 25.0
            twist_tmp.linear.x = 8.0
        elif self.x_maps[0] > self.turtlePos[0]:
            twist_tmp.angular.z = 25.0
            twist_tmp.linear.x = 8.0
            
        self.twist_pub.publish(twist_tmp)
    
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
