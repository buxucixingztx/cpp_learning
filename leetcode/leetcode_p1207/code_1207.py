# 力扣第1207题，独一无二的出现次数
"""
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
"""

class Solution:
    def uniqueOccurrences(self, arr):
        count = dict()
        for num in arr:
            count[num] = count.get(num, 0) + 1
        occ = []
        for v in count.values():
            if v in occ:
                return False
            occ.append(v)
        return True


class Solution_01:
    def uniqueOccurrences(self, arr):
        count = dict()
        for num in arr:
            count[num] = count.get(num, 0) + 1
        return len(set(count.values())) == len(count)


if __name__ == "__main__":
    pass
    

