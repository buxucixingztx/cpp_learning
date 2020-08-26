# 力扣第491题，递增子序列
# 给定一个整型数组，找到所有该数组的递增子序列，递增子序列的长度至少是2


def findSubsequences(nums):
    def gethash(base, mod, temp):
        hashvalue = 0
        for x in temp:
            hashvalue = hashvalue * base % mod + (x + 101)
            hashvalue %= mod
        return hashvalue

    def check(temp):
        for i in range(1, len(temp)):
            if temp[i] < temp[i - 1]:
                return False
        return len(temp) >= 2

    def findSubsequences(mask, nums):
        temp = []
        for i in range(n):
            if mask & 1:
                temp.append(nums[i])
            mask >>= 1
        return temp

    s = set()
    n = len(nums)
    ans = []
    i = 0
    n = 1 << n
    while i < n:
        temps = findSubsequences(i, nums)
        hashvalue = gethash(263, 1e9 + 7, temps)

        if check(temps) and hashvalue not in s:
            ans.append(temps)
            s.add(hashvalue)

        i += 1
    print(ans)
    return ans


# array = [4, 6, 7, 7]
array = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
findSubsequences(array)

