# 力扣1392题，最长快乐前缀
# 【快乐前缀】是在原字符串中既是非空前缀也是后缀（不包括原字符串自身）的字符串。
# 给定一个字符串s, 返回它的最长快乐前缀，如果不存在，则返回一个空字符串


def find_happy_01(s):
    length = len(s)

    max_hp = 'non str'
    sub_s = ''
    for i,v in enumerate(s):
        sub_s += v
        # print('sub_s:', sub_s)
        if sub_s[0] == s[length-i-1]:
            print(sub_s[0], '==', s[length-i-1], sub_s)
            if sub_s == s[length-i-1:] and len(sub_s) != length:
                max_hp = sub_s

    print(max_hp)
    return max_hp


def find_happy_02(s):
    n = len(s)
    prefix, suffix = 0, 0
    base, mod, mul = 31, 1000000007, 1
    happy = 0
    for i in range(1, n):
        prefix = (prefix * base + (ord(s[i - 1]) - 97)) % mod
        suffix = (suffix + (ord(s[n - i]) - 97) * mul) % mod
        if prefix == suffix:
            happy = i
        mul = mul * base % mod
    return s[:happy]


def find_happy_03(s):
    n = len(s)
    record_list = [-1 for _ in range(n)]
    for i in range(1, n):
        j = record_list[i-1]
        while j != -1 and s[i] != s[j+1]:
            j = record_list[j]
        if s[j+1] == s[i]:
            record_list[i] = j + 1
    print(record_list)
    return s[:record_list[-1]+1]


s = 'acccbaaacccbaac'
# s = 'ababab'
result = find_happy_03(s)
print('result:', result)






