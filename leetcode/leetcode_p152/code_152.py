# 力扣第152题，乘积最大子数组
"""
给你一个整数数组nums，请你找出数组中乘积最大的连续子数组(该子数组中至少包含一个数字)，
并返回该子数组所对应的乘积。
"""


class Solution:
    def maxProduct(self, nums):
        min_list = [nums[0]]
        max_list = [nums[0]]

        for num in nums[1:]:
            max_list.append(max([num, min_list[-1]*num, max_list[-1]*num]))
            min_list.append(min([num, min_list[-1]*num, max_list[-2]*num]))
        
        return max(max_list)


class Solution_01:
    def maxProduct(self, nums):
        result = nums[0]
        min_value = nums[0]
        max_value = nums[0]

        for num in nums[1:]:
            temp = min_value
            min_value = min([num, min_value * num, max_value * num])
            max_value = max([num, temp*num, max_value * num])
            if max_value > result:
                result = max_value
        
        return result


if __name__ == "__main__":
    # nums = [2, 3, -2, 4, -1]
    nums = [-4,-3,-2]
    sl1 = Solution_01()
    result1 = sl1.maxProduct(nums)
    print('result:', result1)



