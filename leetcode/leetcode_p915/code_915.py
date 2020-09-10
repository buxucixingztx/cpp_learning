# 力扣第915题，分割数组
"""
给定一个数组 A，将其划分为两个不相交（没有公共元素）的连续子数组 left 和 right， 使得：

left 中的每个元素都小于或等于 right 中的每个元素。
left 和 right 都是非空的。
left 要尽可能小。
在完成这样的分组后返回 left 的长度。可以保证存在这样的划分方法。

提示：
2 <= A.length <= 30000
0 <= A[i] <= 10^6
可以保证至少有一种方法能够按题目所描述的那样对 A 进行划分。
"""


class Solution00:
    def partitionDisjoint(self, A):
        lm = A[0]
        am = lm
        ri = 1
        for i,v in enumerate(A):
            if lm < v and am < v:
                am = v
            if lm > v:
                lm = am
                ri = i + 1
        print('lm:', lm, 'am:', am)
        print('left:', A[:ri])
        print('right:', A[ri:])
        return ri


if __name__ == "__main__":
    # li = [5, 0, 3, 8, 6]
    li = [24,11,49,80,63,8,61,22,73,85]
    sl0 = Solution00()
    length = sl0.partitionDisjoint(li)
    print('最小长度:', length)

