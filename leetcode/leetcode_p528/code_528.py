# 力扣第528题，按权重随机选择
"""
给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

也就是说，选取下标 i 的概率为 w[i] / sum(w) 。
"""

"""
本题太容易超时，使用python一直没通过
"""

import random
from random import randint

class Solution_00:
    def __init__(self, w):
        n = len(w)
        self.w = []
        [self.w.extend([i]*w[i]) for i in range(n)]
        random.shuffle(self.w)
        self.index = 0
        print(self.w)
        
    def pickIndex(self):
        rp = self.w[self.index]
        self.index += 1
        return rp


class Solution_01:
    def __init__(self, w):
        total = 0
        self.psum = []
        self.n = len(w)
        for wi in w:
            total += wi
            self.psum.append(total)
    def pickIndex(self):
        target = random.randint(0, self.n-1)
        low = 0
        high = self.n - 1
        while low != high:
            mid = (low + high) // 2
            if target > self.psum[mid]:
                low = mid + 1
            else:
                high = mid
        return low


if __name__ == '__main__':
    li = [1, 1, 3, 1, 3, 1]
    # for i in range(len(li)):
    #     rp = random.randint(0, len(li)-1)
    #     print(li[rp])
    s00 = Solution_00([1, 3])

