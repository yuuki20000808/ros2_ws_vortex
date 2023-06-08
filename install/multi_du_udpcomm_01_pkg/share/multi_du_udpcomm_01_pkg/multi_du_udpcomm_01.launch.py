# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 launch multi_du_udpcomm_02_pkg multi_du_udpcomm_02.launch.py
import launch
import launch_ros.actions


def generate_launch_description():
    du_communication_013 = launch_ros.actions.Node(
        package='multi_du_udpcomm_01_pkg', executable='du_communication_013')
    du_controller_013 = launch_ros.actions.Node(
        package='multi_du_udpcomm_01_pkg', executable='du_controller_013')
    du_communication_014 = launch_ros.actions.Node(
        package='multi_du_udpcomm_01_pkg', executable='du_communication_014')
    du_controller_014 = launch_ros.actions.Node(
        package='multi_du_udpcomm_01_pkg', executable='du_controller_014')
    du_communication_015 = launch_ros.actions.Node(
        package='multi_du_udpcomm_01_pkg', executable='du_communication_015')
    du_controller_015 = launch_ros.actions.Node(
        package='multi_du_udpcomm_01_pkg', executable='du_controller_015')
    

    return launch.LaunchDescription([
        du_communication_013,
        du_controller_013,
        du_communication_014,
        du_controller_014,
        du_communication_015,
        du_controller_015,        
    ])
