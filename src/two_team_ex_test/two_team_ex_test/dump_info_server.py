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
from std_msgs.msg import Int64MultiArray

from two_team_du_test.a_star import astar
from two_team_du_test.pure_pursuit import pure_pursuit_method
from dump_messages.msg import DumpCNP
from dump_messages.msg import DumpInfoForServer

class  MinimalPubSubCont(Node):

    dump010_id = 10
    dump010_team = 0 # idle
    dump011_id = 11
    dump011_team = 0 # idle
    dump012_id = 12
    dump012_team = 0 # idle

    dump_id_list = [dump010_id, dump011_id, dump012_id]
    dump_team_list = [dump010_team, dump011_team, dump012_team]

    idle_dump_id_list = Int64MultiArray()
    idle_dump_id_list.data = dump_id_list


    def __init__(self):
        super().__init__('dump_info_server')
        # timer_period = 0.01  # seconds
        # self.timer = self.create_timer(timer_period, self.timer_callback)

        # publisher
        self.response_from_server = self.create_publisher(Int64MultiArray, 'response_from_server', 10)
        
        # subscriber
        self.request_from_ex = self.create_subscription(Bool, 'request_from_ex', self.request_from_ex_callback, 10)
        self.dump_info_sub = self.create_subscription(DumpInfoForServer, 'dump_info_for_server', self.dump_info_sub_callback,10)
        self.all_dump_team_list_sub = self.create_subscription(Bool, 'reqeust_all_dump_team_list', self.all_dump_team_list_sub_callback,10)
        

    def request_from_ex_callback(self, request):
        if request.data == True:
            self.response_from_server.publish(self.idle_dump_id_list)


    # update_team_number
    def dump_info_sub_callback(self, dump_info):
        index = self.dump_id_list.index(dump_info.id)
        self.dump_team_list[index] = dump_info.team

        print('dump_info.team: ', dump_info.team)

        self.idle_dump_id_list = Int64MultiArray()

        for i in range(len(self.dump_team_list)):
            if self.dump_team_list[i] == 0:
                self.idle_dump_id_list.data.append(self.dump_id_list[i])

        print(self.idle_dump_id_list)
    
    def all_dump_team_list_sub_callback(self, bool):
        all_dump_team_list = Int64MultiArray()
        all_dump_team_list.data = self.dump_team_list
        all_dump_team_list_pub = self.create_publisher(Int64MultiArray, 'all_dump_team_list_from_server', 10)
        all_dump_team_list_pub.publish(all_dump_team_list)


    '''
    def timer_callback(self):
        pass
    '''
        

def main():
    rclpy.init(args=sys.argv)

    pubsub = MinimalPubSubCont()
    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()