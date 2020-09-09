# 力扣第130题，被围绕的区域
"""
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
"""
import collections


class Solution00:
    def solve(self, board):
        if len(board) == 0:
            return
        if len(board[0]) == 0:
            return
        height = len(board)
        width = len(board[0])

        def dfs(i, j):
            if not 0 <= i < height or not 0 <= j < width or board[i][j] != 'O':
                return
            board[i][j] = 'A'
            dfs(i-1, j)
            dfs(i+1, j)
            dfs(i, j-1)
            dfs(i, j+1)
        
        for h in range(height):
            dfs(h, 0)
            dfs(h, width-1)
        
        for w in range(width):
            dfs(0, w)
            dfs(height-1, w)

        for h in range(height):
            for w in range(height):
                if board[h][w] == 'A':
                    board[h][w] = 'O'
                elif board[h][w] == 'O':
                    board[h][w] = 'X'


class Solution01:
    def solve(self, board):
        if len(board) == 0:
            return
        if len(board[0]) == 0:
            return
        height = len(board)
        width = len(board[0])
        oq = collections.deque()

        for h in range(height):
            if board[h][0] == 'O':
                oq.append([h, 0])
            if board[h][width-1] == 'O':
                oq.append([h, width-1])
        
        for w in range(width):
            if board[0][w] == 'O':
                oq.append([0, w])
            if board[height-1][w] == 'O':
                oq.append([height-1, w])

        while oq:
            h,w = oq.pop()
            board[h][w] = 'A'
            if 0 <= h-1 and board[h-1][w] == 'O':
                oq.append([h-1, w])
            if 0 <= w-1 and board[h][w-1] == 'O':
                oq.append([h, w-1])
            if h+1 < height and board[h+1][w] == 'O':
                oq.append([h+1][w])
            if w+1 < width and board[h][w+1] == 'O':
                oq.append([h, w+1])
        
        for h in range(height):
            for w in range(width):
                if board[h][w] == 'A':
                    board[h][w] = 'O'
                elif board[h][w] == 'O':
                    board[h][w] = 'X'



if __name__ == "__main__":
    # board = [["X","O","X"],
    #          ["O","X","O"],
    #          ["X","O","X"]]
    
    board = [['X', 'X', 'X', 'X'],
             ['X', 'O', 'O', 'X'],
             ['X', 'X', 'O', 'X'],
             ['X', 'O', 'X', 'X'],]

    # sl0 = Solution00()
    # sl0.solve(board)
    sl1 = Solution01()
    sl1.solve(board)

    for b in board:
        print(b)