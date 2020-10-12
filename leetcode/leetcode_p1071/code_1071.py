# 力扣第1071题，字符串的最大公因子
"""
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2.
"""

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        n1 = len(str1)
        n2 = len(str2)
        sub = str2[0]
        for i2,s2 in enumerate(str2[1:]):
            if s2 == sub[0]:
                ns = len(sub)
                if n2 % ns == 0:
                    for i in range(i2+1, n2, ns):
                        if str2[i:i+ns] != sub:
                            break
                    else:
                        break
            sub += s2
        ns = len(sub)
        for i in range(0, n1, ns):
            if str1[i:i+ns] != sub:
                return ""
        else:
            ns1 = n1 // ns
            ns2 = n2 // ns
            n = ns1 if ns1 < ns2 else ns2
            num = 1
            for i in range(2, n+1):
                if ns1 % i == 0 and ns2 % i == 0:
                    num = i
            return sub * num


if __name__ == "__main__":
    # str1 = "ABCABC"
    # str2 = "ABC"

    str1 = "ABABAB"
    str2 = "ABAB"

    sl = Solution()
    result = sl.gcdOfStrings(str1, str2)
    print("result:", result)
