# 力扣516题，最长回文子序列
# 给定一个字符串s，找到其中最长的回文子序列，并返回该序列的长度，可以假设s的最大长度为1000。

s = 'abcba'
length = len(s)
grid = [[0 for _ in range(length)] for _ in range(length)]

for i in range(length):
    grid[i][i] = 1

for i in range(length - 1, -1, -1):
    for j in range(i+1, length):
        if s[i] == s[j]:
            print(i, j, '===')
            grid[i][j] = grid[i+1][j-1]+2
        else:
            grid[i][j] = max(grid[i][j-1], grid[i+1][j])


for g in grid:
    print(g)