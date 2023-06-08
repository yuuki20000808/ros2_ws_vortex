# Execute sample
# source install/setup.bash && source install/local_setup.bash
# ros2 launch six_team_du_stuck multi_du_udpcomm_02.launch.py
import launch
import launch_ros.actions


def generate_launch_description():
    du_communication_010 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_010')
    du_controller_010 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_010')
    du_communication_011 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_011')
    du_controller_011 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_011')
    du_communication_012 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_012')
    du_controller_012 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_012')
    du_communication_013 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_013')
    du_controller_013 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_013')
    du_communication_014 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_014')
    du_controller_014 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_014')
    du_communication_015 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_015')
    du_controller_015 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_015')
    du_communication_016 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_016')
    du_controller_016 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_016')
    du_communication_017 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_017')
    du_controller_017 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_017')
    du_communication_018 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_018')
    du_controller_018 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_018')
    du_communication_019 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_019')
    du_controller_019 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_019')
    du_communication_020 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_020')
    du_controller_020 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_020')
    du_communication_021 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_021')
    du_controller_021 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_021')
    du_communication_022 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_022')
    du_controller_022 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_022')
    du_communication_023 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_023')
    du_controller_023 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_023')
    du_communication_024 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_024')
    du_controller_024 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_024')
    du_communication_025 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_025')
    du_controller_025 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_025')
    du_communication_026 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_026')
    du_controller_026 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_026')
    du_communication_027 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_027')
    du_controller_027 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_027')
    du_communication_028 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_028')
    du_controller_028 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_028')
    du_communication_029 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_029')
    du_controller_029 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_029')
    
        
    '''
    du_communication_080 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_communication_080')
    du_controller_080 = launch_ros.actions.Node(
        package='six_team_du_stuck', executable='du_controller_080')
    '''
    

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
        du_communication_015,
        du_controller_015,
        du_communication_016,
        du_controller_016,
        du_communication_017,
        du_controller_017,
        du_communication_018,
        du_controller_018,
        du_communication_019,
        du_controller_019,
        du_communication_020,
        du_controller_020,
        du_communication_021,
        du_controller_021,
        du_communication_022,
        du_controller_022,
        du_communication_023,
        du_controller_023,
        du_communication_024,
        du_controller_024,
        du_communication_025,
        du_controller_025,
        du_communication_026,
        du_controller_026,
        du_communication_027,
        du_controller_027,
        du_communication_028,
        du_controller_028,
        du_communication_029,
        du_controller_029
    ])
