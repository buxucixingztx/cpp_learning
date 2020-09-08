# 力扣第77题，组合
"""
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
"""



def find_com(sub, li, k):
    global result
    if k == 1:
        for v in li:
            result.append(sub + [v])
        return 
    for i,v in enumerate(li):
        find_com(sub+[v], li[i+1:], k-1)

if __name__ == "__main__":
    n = 5
    k = 3
    result = []
    li = list(range(1, n+1))
    find_com([], li, k)
    print(result)
