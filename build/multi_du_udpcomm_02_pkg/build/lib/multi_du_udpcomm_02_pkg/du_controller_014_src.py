# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run multi_du_udpcomm_02_pkg du_controller_010 --ros-args --params-file src/multi_du_udpcomm_02_pkg/config/params_010.yaml

#!/usr/bin/env python3
import rclpy
import sys
import math
import time

from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import String
from sensor_msgs.msg import JointState
from std_msgs.msg import Bool
from std_msgs.msg import Int16

from multi_du_udpcomm_02_pkg.a_star import astar
from multi_du_udpcomm_02_pkg.pure_pursuit import pure_pursuit_method

class MinimalPubSubCont(Node):

    turtlePos = [0.0, 0.0, 0.0]
    turtlePos_012 = [0.0, 0.0, 0.0]
    ID = 14
    count = 0.0
    load_count = 1000
    throw_away_count = 0
    waypoint = 0  
    target_index = None
    path = []
    old_path = None
    state = -1 # state

    work_finish_flag = False
    work_entry_flag = False

    def __init__(self):   
        # Initialization
        super().__init__('du_controller_014') #node name
                      
        # Publishers
        self.twist_pub = self.create_publisher(Twist, 'du_014/cmd_vel', 100)
        self.cmd_joint_pub = self.create_publisher(JointState, 'du_014/cmd_joint', 100)
        # Excavator Publishers 
        self.flag_work_start_pub = self.create_publisher(Bool,'ex_000/flag/work/start',100)
        self.flag_work_arrival_pub = self.create_publisher(Int16,'ex_000/flag/work/arrival',100)
                
        # Timers
        timer_period = 0.1  
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        
        # Subscribers
        self.subscription = self.create_subscription(Pose, 'du_014/pose',  self.subsc_callback, 10)
        self.subscription_012 = self.create_subscription(Pose, 'du_012/pose',  self.subsc_callback_012, 10)
        # Excavator Subscribers
        self.flag_startup_sub = self.create_subscription(Bool,'du_014/flag/startup', self.flag_work_start_callback, 10)
        self.flag_work_finish_sub = self.create_subscription(Bool,'ex_000/flag/work/finish', self.flag_work_finish_callback, 10)
        self.flag_work_entry_sub = self.create_subscription(Bool,'ex_000/flag/work/entry',self.flag_work_entry_callback, 10)

    def timer_callback(self):
        twist_tmp = Twist()
        cmd_joint_tmp = JointState()
        flag_work_start_tmp = Bool()
        flag_work_arrival_tmp = Int16()
        
        ### initial value
        twist_tmp.linear.x = 0.0 # target speed
        twist_tmp.angular.z = 0.0 # target angle
        twist_tmp.angular.x = self.turtlePos[2] # theta
        piston1 = 0.0
        piston2 = 0.0

        ### goal point decition
        start = (self.turtlePos[0], self.turtlePos[1])
        goal = [(0.0, -45.0),(10.0, -25.0),(15.0,-45.0),(-55.0,-25.0),(-65.0,-45.0),(-70.0,-25.0)]
        # goal = [(0.0, -55.0),(10.0, -35.0),(15.0,-55.0),(-20.0,-35.0),(-30.0,-55.0),(-55.0,-35.0)]

        print(self.state)

        if self.state == 0:
            self.waypoint = 0
            twist_tmp.linear.x = 10.0

            if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 3:
                self.work_entry_flag = False
                self.state = 8
                self.count = 0

        if self.state == 8:
            self.waypoint = 1
            twist_tmp.linear.x = 0.0

            flag_work_arrival_tmp.data = self.ID
            self.flag_work_arrival_pub.publish(flag_work_arrival_tmp)

            if self.work_entry_flag:
                self.state = 1
                self.count = 0
        
        elif self.state == 1:
            self.waypoint = 1
            twist_tmp.linear.x = 5.0

            if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 3:
                self.state = 2
                self.count = 0
        
        elif self.state == 2:
            self.waypoint = 2
            twist_tmp.linear.x = -5.0

            if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 3:
                flag_work_start_tmp.data = True
                self.flag_work_start_pub.publish(flag_work_start_tmp)
                self.work_finish_flag = False
                self.state = 3
                self.count = 0
        
        elif self.state == 3:
            self.waypoint = 3
            twist_tmp.linear.x = 0.0

            if self.work_finish_flag:
                self.state = 4
                self.count = 0
        
        elif self.state == 4:
            self.waypoint = 3
            twist_tmp.linear.x = 10.0

            if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 5:
                self.state = 5
                self.count = 0

        elif self.state == 5:
            self.waypoint = 4
            twist_tmp.linear.x = 5.0

            if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 3:
                self.state = 6
                self.count = 0
        
        elif self.state == 6:
            self.waypoint = 5
            twist_tmp.linear.x = -5.0

            if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 3:
                self.state = 7
                self.count = 0

        if self.state == 7:
            self.waypoint = 0
            twist_tmp.linear.x = 0.0

            if self.throw_away_count < 50:
                self.throw_away_count += 1
                piston1 = 1.0
                piston2 = 1.0
            elif 50 <= self.throw_away_count < 75:
                self.throw_away_count += 1
                piston1 = -1.0
                piston2 = -1.0
            else:
                self.state = 0
                self.count = 0
                self.throw_away_count = 0
                       
        ### a_star algorithm
        if self.count % 20 == 0.0:
            obstacle_x = self.turtlePos_012[0]
            obstacle_y = self.turtlePos_012[1]
            self.path = astar(obstacle_x, obstacle_y, start, goal[self.waypoint])
            self.target_index = None

        if self.path is not None:
            self.old_path = self.path
            self.count = self.count + 1.0
        else:
            self.path = self.old_path
            # self.get_logger().info("failed to generate a route!!")

        ### pure_pursuit algorithm
        if self.path is not None:
            pure_pursuit_target_angle,self.target_index = pure_pursuit_method(self.path,self.turtlePos,self.target_index,twist_tmp.linear.x)
            twist_tmp.angular.z = pure_pursuit_target_angle
        
        ### define piston
        cmd_joint_tmp.name = ['piston1', 'piston2']
        cmd_joint_tmp.position = [piston1, piston2]

        ### publish imfomation
        self.twist_pub.publish(twist_tmp)
        self.cmd_joint_pub.publish(cmd_joint_tmp)
    
    def subsc_callback(self, pose):        
        self.turtlePos[0] = pose.x
        self.turtlePos[1] = pose.y
        self.turtlePos[2] = pose.theta  # degree !!!
        #print(pose.x)

    def subsc_callback_012(self, pose):      
        self.turtlePos_012[0] = pose.x
        self.turtlePos_012[1] = pose.y
        self.turtlePos_012[2] = pose.theta     
       # self.obstacle.append((self.turtlePos_012[0],self.turtlePos_012[1]))

    def flag_work_start_callback(self,flag):
        if flag.data == True:
            self.state = 0

    def flag_work_finish_callback(self,flag):
        self.work_finish_flag = flag.data

    def flag_work_entry_callback(self,flag):
        self.work_entry_flag = flag.data
    
def main():
    rclpy.init(args=sys.argv)
    
    pubsub = MinimalPubSubCont()
    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
