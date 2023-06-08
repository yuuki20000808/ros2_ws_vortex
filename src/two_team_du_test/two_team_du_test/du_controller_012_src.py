# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run two_team_du_test du_controller_012 --ros-args --params-file src/two_team_du_test/config/params_012.yaml

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
from std_msgs.msg import Float32

from two_team_du_test.a_star import astar
from two_team_du_test.pure_pursuit import pure_pursuit_method
from two_team_du_test.detect_waypoint import *
from dump_messages.msg import DumpCNP
from dump_messages.msg import DumpInfoForServer
from dump_messages.msg import ExPosAndTeamNumber

Vessel_up_angular_velocity = -0.5
Vessel_down_angular_velocity = 0.5

hole = [-100.0,-5.0]

class MinimalPubSubCont(Node):

    turtlePos = [0.0, 0.0, 0.0]
    turtlePos_012 = [0.0, 0.0, 0.0]
    ID = 12
    team = 0
    count = 0.0
    load_count = 1000
    throw_away_count = 0
    waypoint = 0  
    waypoint_list = []
    target_index = None
    path = []
    old_path = None
    state = -1 # state
    healty = 1.0

    stack_count = 0

    obstacle_x = -1000.0
    obstacle_y = -1000.0

    work_finish_flag = False
    work_entry_flag = False
    task_complete_flag = False
    dump_site_entry_flag = False

    dump_info = DumpCNP()
    dump_info.id = ID
    dump_info.operational = True

    dump_ID_and_team_number = DumpInfoForServer()
    dump_ID_and_team_number.id = ID
    dump_ID_and_team_number.team = team

    initial_pos = [0.0, 0.0, 0.0]
    subsc_count = 0

    def __init__(self):   
        # Initialization
        super().__init__('du_controller_012') #node name
                      
        # Publishers
        self.twist_pub = self.create_publisher(Twist, 'du_012/cmd_vel', 100)
        self.vessel_angular_velocity_pub = self.create_publisher(Float32, 'du_012/vessel_angular_velocity', 10)
        self.cmd_joint_pub = self.create_publisher(JointState, 'du_012/cmd_joint', 100)
        # Excavator Publishers 
        self.flag_work_start_pub = self.create_publisher(Bool,'ex_000/flag/work/start',100)
        self.flag_work_arrival_pub = self.create_publisher(Int16,'ex_000/flag/work/arrival',100)
        self.flag_dump_site_arrival_pub = self.create_publisher(Int16,'ex_000/flag/dump_site/arrival',100)
        self.flag_dump_site_finished_pub = self.create_publisher(Bool,'ex_000/flag/dump_site/finished',100)
        self.flag_stack_pub = self.create_publisher(JointState,'ex_000/flag/stack',100)
        self.bit_on_ex = self.create_publisher(DumpCNP,'ex_000/bit_on_ex',100)
        # Server Publishers
        self.dump_info_pub = self.create_publisher(DumpInfoForServer,'dump_info_for_server',10)

        # Timers
        timer_period = 0.01  
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        
        # Subscribers
        self.subscription = self.create_subscription(Pose, 'du_012/pose',  self.subsc_callback, 10)
        self.subscription_012 = self.create_subscription(Pose, 'du_012/pose',  self.subsc_callback_012, 10)
        self.vessel_angle_sub = self.create_subscription(Float32,'du_012/vessel_angle',self.vessel_angle_callback,10)
        # Excavator Subscribers
        self.receive_request_from_ex = self.create_subscription(Bool,'du_012/request_from_ex', self.receive_request_from_ex_callback, 10)
        self.accept_request_from_ex = self.create_subscription(ExPosAndTeamNumber,'du_012/flag/startup', self.accept_request_from_ex_callback, 10)
        self.flag_work_finish_sub = self.create_subscription(Bool,'ex_000/flag/work/finish', self.flag_work_finish_callback, 10)
        self.flag_work_entry_sub = self.create_subscription(Bool,'ex_000/flag/work/entry',self.flag_work_entry_callback, 10)
        self.flag_dump_site_entry_sub = self.create_subscription(Bool,'ex_000/flag/dump_site/entry',self.flag_dump_site_entry_callback,10)
        self.flag_stack_sub = self.create_subscription(JointState,'du_012/flag/stack',self.flag_stack_callback, 10)
        self.flag_task_complete_sub = self.create_subscription(Bool,'ex_000/flag/task_complete',self.flag_task_complete_callback, 10)

    def timer_callback(self):
        twist_tmp = Twist()
        cmd_joint_tmp = JointState()
        vessel_angular_velocity_tmp = Float32()
        flag_work_start_tmp = Bool()
        flag_work_arrival_tmp = Int16()
        flag_stack_tmp = JointState()
        flag_dump_site_arrival_tmp = Int16()
        flag_dump_site_finished_tmp = Bool()
        
        ### initial value
        twist_tmp.linear.x = 0.0 # target speed
        twist_tmp.angular.z = 0.0 # target angle
        twist_tmp.angular.x = self.turtlePos[2] # theta
        piston1 = 0.0
        piston2 = 0.0

        ### self.waypoint_list point decition
        start = (self.turtlePos[0], self.turtlePos[1])
        # self.waypoint_list = [(0.0, -35.0),(10.0, -55.0),(15.0,-35.0),(-55.0,-55.0),(-65.0,-35.0),(-70.0,-55.0)]
        # self.waypoint_list = [(0.0, -45.0),(10.0, -25.0),(15.0,-45.0),(-55.0,-25.0),(-65.0,-45.0),(-70.0,-25.0)]
        #self.waypoint_list = [(-20.0, -35.0),(-10.0, -55.0),(-5.0,-35.0),(-135.0,-55.0),(-145.0,-35.0),(-150.0,-55.0)]
        # self.waypoint_list = [(0.0, -55.0),(10.0, -35.0),(15.0,-55.0),(-35.0,-35.0),(-45.0,-55.0),(-50.0,-35.0)]
        # self.waypoint_list = [(0.0, -55.0),(10.0, -35.0),(15.0,-55.0),(-20.0,-35.0),(-30.0,-55.0),(-55.0,-35.0)]

        # print(self.state)

        if self.state == 0:
            self.waypoint = 0
            twist_tmp.linear.x = 10.0 * self.healty

            if math.hypot(self.turtlePos[0] - self.waypoint_list[self.waypoint][0],self.turtlePos[1] - self.waypoint_list[self.waypoint][1]) < 3:
                self.work_entry_flag = False
                self.state = 1
                self.count = 0

        elif self.state == 1:
            self.waypoint = 1
            twist_tmp.linear.x = 0.0

            flag_work_arrival_tmp.data = self.ID
            self.flag_work_arrival_pub.publish(flag_work_arrival_tmp)

            if self.work_entry_flag:
                self.state = 2
                self.count = 0
        
        elif self.state == 2:
            self.waypoint = 1
            twist_tmp.linear.x = 5.0 * self.healty

            if math.hypot(self.turtlePos[0] - self.waypoint_list[self.waypoint][0],self.turtlePos[1] - self.waypoint_list[self.waypoint][1]) < 3:
                self.state = 3
                self.count = 0
        
        elif self.state == 3:
            self.waypoint = 2
            twist_tmp.linear.x = -5.0 * self.healty

            if math.hypot(self.turtlePos[0] - self.waypoint_list[self.waypoint][0],self.turtlePos[1] - self.waypoint_list[self.waypoint][1]) < 3:
                flag_work_start_tmp.data = True
                self.flag_work_start_pub.publish(flag_work_start_tmp)
                self.work_finish_flag = False
                self.state = 4
                self.count = 0
        
        elif self.state == 4:
            self.waypoint = 3
            twist_tmp.linear.x = 0.0

            if self.work_finish_flag == True:
                self.state = 5
                self.count = 0
                self.sand_loading_flag = True
            elif self.task_complete_flag == True:
                self.state = 5
                self.count = 0
                self.sand_loading_flag = False
        
        elif self.state == 5:
            self.waypoint = 3
            twist_tmp.linear.x = 10.0 * self.healty

            if math.hypot(self.turtlePos[0] - self.waypoint_list[self.waypoint][0],self.turtlePos[1] - self.waypoint_list[self.waypoint][1]) < 5:
                self.dump_site_entry_flag = False
                self.state = 11
                self.count = 0
        
        elif self.state == 11:
            self.waypoint = 4
            twist_tmp.linear.x = 0.0

            flag_dump_site_arrival_tmp.data = self.ID
            self.flag_dump_site_arrival_pub.publish(flag_dump_site_arrival_tmp)

            if self.dump_site_entry_flag:
                time.sleep(3)
                if self.sand_loading_flag == True:
                    self.state = 6
                    self.count = 0
                else:
                    self.state = 10
                    self.count = 0

        elif self.state == 6:
            self.waypoint = 4
            twist_tmp.linear.x = 5.0 * self.healty

            if math.hypot(self.turtlePos[0] - self.waypoint_list[self.waypoint][0],self.turtlePos[1] - self.waypoint_list[self.waypoint][1]) < 3:
                self.state = 7
                self.count = 0
        
        elif self.state == 7:
            self.waypoint = 5
            twist_tmp.linear.x = -5.0 * self.healty

            if math.hypot(self.turtlePos[0] - self.waypoint_list[self.waypoint][0],self.turtlePos[1] - self.waypoint_list[self.waypoint][1]) < 3:
                self.state = 8
                self.count = 0

        elif self.state == 8: # throw up
            self.waypoint = 0
            twist_tmp.linear.x = 0.0

            vessel_angular_velocity_tmp.data = Vessel_up_angular_velocity
            if self.current_vessel_angle_rad < -1.57:
                vessel_angular_velocity_tmp.data = 0.0
                self.throw_away_count += 1
                if self.throw_away_count > 300:
                    self.throw_away_count = 0
                    self.state = 9
        
        elif self.state == 9:
            self.waypoint = 0
            twist_tmp.linear.x = 0.0

            vessel_angular_velocity_tmp.data = Vessel_down_angular_velocity
            if self.current_vessel_angle_rad >= 0.0:
                vessel_angular_velocity_tmp.data = 0.0
                self.throw_away_count += 1
                if self.throw_away_count > 100:
                    self.throw_away_count = 0
                    flag_dump_site_finished_tmp.data = True
                    self.flag_dump_site_finished_pub.publish(flag_dump_site_finished_tmp)
                    self.sand_loading_flag = False
                    if self.task_complete_flag == True:
                        self.state = 10
                    else:
                        self.state = 0
        
        elif self.state == 10:
            self.waypoint = 6
            twist_tmp.linear.x = 5.0 * self.healty

            if math.hypot(self.turtlePos[0] - self.waypoint_list[self.waypoint][0],self.turtlePos[1] - self.waypoint_list[self.waypoint][1]) < 3:
                self.state = -1
                self.count = 0
                self.dump_ID_and_team_number.team = 0
                self.dump_info_pub.publish(self.dump_ID_and_team_number)

        if self.state != -1:        

            ### a_star algorithm
            if self.count % 20 == 0.0:
                # obstacle_x = self.turtlePos_012[0]
                # obstacle_y = self.turtlePos_012[1]
                self.path = astar(self.obstacle_x, self.obstacle_y, start, self.waypoint_list[self.waypoint])
                self.target_index = None

            if self.path is not None:
                self.old_path = self.path
                self.count = self.count + 1.0
            elif self.path is None:
                self.path = self.old_path
                # self.get_logger().info("failed to generate a route!!")

            ### pure_pursuit algorithm
            if self.path is not None:
                pure_pursuit_target_angle,self.target_index = pure_pursuit_method(self.path,self.turtlePos,self.target_index,twist_tmp.linear.x)
                twist_tmp.angular.z = pure_pursuit_target_angle


        # stack
        if math.hypot(self.turtlePos[0] - (hole[0]),self.turtlePos[1] - (hole[1])) < 3:
            twist_tmp.linear.x = 0.0
            if self.stack_count == 0:
                flag_stack_tmp.name = ['x', 'y']
                flag_stack_tmp.position = [self.turtlePos[0],self.turtlePos[1]]
                self.flag_stack_pub.publish(flag_stack_tmp)
                self.stack_count = 1
                self.dump_ID_and_team_number.team = -1
                self.dump_info_pub.publish(self.dump_ID_and_team_number)
            
        if self.stack_count != 0:
            twist_tmp.linear.x = 0.0
        
        
        ### define piston
        cmd_joint_tmp.name = ['piston1', 'piston2']
        cmd_joint_tmp.position = [piston1, piston2]

        ### publish imfomation
        self.twist_pub.publish(twist_tmp)
        self.vessel_angular_velocity_pub.publish(vessel_angular_velocity_tmp)
        self.cmd_joint_pub.publish(cmd_joint_tmp)
    
    def subsc_callback(self, pose):        
        self.turtlePos[0] = pose.x
        self.turtlePos[1] = pose.y
        self.turtlePos[2] = pose.theta  # degree !!!
        #print(pose.x)

    def vessel_angle_callback(self,angle):
        self.current_vessel_angle_rad = angle.data
        # print(self.current_vessel_angle_rad)

    def subsc_callback_012(self, pose):      
        self.turtlePos_012[0] = pose.x
        self.turtlePos_012[1] = pose.y
        self.turtlePos_012[2] = pose.theta     
       # self.obstacle.append((self.turtlePos_012[0],self.turtlePos_012[1]))

    def accept_request_from_ex_callback(self,ex_pos_team_number):
        self.get_logger().info("accept!")
        self.state = 0
        self.dump_ID_and_team_number.team = ex_pos_team_number.team
        self.dump_info_pub.publish(self.dump_ID_and_team_number)

        self.waypoint_list = decide_waypoint_from_team_number(ex_pos_team_number,self.initial_pos)
        self.get_logger().info(f"{self.waypoint_list}")


    def receive_request_from_ex_callback(self, request):
        self.get_logger().info("receive_request_from_ex")
        if request.data == True:
            self.dump_info.position.x = self.turtlePos[0]
            self.dump_info.position.y = self.turtlePos[1]
            self.dump_info.position.z = 0.0 #

            self.bit_on_ex.publish(self.dump_info)
            if self.subsc_count == 0:
                self.initial_pos[0] = self.turtlePos[0]
                self.initial_pos[1] = self.turtlePos[1]
                self.initial_pos[2] = self.turtlePos[2]
                self.subsc_count = 1

    def flag_work_finish_callback(self,flag):
        self.work_finish_flag = flag.data

    def flag_work_entry_callback(self,flag):
        self.work_entry_flag = flag.data
    
    def flag_dump_site_entry_callback(self,flag):
        self.dump_site_entry_flag = True
    
    def flag_stack_callback(self,joint_tmp):
        self.obstacle_x = joint_tmp.position[0]
        self.obstacle_y = joint_tmp.position[1]
    
    def flag_task_complete_callback(self,flag):
        self.task_complete_flag = flag.data
    
def main():
    rclpy.init(args=sys.argv)
    
    pubsub = MinimalPubSubCont()
    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()