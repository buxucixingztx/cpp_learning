# 力扣第557题，反转字符串中的单词III
"""
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
"""

s = "let's take LeetCode contest"

n = len(s)
s_l = []
word = []
for ss in s:
    if ss != ' ':
        word.append(ss)
    else:
        s_l.append(''.join(word[::-1]))
        word = []
s_l.append(''.join(word[::-1]))
result = ' '.join(s_l)
print(s)
print(result)