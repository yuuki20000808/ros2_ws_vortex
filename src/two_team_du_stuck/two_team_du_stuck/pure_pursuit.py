"""
Path tracking simulation with pure pursuit steering and PID speed control.
author: Atsushi Sakai (@Atsushi_twi)
        Guillaume Jacquenot (@Gjacquenot)
"""
import numpy as np
import math
import matplotlib.pyplot as plt

# Parameters
k = 0.1  # look forward gain
Lfc = 2.0  # [m] look-ahead distance
Kp = 1.0  # speed proportional gain　比例速度ゲイン
dt = 0.1  # [s] time tick
WB = 6.185  # [m] wheel base of vehicle  後輪と前輪の距離

# stop all animation-related
# show_animation = True


class State:

    def __init__(self, x=0.0, y=0.0, yaw=0.0, v=0.0):
        self.x = x
        self.y = y
        self.yaw = yaw  # 鉛直軸周りの回転
        self.v = v  
        self.rear_x = self.x - ((WB / 2) * math.cos(self.yaw))
        self.rear_y = self.y - ((WB / 2) * math.sin(self.yaw))

    # def update(self, a, delta):
    #     self.x += self.v * math.cos(self.yaw) * dt
    #     self.y += self.v * math.sin(self.yaw) * dt
    #     self.yaw += self.v / WB * math.tan(delta) * dt
    #     self.v += a * dt
    #     self.rear_x = self.x - ((WB / 2) * math.cos(self.yaw))
    #     self.rear_y = self.y - ((WB / 2) * math.sin(self.yaw))

    def calc_distance(self, point_x, point_y):
        dx = self.rear_x - point_x
        dy = self.rear_y - point_y
        return math.hypot(dx, dy)  # 各引数を2乗した総和の平方根を返すメソッド


class States:

    def __init__(self):
        self.x = []
        self.y = []
        self.yaw = []
        self.v = []
        self.t = []

    def append(self, state):
        self.x.append(state.x)
        self.y.append(state.y)
        self.yaw.append(state.yaw)
        self.v.append(state.v)


def proportional_control(target, current):  # 速度の比例制御
    a = Kp * (target - current)

    return a


class TargetCourse:

    def __init__(self, cx, cy):  # 初期化
        self.cx = cx
        self.cy = cy
        self.old_nearest_point_index = None

    def search_target_index(self, state):

        # To speed up nearest point search, doing it at only first time.
        if self.old_nearest_point_index is None:
            # search nearest point index
            dx = [state.rear_x - icx for icx in self.cx]
            dy = [state.rear_y - icy for icy in self.cy]
            d = np.hypot(dx, dy)
            ind = np.argmin(d)  # 配列の最小値のインデックスを取得
            self.old_nearest_point_index = ind
        else:
            ind = self.old_nearest_point_index
            distance_this_index = state.calc_distance(self.cx[ind],
                                                      self.cy[ind])
            while ind < len(self.cx) - 1:  # determine which is closer to the target point and the next point
                distance_next_index = state.calc_distance(self.cx[ind + 1],  # error
                                                          self.cy[ind + 1])
                if distance_this_index < distance_next_index:  # this よりも next の方が長かったら処理終了
                    break
                ind = ind + 1 if (ind + 1) < len(self.cx) else ind
                distance_this_index = distance_next_index
            self.old_nearest_point_index = ind

        Lf = state.v # k * state.v + Lfc  # update look ahead distance  # 速度速い時は遠くの点を見る

        # search look ahead target point index
        while Lf > state.calc_distance(self.cx[ind], self.cy[ind]): # continue until Lf is longer than the distance to the target point
            if (ind + 1) >= len(self.cx):
                break  # not exceed goal
            ind += 1

        return ind, Lf


def pure_pursuit_steer_control(state, trajectory, pind):
    ind, Lf = trajectory.search_target_index(state)

    # 逆走防止 前の点がtarget point になることを防ぐ
    if pind >= ind:
        ind = pind

    if ind < len(trajectory.cx):
        tx = trajectory.cx[ind]
        ty = trajectory.cy[ind]
    else:  # toward goal
        tx = trajectory.cx[-1]
        ty = trajectory.cy[-1]
        ind = len(trajectory.cx) - 1

    alpha = math.atan2(ty - state.rear_y, tx - state.rear_x) - state.yaw

    delta = math.atan2(2.0 * WB * math.sin(alpha) / Lf, 1.0)

    return delta, ind


# def plot_arrow(x, y, yaw, length=1.0, width=0.5, fc="r", ec="k"):  # 矢印を図示する
#     """
#     Plot arrow
#     """

#     if not isinstance(x, float):
#         for ix, iy, iyaw in zip(x, y, yaw):
#             plot_arrow(ix, iy, iyaw)
#     else:
#         plt.arrow(x, y, length * math.cos(yaw), length * math.sin(yaw),
#                   fc=fc, ec=ec, head_width=width, head_length=width)
#         plt.plot(x, y)


def pure_pursuit_method(path,turtlePos,target_index,speed):
    #  target course
    cx = []
    cy = []
    for coordinate in path:
        cx.append(coordinate[0])
        cy.append(coordinate[1])
    
    # cx = np.arange(0, 50, 0.5)
    # cy = [math.sin(ix / 5.0) * ix / 2.0 for ix in cx]

    target_speed = math.fabs(speed) # 10.0 / 3.6  # [m/s]
    if target_speed == 0.0:
        target_speed = 1.0 # Prevent ZerodivisionError

    # T = 100.0  # max simulation time

    # initial state
    state = State(x=turtlePos[0], y=turtlePos[1], yaw=turtlePos[2] * math.pi /180, v=target_speed)

    lastIndex = len(cx) - 1
    # time = 0.0
    states = States()  # リストを作成
    states.append(state)  # 情報を追加
    target_course = TargetCourse(cx, cy)  # 初期化

    if target_index is None:
        target_ind, _ = target_course.search_target_index(state)  # 近くの点のインデックスをとる
    else:
        target_ind = target_index

    # while T >= time and lastIndex > target_ind:  # ゴールに到達するか時間切れまで継続

        # Calc control input
        # ai = proportional_control(target_speed, state.v)  # 速度の比例制御
    di, target_ind = pure_pursuit_steer_control(
        state, target_course, target_ind)  # 目標ステアリング角とターゲットインデックスを取得

        # state.update(ai, di)  # Control vehicle

        # print(di)  # check

        # time += dt
        # states.append(time, state)  # 情報を追加

        # if show_animation:  # pragma: no cover
        #     plt.cla()
        #     # for stopping simulation with the esc key.
        #     plt.gcf().canvas.mpl_connect(
        #         'key_release_event',
        #         lambda event: [exit(0) if event.key == 'escape' else None])
        #     plot_arrow(state.x, state.y, state.yaw)
        #     plt.plot(cx, cy, "-r", label="course")
        #     plt.plot(states.x, states.y, "-b", label="trajectory")
        #     plt.plot(cx[target_ind], cy[target_ind], "xg", label="target")
        #     plt.axis("equal")
        #     plt.grid(True)
        #     plt.title("Speed[km/h]:" + str(state.v * 3.6)[:4])
        #     plt.pause(0.001)
    
    target_angle = di * 180 / math.pi

    return target_angle,target_ind

    # Test
    assert lastIndex >= target_ind, "Cannot goal"

    # if show_animation:  # pragma: no cover
    #     plt.cla()
    #     plt.plot(cx, cy, ".r", label="course")
    #     plt.plot(states.x, states.y, "-b", label="trajectory")
    #     plt.legend()
    #     plt.xlabel("x[m]")
    #     plt.ylabel("y[m]")
    #     plt.axis("equal")
    #     plt.grid(True)

    #     plt.subplots(1)
    #     plt.plot(states.t, [iv * 3.6 for iv in states.v], "-r")
    #     plt.xlabel("Time[s]")
    #     plt.ylabel("Speed[km/h]")
    #     plt.grid(True)
    #     plt.show()


if __name__ == '__main__':
    print("Pure pursuit path tracking simulation start")
    pure_pursuit_method()