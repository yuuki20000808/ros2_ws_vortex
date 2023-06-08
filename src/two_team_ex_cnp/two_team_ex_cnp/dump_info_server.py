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

from dump_messages.msg import DumpCNP
from dump_messages.msg import DumpInfoForServer

class  MinimalPubSubCont(Node):

    dump_num = 6
    dump_id_list = []
    dump_team_list = []
    idle_dump_id_list = Int64MultiArray()


    def __init__(self):
        super().__init__('dump_info_server')

        # subscriber
        self.request_from_ex = self.create_subscription(Int16, 'request_from_ex', self.request_from_ex_callback, 10)
        self.dump_info_sub = self.create_subscription(DumpInfoForServer, 'dump_info_for_server', self.dump_info_sub_callback,10)
        self.all_dump_team_list_sub = self.create_subscription(Int16, 'reqeust_all_dump_team_list', self.all_dump_team_list_sub_callback,10)

        for i in range(self.dump_num):
            self.dump_id_list.append(i+10)
            self.dump_team_list.append(0)
            print(self.dump_team_list)
        self.idle_dump_id_list.data = self.dump_id_list

    def request_from_ex_callback(self, team_number):
        response_from_server = self.create_publisher(Int64MultiArray, f'ex_{team_number.data}/response_from_server', 10)
        response_from_server.publish(self.idle_dump_id_list)
        self.get_logger().info("idle dump list pub backhoe")
        self.get_logger().info(f"{self.idle_dump_id_list}")

    # update_team_number
    def dump_info_sub_callback(self, dump_info):
        index = self.dump_id_list.index(dump_info.id)
        self.dump_team_list[index] = dump_info.team

        print('dump_info.team: ', dump_info.team)

        self.idle_dump_id_list = Int64MultiArray()

        for i in range(len(self.dump_team_list)):
            if self.dump_team_list[i] == 0:
                self.idle_dump_id_list.data.append(self.dump_id_list[i])

        self.get_logger().info("idle dump list kousinn")
        self.get_logger().info(f"{self.idle_dump_id_list}")
    
    def all_dump_team_list_sub_callback(self, team_number):
        all_dump_team_list = Int64MultiArray()
        all_dump_team_list.data = self.dump_team_list
        all_dump_team_list_pub = self.create_publisher(Int64MultiArray, f'ex_{team_number.data}/all_dump_team_list_from_server', 10)
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