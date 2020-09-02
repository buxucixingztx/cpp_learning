# 力扣第231题，2的幂
"""
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
"""

n = 2

def isPowerOfTwo_00(n):
    if n == 1:
        return True
    total = 1
    while total < n:
        total *= 2
        if total == n:
            return True
    return False


def isPowerOfTwo_01(n):
    if n == 1:
        return True
    while True:
        if n % 2 != 0:
            return False
        n //= 2

        if n == 1:
            return True
        
        
def isPowerOfTwo_02(n):
    if n <= 0:
        return False
    if n == 1:
        return True
    i = 1
    while i < n:
        i = i << 1
        if i == n:
            return True
    return False


if __name__ == "__main__":
    n = 17
    i = 1
    result = isPowerOfTwo_01(n)
    print('result:', result)
    print(i<<3)