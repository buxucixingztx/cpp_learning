# 力扣第1347题，制造字母异位词的最小步骤数
"""
给你两个长度相等的字符串 s 和 t。每一个步骤中，你可以选择将 t 中的 任一字符 替换为 另一个字符。

返回使 t 成为 s 的字母异位词的最小步骤数。

字母异位词 指字母相同，但排列不同（也可能相同）的字符串。

提示：

1 <= s.length <= 50000
s.length == t.length
s 和 t 只包含小写英文字母
"""



class Solution_00:
    def minSteps(self, s, t):
        length = len(s)
        s_dict = {}
        count = 0
        for ss in s:
            s_dict[ss] = s_dict.get(ss, 0) + 1
        for tt in t:
            if s_dict.get(tt, 0) != 0:
                s_dict[tt] -= 1
                count += 1
        return length - count


class Solution_01:
    def minSteps(self, s, t):
        alpha_list = [0] * 26
        for ss in s:
            alpha_list[ord(ss)-97] += 1
        for tt in t:
            if alpha_list[ord(tt)-97] != 0:
                alpha_list[ord(tt)-97] -= 1
        return sum(alpha_list)



if __name__ == "__main__":
    s = "bab"
    t = "aba"
    sl0 = Solution_00()
    result0 = sl0.minSteps(s, t)
    print('result0:', result0)

    sl1 = Solution_01()
    result1 = sl1.minSteps(s, t)
    print('result1:', result1)

