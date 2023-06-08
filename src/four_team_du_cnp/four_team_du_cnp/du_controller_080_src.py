# from dump_messages.srv import AddThreeInts     # CHANGE

# import rclpy
# from rclpy.node import Node


# class MinimalService(Node):

#     def __init__(self):
#         super().__init__('minimal_service')
#         self.srv = self.create_service(AddThreeInts, 'add_three_ints', self.add_three_ints_callback)        # CHANGE

#     def add_three_ints_callback(self, request, response):
#         response.sum = request.a + request.b + request.c                                                  # CHANGE
#         self.get_logger().info('Incoming request\na: %d b: %d c: %d' % (request.a, request.b, request.c)) # CHANGE

#         return response

# def main(args=None):
#     rclpy.init(args=args)

#     minimal_service = MinimalService()

#     rclpy.spin(minimal_service)

#     rclpy.shutdown()

# if __name__ == '__main__':
#     main()


# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 run multi_du_udpcomm_02_pkg du_controller_080 --ros-args --params-file src/multi_du_udpcomm_02_pkg/config/params_080.yaml

#!/usr/bin/env python3
import rclpy
import sys
import time

from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from std_msgs.msg import String
from std_msgs.msg import Bool
from sensor_msgs.msg import JointState

from dump_messages.srv import Dumpbool
from std_srvs.srv import SetBool

class MinimalPubSubCont(Node):
    turtlePos = [0.0, 0.0, 0.0]
    x_maps = [-65.0, 65.0]
    y_maps = [-20.0, 20.0]
    mode = 0.0
    count = 0
    
    def __init__(self):   
        # Initialization
        super().__init__('du_controller_080') #node name
                      
        # Publishers
        self.twist_pub = self.create_publisher(Twist, 'du_080/cmd_vel', 100)
        self.cmd_joint_pub = self.create_publisher(JointState, 'du_080/cmd_joint', 100)
        self.test_pub = self.create_publisher(Bool,'test_communication',100)
                
        # Timers
        timer_period = 0.1  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)    
        
        # Subscribers
        self.subscription = self.create_subscription(Pose, 'du_080/pose',  self.subsc_callback, 10)

        # Service
        self.cli = self.create_client(SetBool,'bool_test')
        self.req = SetBool.Request()

    def timer_callback(self):
        twist_tmp = Twist()
        cmd_joint_tmp = JointState()
        test_tmp = Bool()
        
        piston1 = 0.0
        piston2 = 0.0
                
        # initial value
        twist_tmp.linear.x = 0.0 # target speed
        twist_tmp.angular.z = 0.0 # target angle

        # time.sleep(5)

        # if self.count < 0:
        #     test_tmp.data = True
        #     self.test_pub.publish(test_tmp)
        #     self.count += 1
        #     print('ready')
        #     self.re_test_sub = self.create_subscription(Bool,'re_test_communication',self.re_test_callback,100)
                
        
        self.send_request()
        # rclpy.spin_until_future_complete(self,future)
        #if future.done():
        response = self.future.result()
        # print(response.bit)

        # response = self.future.result()
        print(response.message)
        
        '''
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

                    twist_tmp.angular.z = -5.0
        if self.mode == 0.0:
            twist_tmp.linear.x = 0.0
            twist_tmp.angular.z = 0.0
        '''
            
        cmd_joint_tmp.name = ['piston1', 'piston2']
        cmd_joint_tmp.position = [piston1, piston2]
                 
        self.twist_pub.publish(twist_tmp)
        self.cmd_joint_pub.publish(cmd_joint_tmp)

    def send_request(self):
        print("a")
        self.req.data = True
        self.future = self.cli.call_async(self.req)
        #time.sleep(1)
        rclpy.spin_until_future_complete(self, self.future)
        
    
    def subsc_callback(self, pose):        
        self.turtlePos[0] = pose.x
        self.turtlePos[1] = pose.y
        self.turtlePos[2] = pose.theta       
        #print(pose.x)
    
    def re_test_callback(self,flag):
        if flag.data == True:
            print('clear')

    
def main():
    rclpy.init(args=sys.argv)
    
    pubsub = MinimalPubSubCont()
    # pubsub.send_request()

    # while rclpy.ok():
    #     rclpy.spin_once(pubsub)
    #     if pubsub.future.done():
    #         response = pubsub.future.result()
    #         print(response.bit)
    #         break


    rclpy.spin(pubsub)

    pubsub.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
