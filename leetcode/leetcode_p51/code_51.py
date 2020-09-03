# 力扣第51题，N皇后
"""
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
"""
from copy import deepcopy


"""
自己实现的，略显简陋
"""
class Solution_00:

    def solveNQueens(n):
        def is_valid(li, curr):
            for i,v in enumerate(li):
                if v == curr:
                    return False
                if (curr == v + len(li) - i) or (curr == v - len(li) + i):
                    return False
            return True

        answer_list = []

        def find_answer(answer):

            if len(answer) == n:
                answer_list.append(deepcopy(answer))
                return None
            
            for i in range(n):
                validation = is_valid(answer, i)
                # print('answer:', answer, 'i:', i, "validation:", validation)
                if validation:
                    answer.append(i)
                    find_answer(answer)
                    answer.pop()
                else:
                    continue

        def trans_to_str(answers, n):
            result = []
            for answer in answers:
                an = list()
                for i in range(n):
                    line = ['.'] * n
                    line[answer[i]] = 'Q'
                    an.append(line)
                result.append(an)
            
            return result

        answer = []
        find_answer(answer)
        
        final_answer = trans_to_str(answer_list, n)

        return final_answer


"""
让我们来看看官方的实现
方法一：基于集合的回溯
与我自己实现的思路比较类似，都是每次先判断这一行该位置的合法性，
如果合法，则放在该位置上，递归继续寻找下一行；
否则就右移一位，继续判断，直到找到合法位置，进行递归，或找到解决方案或这一行到头，进行回溯
"""
class Solution_01:
    def solveNQueens(self, n):
        def generateBoard():
            board = list()
            for i in range(n):
                row[queens[i]] = 'Q'
                board.append("".join(row))
                row[queens[i]] = "."
            return board

        def backtrack(row):
            if row == n:
                board = generateBoard()
                solutions.append(board)
            else:
                for i in range(n):
                    if i in columns or row - i in diagonal1 or row + i in diagonal2:
                        continue
                    queens[row] = i
                    columns.add(i)
                    diagonal1.add(row - i)
                    diagonal2.add(row + i)
                    backtrack(row + 1)
                    columns.remove(i)
                    diagonal1.remove(row - i)
                    diagonal2.remove(row + i)
        
        solutions = list()
        queens = [-1] * n
        columns = set()
        diagonal1 = set()
        diagonal2 = set()
        row = ["."] * n
        backtrack(0)
        return solutions


"""
官方题解二：基于位运算的回溯
对方法一的空间优化
"""
class Solution_02:
    def solveNQueens(self, n):
        def generateBoard():
            board = list()
            for i in range(n):
                row[queens[i]] = 'Q'
                board.append("".join(row))
                row[queens[i]] = "."
            return board
        
        def sovle(row, columns, diagonals1, diagonals2):
            if row == n:
                board = generateBoard()
                solutions.append(board)
            else:
                availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2))
                while availablePositions:
                    position = availablePositions & (-availablePositions)
                    availablePositions = availablePositions & (availablePositions - 1)
                    columns = bin(position - 1).count('1')
                    queens[row] = columns
                    sovle(row+1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1)
        
        solutions = list()
        queens = [-1] * n
        row = ["."] * n
        sovle(0, 0, 0, 0)
        return solutions



if __name__ == "__main__":
    n = 4
    # validation = is_valid([2], 1)
    # print('validation:', validation)


