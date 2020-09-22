# 力扣第200题，岛屿的数量
"""
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。
"""



class Solution:
    def numIslands(self, grid):
        num_row = len(grid)
        num_col = len(grid[0])
        searched = [[0 for _ in range(num_col)] for _ in range(num_row)]
        print("searched:\n", searched)
        
        def dfs(rows, cols):
            print(f'rows = {rows}, cols = {cols}')
            if rows < 0 or rows >= num_row or cols < 0 or cols >= num_col:
                return
            if searched[rows][cols] == 1:
                return
            else:
                searched[rows][cols] = 1
            
            print(f'grid[{rows}][{cols}] = {grid[rows][cols]}')
            if grid[rows][cols] == '1':
                print("four recall")
                dfs(rows-1, cols)
                dfs(rows+1, cols)
                dfs(rows, cols-1)
                dfs(rows, cols+1)
        nums = 0
        for i in range(num_row):
            for j in range(num_col):
                if searched[i][j] == 0 and grid[i][j] == '1':
                    nums += 1
                    dfs(i, j)
        for s in searched:
            print(s)
        
        print('nums:', nums)


if __name__ == "__main__":
    grid = [
            ['1','1','0','0','0'],
            ['1','1','0','0','0'],
            ['0','0','1','0','0'],
            ['0','0','0','1','1']
            ]

    sl = Solution()
    sl.numIslands(grid=grid)
