# 力扣第844题，比较含退格的字符串。
"""
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。
"""

class Solution:
    def backspaceCompare(self, S, T):
        def getstr(string):
            s_list = []
            for sub in string:
                if sub == '#' and len(s_list) != 0:
                    s_list.pop()
                else:
                    s_list.append(sub)
            return ''.join(s_list)

        s = getstr(S)
        t = getstr(T)
        return s == t


class Solution_01:
    def backspaceCompare(self, S, T):
        def backspaceCompare(self, S: str, T: str) -> bool:
            s_index = len(S) - 1
            t_index = len(T) - 1
            while True:
                cout_ = 0
                while s_index >= 0 and (S[s_index] == '#' or cout_ > 0):
                    if S[s_index] == '#':
                        s_index -= 1
                        cout_ += 1
                    else:
                        s_index -= 1
                        cout_ -= 1
                cout_ = 0
                while t_index >= 0 and (T[t_index] == '#' or cout_ > 0):
                    if T[t_index] == '#':
                        t_index -= 1
                        cout_ += 1
                    else:
                        t_index -= 1
                        cout_ -= 1
                cout_ = 0
                if s_index < 0 and t_index < 0:
                    return True
                if s_index < 0 or t_index < 0:
                    return False
                if S[s_index] != T[t_index]:
                    return False
                t_index -= 1
                s_index -= 1



if __name__ == "__main__":
    s = "ab#c"
    t = "ad#c"


