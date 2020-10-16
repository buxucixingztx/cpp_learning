# 力扣第977题，有序数组的平方
"""
给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
"""

A = [-4, -1, 0, 3, 10]

class Solution:
    def sortedSquares(self, A):
        result = []
        length = len(A)
        start = 0
        end = length - 1
        while start <= end:
            if abs(A[start]) < abs(A[end]):
                result.insert(0, A[end]**2)
                end -= 1
            else:
                result.insert(0, A[start]**2)
                start += 1
        return result


class Solution:
    def sortedSquares(self, A):
        return sorted([a*a for a in A])


if __name__ == "__main__":
    pass