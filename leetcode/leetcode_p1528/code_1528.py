# 力扣第1528题，重新排列字符串
"""
给你一个字符串 s 和一个 长度相同 的整数数组 indices 。

请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。

返回重新排列后的字符串。
"""

class Solution:
    def restoreString(self, s, indices):
        n = len(s)
        ls = [''] * n
        for i, ids in enumerate(indices):
            ls[ids] = s[i]
        
        return ''.join(ls)


if __name__ == "__main__":
    s = "codeleet"
    indices = [4,5,6,7,0,2,1,3]
    sl = Solution()
    print(sl.restoreString(s, indices))
