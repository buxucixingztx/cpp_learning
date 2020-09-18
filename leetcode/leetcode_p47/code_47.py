# 力扣第47题，全排列
"""
给定一个可包含重复数字的序列，返回所有不重复的全排列。
"""
from collections import defaultdict

class Solution:
    def permuteUnique(self, nums):
        length = len(nums)
        numdict = defaultdict(list)
        for n in nums:
            numdict[n].append(n)
        result = []
        def dfs(nd, l):
            if len(l) == length:
                result.append(list(l))
            else:
                for k,v in nd.items():
                    if v:
                        l.append(nd[k].pop())
                        dfs(nd, l)
                        l.pop()
                        nd[k].append(k)
        
        dfs(numdict, [])
        
        return result


if __name__ == "__main__":
    nums = [1, 1, 1, 2]
    sl = Solution()
    result = sl.permuteUnique(nums)
    for re in result:
        print(re)