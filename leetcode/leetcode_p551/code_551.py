# 力扣第551题，学生出勤记录I
"""
给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：

'A' : Absent，缺勤
'L' : Late，迟到
'P' : Present，到场
如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。

你需要根据这个学生的出勤记录判断他是否会被奖赏.
"""

class Solution:
    def checkRecord(self, s):
        pass


if __name__ == "__main__":
    s = "PPALPLL"

    a_count = 0
    l_count = 0
    for sub in s:
        if sub == 'L':
            l_count += 1
        else:
            l_count = 0
            if sub == 'A':
                a_count += 1
        if a_count > 1:
            print('False')
            break
        if l_count > 2:
            print('False')
            break
    else:
        print('True')
