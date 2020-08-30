# 力扣第214题，最短回文串
"""
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
"""

s = 'aacecaaa'
# s = 'cbabcddd'

"""
第一种，暴力法，可以解决，但会超时
"""
class Solution_00:
    def shortestPalindrome(self, s):
        length = len(s)
        left_s = ''
        print('s: ', s)
        print('left_s:', left_s)
        for i in range(length-1, 0, -1):
            if s[i] == s[0]:
                pre = 0
                for j in range(i, 0, -1):
                    if s[j] != s[pre]:
                        break
                    pre += 1
                else:
                    return left_s + s
            left_s += s[i]

        return left_s + s


"""
第二种，KMP，一种常用的字符串匹配方法
重点是找出fail列表，也叫next列表，即匹配失败时，需要移动的索引位置
"""
class Solution_01:
    def shortestPalindrome(self, s):
        n = len(s)
        fail = [-1 for _ in range(n)]
        for i in range(1, n):
            j = fail[i-1]
            while j != -1 and s[j+1] != s[i]:
                j = fail[j]
            if s[j+1] == s[i]:
                fail[i] = fail[j+1] + 1

        best = -1
        for i in range(n-1, -1, -1):
            while best != -1 and s[best+1] != s[i]:
                best = fail[best]
            if s[best+1] == s[i]:
                best += 1
        
        print(best)
        return s[:best:-1]+s
    

"""
第三种，字符串哈希法
对字符串进行编码，回文的话，就是正向编码和反向编码，寻找两种编码值相等的位置。
"""
class Solution_02:
    def shortestPalindrome(self, s):
        n = len(s)
        base, mod = 131, 10**9 + 7
        left = right = 0
        best = -1
        mul = 1
        for i in range(n):
            right = (right * base + ord(s[i])) % mod
            left = (ord(s[i]) * mul + left) % mod
            if right == left:
                best = i
            mul = mul * base % mod
        print('best:', best)
        add = ("" if best == n-1 else s[best+1:])
        print(add)
        return add[::-1] + s


if __name__ == '__main__':
    so = Solution_00()
    print("构建Solution实例")
    shortest = so.shortestPalindrome(s)
    print("s0最短回文串: ", shortest)

    s = 'abcd'
    s1 = Solution_01()
    shortest = s1.shortestPalindrome(s)
    print("s1最短回文串: ", shortest)

    s2 = Solution_02()
    shortest = s2.shortestPalindrome(s)
    print("s2最短回文串：", shortest)
