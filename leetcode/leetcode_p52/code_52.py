# 力扣第52题，N皇后II
"""
n皇后问题研究的是如何将n个皇后放置在nxn的棋盘上，并且使皇后彼此之间不能相互攻击。

给定一个整数n，返回n皇后不同的解决方案的数量。
"""

class Solution:
    def totalNQueens(self, n: int) -> int:
        def checkValid(li, cur, pos):
            for i,p in enumerate(li[:cur][::-1]):
                if pos == p:
                    return False
                if pos == p-i-1 or pos == p+i+1:
                    return False
            return True
        
        result = 0
        record = [-1] * n

        def dfs(layer):
            nonlocal result, record
            if layer == n:
                result += 1
                return 
            for i in range(n):
                if checkValid(record, layer, i):
                    record[layer] = i 
                    dfs(layer+1)
                record[layer] = -1
        dfs(0)

        return result


if __name__ == "__main__":
    sl = Solution()
    n = 4
    print(sl.totalNQueens(n))

