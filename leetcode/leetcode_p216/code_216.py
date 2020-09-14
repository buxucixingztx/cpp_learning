# 力扣地216题，组合总和III
"""
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
"""

k = 3
n = 7

result = []
def dfs(k, t, i, sub):
    if k == 0 and t == 0:
        result.append(sub)
        return
    if k <= 0 and t > 0 or i > 9 or i > t:
        return 
    dfs(k, t, i+1, sub)
    dfs(k-1, t-i, i+1, sub+[i])


dfs(k, n, 1, [])

print(result)

    