# 力扣第474题，1和0
"""
在计算机界中，我们总是追求用有限的资源获取最大的收益。

现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。

你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

注意:

给定 0 和 1 的数量都不会超过 100。
给定字符串数组的长度不会超过 600。
"""



def counts(strs):
    num_0 = strs.count('0')
    num_1 = strs.count('1')
    return [num_0, num_1]


def findMaxForm(strs, m, n):
    dp = [[0]*(n+1) for _ in range(m+1)]
    max_num = 0
    for s in strs:
        mn = counts(s)
        for mi in range(m, -1, -1):
            if mi - mn[0] < 0:
                break
            for ni in range(n, -1, -1):
                if ni - mn[1] < 0:
                    break
                dp[mi][ni] = max(dp[mi-mn[0]][ni-mn[1]]+1, dp[mi][ni])
                # print(dp)
                if dp[mi][ni] > max_num:
                    max_num = dp[mi][ni]
    #     print(dp)
    print(dp)
    return max_num


if __name__ == "__main__":
    strs = ['10', '0001', '111001', '1', '0']
    m = 5 
    n = 3
    # strs = ["10","0","1"]
    # m = 1
    # n = 1
    # for s in strs:
    #     print(counts(s))
    result = findMaxForm(strs, m, n)
    print('result:', result)