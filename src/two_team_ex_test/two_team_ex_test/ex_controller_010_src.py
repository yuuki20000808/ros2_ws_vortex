# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run single_ex_sim_pkg ex_controller_000

#!/usr/bin/env python3
import rclpy
import sys
import time
import math

from rclpy.node import Node
from geometry_msgs.msg import Twist

from turtlesim.msg import Pose
from sensor_msgs.msg import Joy
from sensor_msgs.msg import JointState
from std_msgs.msg import Int64MultiArray

from std_msgs.msg import Float32
from std_msgs.msg import Int16
from std_msgs.msg import Bool
from dump_messages.msg import DumpCNP
from dump_messages.msg import ExPosAndTeamNumber

from two_team_ex_test.a_star import astar
from two_team_ex_test.pure_pursuit import pure_pursuit_method
import numpy as np


state = 0
ko_state = 0



global status_boom, status_swing, status_arm, status_bucket

def sort_DumpCNP_by_distance(DumpCNP_list,current_pos):
    sorted_list = sorted(DumpCNP_list, key=lambda dump_pos: math.hypot(dump_pos.position.x - current_pos[0], dump_pos.position.y - current_pos[1]))
    return sorted_list

class MinimalPubSubCont(Node):

    turtlePos = [0.0, 0.0, 0.0]
    sand = 1700.0
    deadline = 400.0
    finish_time = 1000.0

    swing_diff_target = -30.0

    ex_team_number = 1

    loading_time = 40.0
    mounding_time = 10.0
    distance = 740.0
    dumpspeed = 10.0
    ave_sand = 750.0
    units = 0
    add_units = 0
    request_units = 0
    pre_performance = 0.0
    real_performance = 0.0

    state_pp = 0#-1
    healty = 1.0
    count = 0.0
    mode = 0

    obstacle_x = -1000.0
    obstacle_y = -1000.0

    path = []
    old_path = None
    target_index = None

    dump_list = []
    time_list = []
    sand_list = []
    dug_sand_list = []
    dump_ID_list = []

    dump_CNP_list = []
    sorted_dump_list = []
    initial_dump_list = []

    start_time = time.time()
    interval_time = 0

    time_record = []
    sand_record = []
    pre_record = []
    real_record = []

    task_flag = False
    work_flag = False
    arrival_flag = False
    dump_site_flag = False
    request_flag = False
    performance_flag = False

    request_to_server = Bool()
    reqeust_all_dump_team_list_flag = Bool()
    ex_pos_team_number = ExPosAndTeamNumber()

    i = 0
    initial_pos = [0.0, 0.0, 0.0]
    loop_count = 0



    def __init__(self):   
        # Initialization
        super().__init__('ex_controller_000') #node name
        num = '000'
        # Publishers
        self.cmd_vel_pub = self.create_publisher(Twist, f'ex_{num}/cmd/body/vel', 100)
        self.cmd_ang_pub = self.create_publisher(Twist, 'ex_000/cmd/ang/vel', 100)
        self.cmd_swing_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/swing/ang', 100)
        self.cmd_boom_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/boom/ang', 100)
        self.cmd_arm_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/arm/ang', 100)
        self.cmd_bucket_ang_pub = self.create_publisher(Float32, 'ex_000/cmd/bucket/ang', 100)
        self.twist_pub = self.create_publisher(Twist, 'ex_000/cmd_vel', 100)
        # Dump Publishers
        self.flag_work_entry_pub = self.create_publisher(Bool,'ex_000/flag/work/entry',100)
        self.flag_dump_site_entry_pub = self.create_publisher(Bool,'ex_000/flag/dump_site/entry',100)
        self.flag_work_finish_pub = self.create_publisher(Bool,'ex_000/flag/work/finish',100)
        self.flag_task_complete_pub = self.create_publisher(Bool,'ex_000/flag/task_complete',100)
        # Server Publishers
        self.request_from_ex = self.create_publisher(Bool,'request_from_ex',100)
        self.reqeust_all_dump_team_list = self.create_publisher(Bool, 'reqeust_all_dump_team_list',10)
        
               
        # Joy Subscribers
        self.status_joint_sub = self.create_subscription(JointState, 'ex_000/status/joint/ang',  self.status_joint_callback, 10)
        self.cmd_joy_sub = self.create_subscription(Joy, 'ex_000/cmd/joy',  self.cmd_joy_callback, 10)
        self.ex_soilmass_sub = self.create_subscription(Float32, 'ex_000/soilmass', self.ex_soilmass_callback, 100)
        self.subscription_ex = self.create_subscription(Pose, 'ex_000/pose',  self.subsc_callback_ex, 10)
        # Dump Subscrivers
        self.flag_work_arrival_sub = self.create_subscription(Int16,'ex_000/flag/work/arrival',self.flag_work_arrival_callback,10)
        self.flag_work_start_sub = self.create_subscription(Bool,'ex_000/flag/work/start',self.flag_work_callback,10)
        self.flag_dump_site_arrival_sub = self.create_subscription(Int16,'ex_000/flag/dump_site/arrival',self.flag_dump_site_arrival_callback,10)
        self.flag_dump_site_finished_sub = self.create_subscription(Bool,'ex_000/flag/dump_site/finished',self.flag_dump_site_finished_callback,100)
        self.flag_stack_sub = self.create_subscription(JointState,'ex_000/flag/stack',self.flag_stack_callback,10)
        self.bit_from_dump = self.create_subscription(DumpCNP,'ex_000/bit_on_ex',self.bit_from_dump,10)
        # Server Subscrivers
        self.response_from_server = self.create_subscription(Int64MultiArray, 'response_from_server',self.response_from_server_callback,10)
        self.all_dump_team_list_from_server = self.create_subscription(Int64MultiArray, 'all_dump_team_list_from_server', self.all_dump_team_list_from_server_callback ,10)

        # decide dump units
        while self.finish_time > self.deadline:
            self.add_units += 1
            self.pre_performance = (self.ave_sand * self.add_units)/(self.distance*2 / self.dumpspeed + self.loading_time + self.mounding_time)
            self.finish_time = self.sand / self.pre_performance   

        #  self.add_units = 3

        print("add_units:",self.add_units)
        print("predict performance:",self.pre_performance)
        print("finish_time:",self.finish_time)
    

    def bit_from_dump(self, DumpCNP):
        if len(self.dump_CNP_list) < len(self.dump_ID_list): # change the dump_ID_list to idle dump id list in the future
            self.dump_CNP_list.append(DumpCNP)
        if len(self.dump_CNP_list) == len(self.dump_ID_list):
            self.sorted_dump_list = sort_DumpCNP_by_distance(self.dump_CNP_list,self.turtlePos)
            self.request_flag = True
            self.dump_CNP_list = []
            print("finished sorting")
            print(self.sorted_dump_list)


    def status_joint_callback(self, joint_tmp):
        global status_boom, status_swing, status_arm, status_bucket
        status_swing = joint_tmp.position[0]
        status_boom = joint_tmp.position[1]
        status_arm = joint_tmp.position[2]
        status_bucket = joint_tmp.position[3]
        #self.i += 1
        #print("status arm: ", status_arm, "count: ", self.i)

    def ex_soilmass_callback(self, soilmass_tmp):
        global soilmass
        soilmass = soilmass_tmp.data

    def flag_work_arrival_callback(self,dump_ID):
        if self.arrival_flag == False:
            self.arrival_flag = True
            self.performance_flag = True

            global arrival_dump
            arrival_dump = dump_ID.data

            flag_work_entry_tmp = Bool()
            flag_work_entry_tmp.data = True
            self.flag_work_entry_pub.publish(flag_work_entry_tmp)
        else:
            pass

    def flag_dump_site_arrival_callback(self,dump_ID):
        if self.dump_site_flag == False:
            self.dump_site_flag = True

            flag_dump_site_entry_tmp = Bool()
            flag_dump_site_entry_tmp.data = True
            self.flag_dump_site_entry_pub.publish(flag_dump_site_entry_tmp)
        else:
            pass        

    def flag_dump_site_finished_callback(self,flag):
        self.dump_site_flag = False

    def flag_work_callback(self, work_flag_tmp):
        self.work_flag = work_flag_tmp.data

    def flag_stack_callback(self, joint_tmp):
        x = joint_tmp.position[0]
        y = joint_tmp.position[1]

        for i in self.dump_ID_list:
            test = 'du_0{}/flag/stack'.format(i)
            flag_stack_pub = self.create_publisher(JointState,test,10)
            flag_stack_tmp = JointState()
            flag_stack_tmp.name = ['x','y']
            flag_stack_tmp.position = [x,y]
            flag_stack_pub.publish(flag_stack_tmp)
        
    def subsc_callback_ex(self, pose):        
        self.turtlePos[0] = pose.x
        self.turtlePos[1] = pose.y
        self.turtlePos[2] = pose.theta  # degree !!!

    def response_from_server_callback(self,idle_list):
        self.dump_ID_list = idle_list.data

        if self.task_flag == True:
            # request for all dump
            # print(self.dump_ID_list[0])
            if len(self.initial_dump_list) == 0:
                self.initial_dump_list = idle_list.data
                print('initial_dump_list',self.initial_dump_list)
            for i in self.dump_ID_list:
                request_dump_topic = f'du_0{i}/request_from_ex'
                flag_request_pub = self.create_publisher(Bool,request_dump_topic,10)
                flag_request_tmp = Bool()
                flag_request_tmp.data = True
                flag_request_pub.publish(flag_request_tmp)
                print(request_dump_topic)
                time.sleep(0.3)


    def all_dump_team_list_from_server_callback(self, all_dump_team_list):
        if self.task_flag == False:
            if self.ex_team_number not in all_dump_team_list.data:
                self.mode = 5
                self.target_index = 0
                print('self.mode:', self.mode)

    def cmd_joy_callback(self, joy_tmp):

        crawler_vx = 0.0
        crawler_vy = 0.0
        swing = 0.0
        boom = 0.0 
        arm = 0.0
        bucket = 0.0

        target_vx = 0.0
        target_az = 0.0
        body_tx = 0.0
        body_tz = 0.0

        flag_work_arrival_tmp = Int16()

        global state, ko_state

        # self.mode change
        if joy_tmp.buttons[9] == 1:
            self.mode = 0
        elif joy_tmp.buttons[1] == 1:
            self.mode = 1
            print("mode change")
        
        # remote self.mode
        if self.mode == 0:

            #crawler_vx = joy_tmp.axes[6] # left and right
            crawler_vy = joy_tmp.axes[7] # up and  down
            target_az = joy_tmp.axes[6] * 100
            
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

        elif self.mode == 1:
            start = (self.turtlePos[0], self.turtlePos[1])
            goal = [(2.66, -4.56), (11.0, -2.0)]

            if self.loop_count == 0:
                self.initial_pos = [(self.turtlePos[0],self.turtlePos[1])]
                self.loop_count = 1

            if self.state_pp == 0:
                self.waypoint = 0
                #twist_tmp.linear.x = 10.0 * self.healty
                crawler_vy = 10.0 * self.healty

                if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 3:
                    self.state_pp = 1
                    self.count = 0

            elif self.state_pp == 1:
                self.waypoint = 1
                crawler_vy = 10.0 * self.healty

                if math.hypot(self.turtlePos[0] - goal[self.waypoint][0],self.turtlePos[1] - goal[self.waypoint][1]) < 3:
                    self.state_pp = 2
                    crawler_vy = 0.0 * self.healty

                    self.count = 0

            elif self.state_pp == 2:
                self.waypoint = 2
                crawler_vy = 0.0 * self.healty
                self.mode = 2


                

            ### a_star algorithm
            """
            if self.count % 20 == 0.0:
                # obstacle_x = self.turtlePos_012[0]
                # obstacle_y = self.turtlePos_012[1]
                self.path = astar(self.obstacle_x, self.obstacle_y, start, goal[self.waypoint])
                self.target_index = None
            """

            if self.path is not None:
                self.old_path = self.path
                self.count = self.count + 1.0
            elif self.path is None:
                self.path = self.old_path
                self.get_logger().info("failed to generate a route!!")

            ### pure_pursuit algorithm
            if self.path is not None:
                pure_pursuit_target_angle,self.target_index = pure_pursuit_method(goal,self.turtlePos,self.target_index,crawler_vy)
                #twist_tmp.angular.z = pure_pursuit_target_angle
                target_az = pure_pursuit_target_angle

            #print("*****", target_az)


        elif self.mode == 2:
            if self.turtlePos[2] < 30:
                target_az = 15.0
            else:
                target_az = 0.0
                self.ex_pos_team_number.pos.x = self.turtlePos[0]
                self.ex_pos_team_number.pos.y = self.turtlePos[1]
                self.ex_pos_team_number.pos.theta = self.turtlePos[2]

                # request to server
                self.task_flag = True
                self.request_to_server.data = True
                self.request_from_ex.publish(self.request_to_server)
                time.sleep(1)
                self.mode = 3
            
        # auto self.mode
        elif self.mode == 3:

            if self.arrival_flag:

                # print("state:", state, ko_state)        

                if state == 0:
                    arm_target = -25.0

                    if status_arm >= arm_target:
                        arm = -3.0

                    elif status_arm < arm_target:
                        arm = 0.0
                        ko_state = ko_state + 1       

                if state == 1:
                    swing_target = self.swing_diff_target

                    if status_swing >= swing_target:
                        swing = -2.0
                    elif status_swing < swing_target:
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
                    swing_target = 75

                    if status_swing <= swing_target:
                        swing = 2.0
                    elif status_swing > swing_target:
                        swing = 0.0
                        ko_state = ko_state + 1

                if state == 8 and self.work_flag == True:
                    bucket_target = 0

                    if status_bucket >= bucket_target:
                        bucket = -6.0
                    elif status_bucket < bucket_target:
                        bucket = 0.0
                        ko_state = ko_state + 1

                if ko_state == 10:
                    state = state + 1
                    ko_state = 0

                    if state == 1:
                        self.swing_diff_target += 5.0
                    elif state == 7:
                        self.sand -= soilmass
                        self.dug_sand_list.append(soilmass)
                        self.sand_record.append(self.sand)
                        self.time_record.append(time.time() - self.start_time)
                        if self.sand < 0.0:
                            print(self.sand_record)
                            print(self.time_record)
                    elif state == 9:
                        # send info to dump
                        time.sleep(4.0)
                        flag_work_finish_tmp = Bool()
                        flag_work_finish_tmp.data = True
                        self.flag_work_finish_pub.publish(flag_work_finish_tmp)
                        # Initialize
                        self.work_flag = False
                        self.arrival_flag = False
                        state = 0
                        if self.sand < 0:
                            print('Task finish')
                            flag_task_complete_tmp = Bool()
                            flag_task_complete_tmp.data = True
                            self.flag_task_complete_pub.publish(flag_task_complete_tmp)
                            self.task_flag = False
                            self.mode = 4
            
        
            if self.performance_flag:

                if arrival_dump in self.dump_list:
                    list_index = self.dump_list.index(arrival_dump)
                    self.real_performance = (self.sand_list[list_index] - self.sand) / (time.time() - self.time_list[list_index])
                    self.finish_time = self.sand / self.real_performance
                    print('time:',time.time() - self.start_time)
                    print("real performance:",self.real_performance)
                    print("pre finish time:",(time.time() - self.start_time) + self.finish_time)
                    # decide add_units
                    while (time.time() - self.start_time) + self.finish_time > self.deadline:
                        self.add_units += 1
                        re_real_performance = self.real_performance / len(self.dump_list) * (len(self.dump_list) + self.add_units)
                        self.finish_time = self.sand / re_real_performance
                        '''
                        self.request_flag = True
                        '''
                        
                    # request to server
                    if self.add_units > 0:
                        self.request_to_server.data = True
                        self.request_from_ex.publish(self.request_to_server)
                        time.sleep(1)
                    
                    self.pre_performance = (self.ave_sand + sum(self.dug_sand_list) / len(self.dug_sand_list)) / 2 * (len(self.dump_list) + self.add_units) / (time.time() - self.time_list[list_index])
                    
                    print("add_units:",self.add_units)
                    print("predict performance:",self.pre_performance)
                    print("pre finish time:",(time.time() - self.start_time) + self.finish_time)

                    self.dump_list = []
                    self.time_list = []
                    self.sand_list = []

                self.dump_list.append(arrival_dump)
                self.time_list.append(time.time())
                self.sand_list.append(self.sand)
                self.performance_flag = False
                # print(self.dump_list)
                # print(self.time_list)
                # print(self.sand_list)

            if self.request_flag:

                #call dumps in order of distace

                if time.time() - self.interval_time > 20.0: # original 22.0

                    try:
                        self.interval_time = time.time()
                        dump_topic = 'du_0{}/flag/startup'.format(self.sorted_dump_list[self.request_units].id) # attention!!!
                        print(dump_topic)
                        flag_startup_pub = self.create_publisher(ExPosAndTeamNumber,dump_topic,10)
                        self.ex_pos_team_number.team = self.ex_team_number
                        flag_startup_pub.publish(self.ex_pos_team_number)
                        self.request_units += 1
                    except IndexError:
                        print("Not enough dumps!")

                    if self.request_units == self.add_units:
                        self.units += self.add_units
                        self.add_units = 0
                        self.request_units = 0
                        self.interval_time = 0
                        self.request_flag = False
                        print("new units:",self.units)
        
        elif self.mode == 4:

            # request to server
            self.reqeust_all_dump_team_list_flag.data = True
            #self.request_from_ex.publish(self.request_to_server)
            self.reqeust_all_dump_team_list.publish(self.reqeust_all_dump_team_list_flag)
            time.sleep(0.1)

            swing_target = 0.0

            if status_swing >= swing_target:
                swing = -2.0
            elif status_swing < swing_target:
                swing = 0.0

        elif self.mode == 5:
            if self.turtlePos[2] > -150:
                target_az = -30.0
            else:
                self.mode = 6

        elif self.mode == 6:
            start = (self.turtlePos[0], self.turtlePos[1])
            crawler_vy = 10.0 * self.healty

            goal_route = [[-120.0,-40.0],[self.initial_pos[0][0],self.initial_pos[0][1]]]

            if math.hypot(self.turtlePos[0] - self.initial_pos[0][0],self.turtlePos[1] - self.initial_pos[0][1]) < 3:
                self.mode = 7
                self.count = 0
            
            ### pure_pursuit algorithm
            if self.path is not None:
                pure_pursuit_target_angle,self.target_index = pure_pursuit_method(goal_route,self.turtlePos,self.target_index,crawler_vy)
                #twist_tmp.angular.z = pure_pursuit_target_angle
                target_az = pure_pursuit_target_angle

        elif self.mode == 7:
            pass


            # if self.request_flag:

            #     for i in range(self.units,(self.units + self.add_units)):
            #         try:
            #             test = 'du_0{}/flag/startup'.format(self.dump_ID_list[i])
            #             flag_startup_pub = self.create_publisher(Bool,test,10)
            #             flag_startup_tmp = Bool()
            #             flag_startup_tmp.data = True
            #             flag_startup_pub.publish(flag_startup_tmp)
            #         except IndexError:
            #             prinflag_stack_callbackt("Not enough dumps!")

            #     self.units += self.add_units
            #     self.add_units = 0
            #     self.request_flag = False
            #     print("new units:",self.units)


        cmd_vel_tmp = Twist()
        #cmd_vel_tmp.linear.x = float(crawler_vx)
        #cmd_vel_tmp.linear.y = float(crawler_vy)
        cmd_vel_tmp.linear.x = float(crawler_vy)
        cmd_vel_tmp.linear.y = float(crawler_vx)

        cmd_ang_tmp = Twist()
        cmd_ang_tmp.angular.x = self.turtlePos[2] # theta
        cmd_ang_tmp.angular.z = target_az#float(body_tz)

        #koko_???
        twist_tmp = Twist()
        twist_tmp.linear.x = target_vx # target speed
        twist_tmp.angular.x = self.turtlePos[2] # theta
        twist_tmp.angular.z = target_az # target angle

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
        self.cmd_ang_pub.publish(cmd_ang_tmp)
        self.cmd_boom_ang_pub.publish(cmd_boom_ang_tmp)
        self.cmd_arm_ang_pub.publish(cmd_arm_ang_tmp)
        self.cmd_swing_ang_pub.publish(cmd_swing_ang_tmp)
        self.cmd_bucket_ang_pub.publish(cmd_bucket_ang_tmp)
        self.twist_pub.publish(twist_tmp)
    
def main():
    rclpy.init(args=sys.argv)
    
    pubsub = MinimalPubSubCont()
    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
