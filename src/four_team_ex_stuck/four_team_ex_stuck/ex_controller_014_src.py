# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run single_ex_sim_pkg ex_controller_004

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

from std_msgs.msg import Float32
from std_msgs.msg import Int16
from std_msgs.msg import Bool


mode = 0
state = 0
ko_state = 0

global status_boom, status_swing, status_arm, status_bucket

class MinimalPubSubCont(Node):

    sand = 5000.0
    deadline = 500.0
    finish_time = 1000.0

    swing_diff_target = 30.0

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

    dump_list = []
    time_list = []
    sand_list = []
    dug_sand_list = []
    dump_ID_list = [18,19,20]

    start_time = time.time()
    interval_time = 0

    time_record = []
    sand_record = []
    pre_record = []
    real_record = []

    work_flag = False
    arrival_flag = False
    request_flag = False
    performance_flag = False

    i = 0

    def __init__(self):   
        # Initialization
        super().__init__('ex_controller_004') #node name
               
        # Publishers
        self.cmd_vel_pub = self.create_publisher(Twist, 'ex_004/cmd/body/vel', 100)
        self.cmd_swing_ang_pub = self.create_publisher(Float32, 'ex_004/cmd/swing/ang', 100)
        self.cmd_boom_ang_pub = self.create_publisher(Float32, 'ex_004/cmd/boom/ang', 100)
        self.cmd_arm_ang_pub = self.create_publisher(Float32, 'ex_004/cmd/arm/ang', 100)
        self.cmd_bucket_ang_pub = self.create_publisher(Float32, 'ex_004/cmd/bucket/ang', 100)
        # Dump Publishers
        self.flag_work_entry_pub = self.create_publisher(Bool,'ex_004/flag/work/entry',100)
        self.flag_work_finish_pub = self.create_publisher(Bool,'ex_004/flag/work/finish',100)
               
        # Joy Subscribers
        self.status_joint_sub = self.create_subscription(JointState, 'ex_004/status/joint/ang',  self.status_joint_callback, 10)
        self.cmd_joy_sub = self.create_subscription(Joy, 'ex_000/cmd/joy',  self.cmd_joy_callback, 10)
        self.ex_soilmass_sub = self.create_subscription(Float32, 'ex_004/soilmass', self.ex_soilmass_callback, 100)
        # Dump Subscrivers
        self.flag_work_arrival_sub = self.create_subscription(Int16,'ex_004/flag/work/arrival',self.flag_work_arrival_callback,10)
        self.flag_work_start_sub = self.create_subscription(Bool,'ex_004/flag/work/start',self.flag_work_callback,10)
        self.flag_stack_sub = self.create_subscription(JointState,'ex_004/flag/stack',self.flag_stack_callback,10)

        # decide dump units
        while self.finish_time > self.deadline:
            self.add_units += 1
            self.pre_performance = (self.ave_sand * self.add_units)/(self.distance*2 / self.dumpspeed + self.loading_time + self.mounding_time)
            self.finish_time = self.sand / self.pre_performance
            self.request_flag = True
        print("add_units:",self.add_units)
        print("predict performance:",self.pre_performance)
        print("finish_time:",self.finish_time)


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

            if self.arrival_flag:

                # print("state:", state, ko_state)        

                if state == 0:
                    arm_target = -25

                    if status_arm >= arm_target:
                        arm = -3.0
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
                    swing_target = -75

                    if status_swing >= swing_target:
                        swing = -2.0
                    elif status_swing < swing_target:
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
                        self.swing_diff_target -= 5.0
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
            
        
            if self.performance_flag:

                if arrival_dump in self.dump_list:
                    list_index = self.dump_list.index(arrival_dump)
                    self.real_performance = (self.sand_list[list_index] - self.sand) / (time.time() - self.time_list[list_index])
                    self.finish_time = self.sand / self.real_performance
                    print('time:',time.time() - self.start_time)
                    print("real performance:",self.real_performance)
                    print("pre finish time:",(time.time() - self.start_time) + self.finish_time)
                    
                    while (time.time() - self.start_time) + self.finish_time > self.deadline:
                        self.add_units += 1
                        re_real_performance = self.real_performance / len(self.dump_list) * (len(self.dump_list) + self.add_units)
                        self.finish_time = self.sand / re_real_performance
                        self.request_flag = True
                    
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

                if time.time() - self.interval_time > 40.0: # original 22.0

                    try:
                        self.request_units += 1
                        self.interval_time = time.time()
                        dump_topic = 'du_0{}/flag/startup'.format(self.dump_ID_list[self.units + self.request_units - 1])
                        flag_startup_pub = self.create_publisher(Bool,dump_topic,10)
                        flag_startup_tmp = Bool()
                        flag_startup_tmp.data = True
                        flag_startup_pub.publish(flag_startup_tmp)
                    except IndexError:
                        print("Not enough dumps!")

                    if self.request_units == self.add_units:
                        self.units += self.add_units
                        self.add_units = 0
                        self.request_units = 0
                        self.interval_time = 0
                        self.request_flag = False
                        print("new units:",self.units)

            # if self.request_flag:

            #     for i in range(self.units,(self.units + self.add_units)):
            #         try:
            #             test = 'du_0{}/flag/startup'.format(self.dump_ID_list[i])
            #             flag_startup_pub = self.create_publisher(Bool,test,10)
            #             flag_startup_tmp = Bool()
            #             flag_startup_tmp.data = True
            #             flag_startup_pub.publish(flag_startup_tmp)
            #         except IndexError:
            #             print("Not enough dumps!")

            #     self.units += self.add_units
            #     self.add_units = 0
            #     self.request_flag = False
            #     print("new units:",self.units)


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
