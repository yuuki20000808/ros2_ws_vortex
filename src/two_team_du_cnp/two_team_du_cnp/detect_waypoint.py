import numpy as np
from dump_messages.msg import DumpInfoForServer

def decide_waypoint_from_team_number(ex_pos_team_number,initial_pos):

    present_ex_pos = np.array([[ex_pos_team_number.pos.x], [ex_pos_team_number.pos.y]])
    ideal_ex_pos = [-9,-32]
    ideal_theta = 30.0
    ideal_waypoint = [[-20.0, -35.0],[-10.0, -55.0],[-5.0,-35.0]]
    dumpsite = ex_pos_team_number.dumpsite
    deviation_angle = ex_pos_team_number.pos.theta - ideal_theta # atention!!
    deviation_vector = present_ex_pos - np.array([[ideal_ex_pos[0]], [ideal_ex_pos[1]]])

    angle = np.radians(deviation_angle)
    routation_matrix = np.array([[np.cos(angle),-np.sin(angle)],[np.sin(angle),np.cos(angle)]])
    for i in range(3):
        column_vector = np.array([[ideal_waypoint[i][0]],[ideal_waypoint[i][1]]]) + deviation_vector
        vector_from_ex_to_waypint = column_vector - present_ex_pos
        routated_vector = np.dot(routation_matrix, vector_from_ex_to_waypint)
        waypoint = routated_vector + present_ex_pos
        ideal_waypoint[i][0] = waypoint[0, 0]
        ideal_waypoint[i][1] = waypoint[1, 0]
    
    # add dump site position
    ideal_dump_site = [[dumpsite[0]+15.0,dumpsite[1]+5.0],[dumpsite[0]+5.0,dumpsite[1]+25.0],[dumpsite[0],dumpsite[1]+5.0]]
    for i in range(len(ideal_dump_site)):
        ideal_waypoint.append(ideal_dump_site[i])

    # add base position
    ideal_waypoint.append(initial_pos)
        
    return ideal_waypoint