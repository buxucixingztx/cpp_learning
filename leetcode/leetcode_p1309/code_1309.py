# 力扣第1309题，解码字母到整数映射
"""
给你一个字符串 s，它由数字（'0' - '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：

字符（'a' - 'i'）分别用（'1' - '9'）表示。
字符（'j' - 'z'）分别用（'10#' - '26#'）表示。 
返回映射之后形成的新字符串。

题目数据保证映射始终唯一。
"""

"""
思路，从头匹配，从尾部匹配
"""



def freqAlphabets_00(s):
    de_s = ""
    count = 0
    trans = ''
    for ss in s[::-1]:
        if count == 2:
            count -= 1
            trans = ss + trans
        elif count == 1:
            count -= 1
            trans = ss + trans
            de_s = chr(int(trans)+96) + de_s
        else:
            if ss == '#':
                count = 2
                trans = ''
            else:
                de_s = chr(int(ss)+96) + de_s
    print(de_s)
    return de_s


def freqAlphabets_01(s):
    n = len(s) - 1
    des = ''
    while n >= 0:
        alpha = s[n]
        if alpha == '#':
            alpha = s[n-2:n]
            n -= 2
        des = chr(int(alpha)+96) + des
        n -= 1
    print(des)
    return des


if __name__ == "__main__":
    s = "1326#"
    print(s)
    freqAlphabets_00(s)
    freqAlphabets_01(s)

