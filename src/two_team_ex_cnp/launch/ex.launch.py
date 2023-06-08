# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 launch two_team_ex_cnp multi_du_udpcomm_02.launch.py
import launch
import launch_ros.actions


def generate_launch_description():
    dump_info_server =  launch_ros.actions.Node(
        package='two_team_ex_cnp', executable='dump_info_server')
    ex_communication_000 = launch_ros.actions.Node(
        package='two_team_ex_cnp', executable='ex_communication_000')
    ex_controller_000 = launch_ros.actions.Node(
        package='two_team_ex_cnp', executable='ex_controller_000')
    ex_communication_003 = launch_ros.actions.Node(
        package='two_team_ex_cnp', executable='ex_communication_003')
    ex_controller_003 = launch_ros.actions.Node(
        package='two_team_ex_cnp', executable='ex_controller_003')
    # ex_communication_004 = launch_ros.actions.Node(
    #     package='two_team_ex_cnp', executable='ex_communication_004')
    # ex_controller_004 = launch_ros.actions.Node(
    #     package='two_team_ex_cnp', executable='ex_controller_004')
    

    return launch.LaunchDescription([
        dump_info_server,
        ex_communication_000,
        ex_controller_000,
        ex_communication_003,
        ex_controller_003
    ])
