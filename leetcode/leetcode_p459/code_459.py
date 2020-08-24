"""
力扣459题，重复的子字符串。
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
给定的字符串只含有小写英文字母，并且长度不超过10000.
"""



def judge_subs(strs, sub_s):
    s_num = len(strs)
    ss_num = len(sub_s)
    if s_num % ss_num != 0:
        return False
    else:
        for i in range(0, s_num, ss_num):
            if sub_s != s[i:i+ss_num]:
                return False
    return True


def repeateSubstringPattern(s):
    length = len(s)
    sub_s = ''
    for i in range(length//2):
        if s[i] in sub_s:
            if s[i] == sub_s[0]:
                result = judge_subs(s, sub_s)
                if result:
                    return True
        sub_s += s[i]
    result = judge_subs(s, sub_s)
    return result


def repeateSubstringPattern_1(s):
    n = len(s)
    for i in range(1, n//2 + 1):
        if n % i == 0:
            if all(s[j] == s[j - i] for j in range(i, n)):
                return True
    return False


def repeateSubstringPattern_2(s):
    return (s+s).find(s, 1) != len(s)


s = "abcabcabcabc"
# s = 'ababc'
print(s)

result = repeateSubstringPattern(s)
print(result)

result_1 = repeateSubstringPattern_1(s)
print(result_1)

print((s+s).find(s, 1))
print((s+s).find(s, 1) != len(s))

