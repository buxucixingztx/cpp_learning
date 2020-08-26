# 力扣第398题，随机数索引
# 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。可以假设数字一定存在与数组中。

import random


def picks(nums, target):
    index = []
    total = 0
    for i,v in enumerate(nums):
        if v == target:
            index.append(i)
            total += 1

    rand_index = random.randint(0, total-1)
    print(index[rand_index])
    return index[rand_index]


class Solution:
    def __init__(self, nums):
        self.nums = nums
        self.count = 0
        self.dict = {}

    def pick(self, target):
        if target not in self.dict:
            self.dict[target] = []
            for i, v in enumerate(self.nums):
                if v == target:
                    self.dict[target].append(i)
        self.count += 1
        index_list = self.dict[target]
        index = index_list[self.count % len(index_list)]
        return index


array = [1, 2, 3, 3, 3]
target = 3

p1 = picks(array, target)
print('p1: ', p1)

S1 = Solution(array)
p2 = S1.pick(target)
print('p2: ', p2)
