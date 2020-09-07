# 力扣第207题，课程表

"""
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
"""
import collections
from collections import deque


"""
自己实现的，方法类似于深度优先搜索，但对每个点的状态区分度不够，
只区分未处理和已处理，而实际上应该再加上处理中的状态。
"""
def canFinish(numCourses, prerequisites):
    record = [1 for _ in range(numCourses)]

    pre_dict = dict()
    for requisit in prerequisites:
        after = requisit[0]
        pre = requisit[1]
        record[after] = 0
        pre_dict[pre] = pre_dict.get(pre, [])
        pre_dict[pre].append(after)

    def find_course(index):
        if pre_dict.get(index) == None:
            return None
        index_list = pre_dict.get(index)
        for i in index_list:
            if record[i] == 1:
                continue
            record[i] = 1
            find_course(i)

    for i,re in enumerate(record):
        if re == 1:
            find_course(i)


    print('record:', record)
    print('pre_dict:', pre_dict)

    if len(record) == sum(record):
        print('可以修完所有课程')
    else:
        print('不可修完所有课程')


"""
方法一：深度优先搜索
"""
class Solution_00:
    def canFinish(self, numCourses, prerequisites):
        states = [0] * numCourses
        outdeg = collections.defaultdict(list)
        visited = list()
        valid = True

        for info in prerequisites:
            outdeg[info[1]].append(info[0]) 

        def dfs(index):
            nonlocal valid
            if states[index] == 2 or not valid:
                return
            outs = outdeg[index]
            states[index] = 1
            for out in outs:
                if states[out] == 1:
                    valid = False
                    return
                elif states[out] == 0:
                    dfs(out)
            states[index] = 2
            visited.append(index)

        print('visited:', visited)
        print('outdeg:', outdeg)
        for i in range(numCourses):
            dfs(index=i)

        return valid


"""
方法二：广度优先搜索
"""
class Solution_01:
    def canFinish(self, numCourses, prerequisites):
        num_indeg = [0] * numCourses
        outdeg = collections.defaultdict(list)
        zeroqueue = collections.deque()
        nums = 0

        for info in prerequisites:
            outdeg[info[1]].append(info[0])
            num_indeg[info[0]] += 1
        
        for i,v in enumerate(num_indeg):
            if v == 0:
                zeroqueue.append(i)

        while len(zeroqueue) != 0:
            nums += 1
            index = zeroqueue.popleft()
            outs = outdeg[index]
            for out in outs:
                num_indeg[out] -= 1
                if num_indeg[out] == 0:
                    zeroqueue.append(out)
        
        return nums == numCourses
        


if __name__ == "__main__":
    # numCourses = 3
    # prerequisites = [[1,0],[1,2],[0,1]]
    numCourses = 4
    prerequisites = [[0,1],[3,1],[1,3],[3,2]]

    # sl0 = Solution_00()
    # result0 = sl0.canFinish(numCourses, prerequisites)
    # print('result0:', result0)

    sl1 = Solution_01()
    result1 = sl1.canFinish(numCourses, prerequisites)
    print('result1:', result1)

    