# 力扣第3题，无重复字符的最长子串
"""
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
"""

s = "abcabcbb"

sub_s = ""
max_sub = ""
max_length = 0
for ss in s:
    index = sub_s.find(ss)
    if index != -1:
        if len(sub_s) > max_length:
            max_length = len(sub_s)
            max_sub = sub_s
        sub_s = sub_s[index+1:]
        sub_s += ss
    else:
        sub_s += ss
if len(sub_s) > max_length:
    max_length = len(sub_s)
    max_sub = sub_s
print(s)
print(max_sub)
print(max_length)