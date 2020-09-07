# 力扣第210题，课程表II
"""
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
"""
import collections
from leetcode.leetcode_p207.code_207 import numCourses, prerequisites, re


"""
解法一：深度优先遍历
"""
class Solution_01():
    def findOrder(self, numCourses, prerequisites):
        # 存储有向图
        edges = collections.defaultdict(list)
        # 存储状态, 0未处理，1处理中，2已处理
        states = [0] * numCourses
        # 是否有效，即是否有环
        valid = True
        # 栈，保存遍历的顺序
        visited = list()

        for info in prerequisites:
            edges[info[1]].append(info[0])

        print('edges:', edges)

        def dsf(index):
            if states[index] == 2:
                return

            nonlocal valid
            cans = edges[index]
            states[index] = 1
    
            for c in cans:
                if states[c] == 0:
                    dsf(c)
                elif states[c] == 1:
                    valid = False
                    return
            states[index] = 2
            visited.append(index)
        
        for i in range(numCourses):
            dsf(i)

        print('states:', states)
        if not valid:
            return list()
        
        return visited[::-1]


"""
解法二：广度优先算法(自己实现的)
"""
class Solution_02():
    def findOrder(self, numCourses, prerequisites):
        out_dict = collections.defaultdict(list)
        in_dict = collections.defaultdict(set)
        unvisited = set(range(numCourses))
        lines = list()

        for p in prerequisites:
            out_dict[p[1]].append(p[0])
            in_dict[p[0]].add(p[1])

        while unvisited:
            line = []
            for ele in unvisited:
                in_element = in_dict[ele]
                out_element = out_dict[ele]
                if not in_element:
                    line.append(ele)
                    for oe in out_element:
                        in_dict[oe].remove(ele)
            if not line:
                break
            lines += line
            for l in line:
                unvisited.remove(l)
        
        if unvisited:
            return list()
        
        return lines


"""
解法二：广度优先算法(官方版本)
"""
class Solution:
    def findOrder(self, numCourses, prerequisites):
        # 存储有向图
        edges = collections.defaultdict(list)
        # 存储每个节点的入度
        indeg = [0] * numCourses
        # 存储答案
        result = list()

        for info in prerequisites:
            edges[info[1]].append(info[0])
            indeg[info[0]] += 1
        
        # 将所有入度为0的节点放入队列中
        q = collections.deque([u for u in range(numCourses) if indeg[u] == 0])

        while q:
            # 从队首取出一个节点
            u = q.popleft()
            # 放入答案中
            result.append(u)
            for v in edges[u]:
                indeg[v] -= 1
                # 如果相邻节点v的入度为0，就可以选v对应的课程了
                if indeg[v] == 0:
                    q.append(v)

        if len(result) != numCourses:
            result = list()

        return result


if __name__ == "__main__":
    n = 2
    pres = [[1,0],[0,1]]
    # n = 4
    # pres = [[1,0],[2,0],[3,1],[3,2]]
    sl = Solution_01()
    orders = sl.findOrder(n, pres)
    print(orders)