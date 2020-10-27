# 力扣第1365题，有多少小于当前数字的数字
"""
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i]。

以数组形式返回答案。
"""

class Solution:
    def smallerNumbersThanCurrent(self, nums):
        result = []
        for num in nums:
            count = 0 
            for n in nums:
                if num > n:
                    count += 1
            result.append(count)
        return result


class Solution_01:
    def smallerNumbersThanCurrent(self, nums):
        nums = [[i, nums[i]] for i in range(len(nums))]
        sorted_nums = sorted(nums, key=lambda x: x[1])
        result = [0] * len(nums)
        for i,num in enumerate(sorted_nums):
            if i == 0:
                result[num[0]] = 0
            else:
                if num[1] == sorted_nums[i-1][1]:
                    result[num[0]] = result[sorted_nums[i-1][0]]
                else:
                    result[num[0]] = i
        return result


if __name__ == "__main__":
    # nums = [8, 1, 2, 2, 3]
    nums = [7, 7, 7, 7]
    sl = Solution()
    print(sl.smallerNumbersThanCurrent(nums))

    