# LCP 15. 游乐园的迷宫。
"""
小王来到了游乐园，她玩的第一个项目是模拟推销员。有一个二维平面地图，其中散布着 N 个推销点，编号 0 到 N-1，不存在三点共线的情况。
每两点之间有一条直线相连。游戏没有规定起点和终点，但限定了每次转角的方向。首先，小王需要先选择两个点分别作为起点和终点，
然后从起点开始访问剩余 N-2 个点恰好一次并回到终点。访问的顺序需要满足一串给定的长度为 N-2 由 L 和 R 组成的字符串 direction，
表示从起点出发之后在每个顶点上转角的方向。根据这个提示，小王希望你能够帮她找到一个可行的遍历顺序，输出顺序下标（若有多个方案，输出任意一种）。
可以证明这样的遍历顺序一定是存在的。


限制：

3 <= points.length <= 1000 且 points[i].length == 2
1 <= points[i][0],points[i][1] <= 10000
direction.length == points.length - 2
direction 只包含 "L","R"
"""
import math
from math import atan


"""
题意：平面上有N个点，找到一条访问N个点的路径，使得路径的转角满足给定的转角序列。

题解：
我们保持一个理想的状态：转向时，剩余的点都位于要求方向的一侧（即剩余点都符合当前这次的转向要求)。那么当前这次转向选择什么点，
可以使下一次转向的要求是L(R)，则这次转向的点中选择相对方向最右(最左)的点即可。

这里的最左或最右的选择，可以利用叉积的性质：若向量BC和向量BD的叉积结果为正，则从向量BC到向量BD为逆时针选择(BD在BC的左侧)；
反之，若结果为负，则从向量BC到向量BD为顺时针选择(BD在BC的右侧)
"""
class Solution:
    def sub(self, a, b):
        return [a[0]-b[0], a[1]-b[1]]
    
    def cross(self, a, b):
        return a[0]*b[1] - a[1]*b[0]

    def visitOrder(self, points, direction):
        n = len(points)
        used = [0] * n
        order = []

        start = 0
        for i in range(n):
            if points[i][0] < points[start][0]:
                start = i
        used[start] = 1
        order.append(start)

        for i in direction:
            nxt = -1
            if i == 'L':
                for j in range(n):
                    if not used[j]:
                        if nxt == -1 or self.cross(self.sub(points[nxt], points[start]), self.sub(points[j], points[start])) < 0:
                            nxt = j
            else:
                for j in range(n):
                    if not used[j]:
                        if nxt == -1 or self.cross(self.sub(points[nxt], points[start]), self.sub(points[j], points[start])) > 0:
                            nxt = j
            used[nxt] = True
            order.append(nxt)
            start = nxt
        
        for i in range(n):
            if not used[i]:
                order.append(i)
        return order


if __name__ == "__main__":
    points = [[1,3],[2,4],[3,3],[2,1]]
    direction = "LR"
    sl = Solution()
    order = sl.visitOrder(points, direction)
    print('order:', order)




