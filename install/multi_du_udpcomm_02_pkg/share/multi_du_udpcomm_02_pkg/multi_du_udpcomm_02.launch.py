# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 launch multi_du_udpcomm_02_pkg multi_du_udpcomm_02.launch.py
import launch
import launch_ros.actions


def generate_launch_description():
    du_communication_010 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_communication_010')
    du_controller_010 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_controller_010')
    du_communication_011 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_communication_011')
    du_controller_011 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_controller_011')
    du_communication_012 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_communication_012')
    du_controller_012 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_controller_012')
    du_communication_013 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_communication_013')
    du_controller_013 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_controller_013')
    du_communication_014 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_communication_014')
    du_controller_014 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_controller_014')
    du_communication_080 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_communication_080')
    du_controller_080 = launch_ros.actions.Node(
        package='multi_du_udpcomm_02_pkg', executable='du_controller_080')
    

    return launch.LaunchDescription([
        du_communication_010,
        du_controller_010,
        du_communication_011,
        du_controller_011,
        du_communication_012,
        du_controller_012,   
        du_communication_013,
        du_controller_013,
        du_communication_014,
        du_controller_014,
        du_communication_080,
        du_controller_080,     
    ])
