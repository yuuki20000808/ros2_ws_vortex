# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 launch four_team_ex_stuck multi_du_udpcomm_02.launch.py
import launch
import launch_ros.actions


def generate_launch_description():
    ex_communication_000 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_communication_000')
    ex_controller_000 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_controller_000')
    ex_communication_003 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_communication_003')
    ex_controller_003 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_controller_003')
    ex_communication_004 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_communication_004')
    ex_controller_004 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_controller_004')
    ex_communication_005 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_communication_005')
    ex_controller_005 = launch_ros.actions.Node(
        package='four_team_ex_stuck', executable='ex_controller_005')
    

    return launch.LaunchDescription([
        ex_communication_000,
        ex_controller_000,
        ex_communication_003,
        ex_controller_003,
        ex_communication_004,
        ex_controller_004,
        ex_communication_005,
        ex_controller_005
    ])
