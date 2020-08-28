# 力扣第1326题，灌溉花园的最少水龙头数目
"""
在 x 轴上有一个一维的花园。花园长度为 n，从点 0 开始，到点 n 结束。

花园里总共有 n + 1 个水龙头，分别位于 [0, 1, ..., n] 。

给你一个整数 n 和一个长度为 n + 1 的整数数组 ranges ，其中 ranges[i] （下标从 0 开始）表示：如果打开点 i 处的水龙头，
可以灌溉的区域为 [i -  ranges[i], i + ranges[i]] 。

请你返回可以灌溉整个花园的 最少水龙头数目 。如果花园始终存在无法灌溉到的地方，请你返回 -1 。
"""
"""
本题我自己没有做出来，一下是官方的题解。

方法一：动态规划
1、首先定义一个一维数组prev，每个位置存放的是到达该位置的最长的区间的左值；
2、定义一个一维搜索数组dp，每个位置初始化为一个极大值，第一个位置0；
3、遍历1到n+1的prev范围，如果prev对应的元素的值小于该位置对应的索引值，则从头寻找非极大值的元素个数（最少个数），并加一

注：
上述说明可能不太详细，其实这里面有两个比较难以理解的点。

第一个点是prev数组是怎么构建的，作用是什么？
prev数组长度为n+1，为水龙头的数量，用来记录每个水龙头能覆盖的范围，比较巧妙的一点是，它的每个位置的元素是水龙头覆盖范围的最小左值，
这样每个位置的信息有三个，范围的左值(元素)，范围的右值(索引)，范围(索引减去元素)。
构建过程是计算每个水龙头能覆盖的范围(i-ranges[i], i+ranges[i])，然后寻找以该范围右值为索引的prev元素的值，
如果该值小于该范围的左值，则用左值替换该元素。
注意处理边界问题。

第二个点是dp数组(动态规划数组)及状态转移
dp数组是用来保存子序列状态并状态转移的，但我觉得本题使用的prev数组并不适合做子序列的规划。

本题的dp数组长度为水龙头个数，使用0开头，后面全初始化为极大值，目的是统计dp每个位置能使用的最少水龙头个数。
接下来遍历prev数组，如果该位置元素小于其索引值(说明该位置是一个大的范围的左值，索引为右值)，那么我们就遍历该范围的dp数组，
寻找非极大值的元素，并修改dp数组该索引(遍历到prev的索引)的元素为非极大值+1和当前元素值的最小值；
最后我们只需要查看dp数组最后的元素是否为极大值，如果是极大值，则说明不能覆盖所有范围，如果是非极大值，那么最后的这个元素就是最少水龙头数量。
"""

def solution_01():
    # n = 5
    # ranges = [3, 4, 1, 1, 0, 0]
    n = 9
    ranges = [0,5,0,3,3,3,1,4,0,4]

    prev = [x for x in range(n + 1)]
    #   [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    #   [0, 5, 0, 3, 3, 3, 1, 4, 0, 4]
    #   [0, 1, 2, 3, 4, 5, 0, 1, 2, 3]
    print(ranges)
    for i in range(n+1):
        l = max(i - ranges[i], 0)
        r = min(i + ranges[i], n)
        prev[r] = min(prev[r], l)

    print(prev)

    big = 2**30
    dp = [0] + [big] * n
    # [0, 1073741824, 1073741824, 1073741824, 1073741824, 1073741824, 1073741824, 1073741824, 1073741824, 1073741824]
    # [0, 1,          2,          3,          4,          5,          0,          1,          2,          3         ]
    # [0, 1073741824, 1073741824, 1073741824, 1073741824, 1073741824, 1,          2,          2,          2         ]
    print(dp)
    for i in range(1, n+1):
        for j in range(prev[i], i):
            if dp[j] != big:
                dp[i] = min(dp[i], dp[j] + 1)

    print(dp)


"""
第二种解决方案是在第一种解决方案的基础上进行的优化。
思路是从后向前寻找是否有重合的区域可以组成完整覆盖范围。

ans = 0, break_point设为n
具体来说就是先从prev中取出最后一个元素，它标识了水龙头覆盖范围的左值(记为thresh)，将break_point设为thresh，ans+=1
然后我们从后向前一直寻找更小的左值到索引为break_point的位置，并记录下寻找过程遇到的prev更小的左值，将其赋值给thresh，
在索引值为break_point位置进行判断，thresh是否得到了更新，如果没有，说明覆盖范围发生了中断，返回-1；否则更新break_point为thresh，ans+=1
"""
def solution_02():
    n = 17
    ranges = [0,3,3,2,2,4,2,1,5,1,0,1,2,3,0,3,1,1]
    prev = [x for x in range(n+1)]
    for i,v in enumerate(ranges):
        lv = max(0, i-v)
        rv = min(n, i+v)
        prev[rv] = min(lv, prev[rv])
    
    break_point = n
    thresh = n+1
    ans = 0
    for i in range(n, 1, -1):
        thresh = min(prev[i], thresh)
        if i == break_point:
            if i <= thresh:
                return -1
            ans += 1
            break_point = thresh
    print(ans)
    return ans


solution_02()



