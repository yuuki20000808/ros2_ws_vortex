import rclpy
import sys

import math
import time

# A* (A-star)経路探索プログラム
class Astar():
    """A node class for A* Pathfinding"""

    def __init__(self, parent=None, position=None): # option hikishuu
        self.parent = parent # 親ノードの設定
        self.position = position # (row, column)のタプル ※row：行、column：列

        self.g = 0.0  # real cost
        self.h = 0.0  # estimate cost
        self.f = 0.0  # total cost

    # def __eq__(self, other):
    #     # node 同士の比較演算子(==)を使用できるように
    #     return self.position == other.position

def astar(obstacle_x, obstacle_y, start, end):
    """Returns a list of tuples as a path from the given start to the given end in the given maze"""
    # obstacle: other dump position、start:スタートポジション、end:ゴールポジション
    # ゴールまでの最短経路のリストを返す関数

    # Create start and end node
    # スタート、エンド（ゴール）ノードの初期化
    start_node = Astar(None, start) # 親ノードは無し
    start_node.g = start_node.h = start_node.f = 0.0
    end_node = Astar(None, end)
    end_node.g = end_node.h = end_node.f = 0.0

    start_time = time.time()

    # Initialize both open and closed list
    open_list = [] # 経路候補を入れとくリスト
    closed_list = [] # 計算終わった用済みリスト
    # Add the start node
    # 経路候補にスタートノードを追加して計算スタート
    open_list.append(start_node)

    # Loop until you find the end
    while len(open_list) > 0:

        # Get the current node
        current_node = open_list[0] 
        current_index = 0
        for index, item in enumerate(open_list):  # index : インデックス番号  item : 要素
            # オープンリストの中でF値が一番小さいノードを選ぶ
            if item.f < current_node.f:
                current_node = item  # 一番小さいノード
                current_index = index  # 一番小さいノードのインデックス番号

        # Pop current off open list, add to closed list
        # 一番小さいF値のノードをオープンリストから削除して、クローズリストに追加
        open_list.pop(current_index)  # リストの要素を削除
        closed_list.append(current_node)  # リストに要素を追加

        # Found the goal
        # ゴールに到達してれば経路(Path)を表示して終了
        if (end_node.position[0]-1) < current_node.position[0] and current_node.position[0] < (end_node.position[0]+1) and (end_node.position[1]-1) < current_node.position[1] and current_node.position[1] < (end_node.position[1]+1):
            path = []  # リスト作成
            current = current_node  # current に ゴール地点でのノードを代入
            while current is not None:
                path.append(current.position)  # path に current.position を追加
                current = current.parent  # current に 親ノード（一つ前のノード）を代入
            return path[::-1] # Return reversed path

        # Generate children
        # ゴールに到達してなければ子ノードを生成
        children = []  # ループごとに初期化して代入
        # for new_position in [(0.0, -1.0), (0.0, 1.0), (-1.0, 0.0), (1.0, 0.0)]: # 上下左右移動のみ (Adjacent squares
        for new_position in [(0.0, -0.5), (0.0, 0.5), (-0.5, 0.0), (0.5, 0.0), (-0.5, -0.5), (-0.5, 0.5), (0.5, -0.5), (0.5, 0.5)]: # 斜め移動ありの場合


            # Get node position
            node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1])

            # Make sure within range
            # 迷路内の移動に限る
            if node_position[0] > 200 or node_position[0] < -200 or node_position[1] > 200 or node_position[1] < -200:
                continue

            # Make sure walkable terrain
            # 移動できる位置に限る（障害物は移動できない）
            # if math.hypot(obstacle_x - node_position[0],obstacle_y - node_position[1]) < 10.0:
            #     continue
            distance = math.hypot(obstacle_x - node_position[0],obstacle_y - node_position[1])
            theta = math.atan2(node_position[0] - obstacle_x,node_position[1] - obstacle_y)
            if distance < math.sqrt(12**2*math.sin(theta)**2 + 7**2*math.cos(theta)**2):
                continue


            # Create new node
            # 移動できる位置のノードのみを生成
            new_node = Astar(current_node, node_position)  # current_node が親ノード node_position が移動できる位置の座標

            # Append
            # 子リストに追加
            children.append(new_node)

        # Loop through children
        # 各子ノードでG, H, Fを計算
        for child in children:  # 変数 child に ノード children が代入されて計算

            # Child is on the closed list
            if len([closed_child for closed_child in closed_list if closed_child.position == child.position]) > 0:  # クローズドリストになければ続行
                continue  # for文のブロックの先頭に戻る

            # Create the f, g, and h values
            # G は親ノード + 1
            child.g = current_node.g + 1.0
            # H は （現在位置 - エンド位置)の2乗  # is it right?
            child.h = ((child.position[0] - end_node.position[0]) ** 2) + ((child.position[1] - end_node.position[1]) ** 2)
            # F = G + H
            child.f = child.g + child.h

            # Child is already in the open list
            if len([open_node for open_node in open_list if child.position == open_node.position and child.g > open_node.g]) > 0:  # オープンリストになければ続行し，もし同じ子ノードでより小さいG値であれば親ノードを現在のノードに設定する  python 内包表記
                continue

            # Add the child to the open list
            # 子ノードをオープンリストに追加
            open_list.append(child)

        end_time = (time.time() - start_time)
        if end_time > 0.5:
            return None

    print("test")

# def example():

#     maze = [[0, 0, 0, 0, 0],
#             [0, 1, 0, 0, 0],
#             [0, 0, 0, 0, 0],
#             [0, 0, 0, 1, 0],
#             [0, 0, 0, 1, 0]]

#     start = (0, 0)
#     end = (4, 4)

#     path = astar(maze, start, end)
#     print(path)

# if __name__ == '__main__':
#     example()

# A*で見つけたパス
# [(0, 0), (0, 1), (0, 2), (1, 2), (2, 2), (2, 3), (2, 4), (3, 4), (4, 4)]