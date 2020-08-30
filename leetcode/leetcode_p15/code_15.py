# 力扣第15题，三数之和
"""
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
"""


"""
本题难度不太大，用暴力法解决的话，思路也非常明确，但需要三个for循环，时间复杂度为o(n**3)，不能满足要求。
所以借鉴了官方题解，使用两个for循环，其中使用了两数相加必然等于第三个数的相反数的性质，第二个循环使用两个指针，分别从头和尾向中间递进。

不过设计起来还是有点麻烦的，里面的逻辑需要梳理清楚，哪个条件先进行判断，哪个条件后判断等等。
还有一个亮点就是在处理重复数字上，先对该数字进行正常处理，如果后续又发现了它，就直接跳过。
"""
def solution_00(nums):
    nums = sorted(nums)
    result = []
    n = len(nums)
    for i in range(n):
        if i > 0 and nums[i] == nums[i-1]:
            continue
        if nums[i] > 0 :
            break
        k = n - 1
        left = -nums[i]
        for j in range(i+1, n-1):
            if j > i+1 and nums[j-1] == nums[j]:
                continue
            while j < k and nums[j] + nums[k] > left:
                k -= 1
            if j >= k:
                break
            if nums[j] + nums[k] == left:
                result.append([nums[i], nums[j], nums[k]])
                continue
    print(result)
    return result


if __name__ == '__main__':
    # nums = [-1, 0, 1, 2, -1, -4]
    nums = [1,2,-2,-1]
    solution_00(nums)