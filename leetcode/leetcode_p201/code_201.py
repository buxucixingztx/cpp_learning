#  力扣201题，数字范围按位与
m = 7
n = 5

shift = 0
while m != n:
    m = m >> 1
    n = n >> 1
    shift += 1

print(m, n, shift)
m = m << shift
print("result:", m)