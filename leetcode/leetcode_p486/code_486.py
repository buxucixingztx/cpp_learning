# 力扣第486题，预测赢家
"""
给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，
然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。
最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
"""


"""
第一种方法，递归，自己实现的
思路就是每个回合，当前玩家都会做出最有利于自己的选择
"""
def first_score(nums, flag=True):
    if len(nums) == 1:
        return nums[0]
    if flag:
        if len(nums) == 2:
            return max(nums)
        right = first_score(nums[1:], flag=False) + nums[0]
        left = first_score(nums[:-1], flag=False) + nums[-1]
        return right if right >= left else left
    else:
        if len(nums) == 2:
            return min(nums)
        right = first_score(nums[1:], flag=True)
        left = first_score(nums[:-1], flag=True)

        return left if right >= left else right


"""
官方题解一：递归
思路是把先手玩家的分数设为总数，如果是先手玩家选择，则累加到总分，否则从总分中减去当前分数
"""
def predict_winner_01(nums):

    def first_score(start, end, turn):
        if start == end:
            return nums[start] * turn
        scoreStart = nums[start] * turn + total(start + 1, end, -turn)
        scoreEnd = nums[end] * turn + total(start, end - 1, -turn)
        return max(scoreStart * turn, scoreEnd * turn) * turn
    
    return total(0, len(nums) - 1, 1) >= 0


"""
官方题解二：动态规划
使用二维数组保存先手玩家与后手玩家的分数之差的最大值。
状态转移方程：
    dp[i][j] = max(nums[i] - dp[i+1][j], nums[j]-dp[i][j-1])
状态转移方程的意义为：
对于新增的序列，如果先手选择第一个元素，那么后手肯定选择剩下里面最优的；
如果先手选择最后一个元素，那么后手一样会从剩下的里面选择最优结果；
所以总结果就是，先手当前两种选择的元素减去后手的最优选择，然后从中选最大的值。
"""
def predict_winner_02(nums):
    n = len(nums)
    dp = [[0]*n for _ in range(n)]
    for i in range(n):
        dp[i][i] = nums[i]
    for i in range(n-1, -1, -1):
        for j in range(i+1, n):
            dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1])
    print(dp)
    return dp[0][n-1] >= 0


"""
下面也是动态规划，不过因为状态转移方程汇总，dp[i][j]的值只跟dp[i+1][j]与dp[i][j-1]有关，
所以可以使用一维数组代替二维数组。
"""
def predict_winner_03(nums):
    length = len(nums)
    dp = [i for i in nums]
    for i in range(length-2, -1, -1):
        for j in range(i+1, length):
            dp[j] = max(nums[i] - dp[j], nums[j] - dp[j-1])
    print(dp)
    return dp[-1] >= 0

if __name__ == "__main__":
    # l = [1, 5, 233, 7]
    l = [1, 5, 2, 4, 6]
    # total = sum(l)
    # print("total =", total)
    # first = first_score(l)
    # print("first person score:", first)
    # print(l[:-1])

    # result = predict_winner(l)
    # print("result: ", result)

    result_2 = predict_winner_02(l)
    print('result_2:', result_2)

    result_3 = predict_winner_03(l)
    print('result_3:', result_3)
