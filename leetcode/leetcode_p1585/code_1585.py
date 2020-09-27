# 力扣第1585题， 检查字符串是否可以通过排序子字符串得到另一个字符串
"""
给你两个字符串 s 和 t ，请你通过若干次以下操作将字符串 s 转化成字符串 t ：

选择 s 中一个 非空 子字符串并将它包含的字符就地 升序 排序。
比方说，对下划线所示的子字符串进行操作可以由 "14234" 得到 "12344" 。

如果可以将字符串 s 变成 t ，返回 true 。否则，返回 false 。

一个 子字符串 定义为一个字符串中连续的若干字符
"""
import collections

class Solution:
    def isTransformable(self, s, t):
        n = len(s)
        pos = {i: collections.deque() for i in range(10)}
        for i, digit in enumerate(s):
            pos[int(digit)].append(i)
        
        for i, digit in enumerate(t):
            d = int(digit)
            if not pos[d]:
                return False
            if any(pos[j] and pos[j][0] < pos[d][0] for j in range(d)):
                return False
            pos[d].popleft()
        return True


if __name__ == "__main__":
    s = "84532"
    t = "34852"
    sl = Solution()
    result = sl.isTransformable(s, t)
    print("result:", result)

    