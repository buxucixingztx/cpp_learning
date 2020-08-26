# 力扣第507题，完美数
# 对于一个正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”


num = 33550336
# num = 120

sums = 0
i = 1
while i * i < num:
    if num % i == 0:
        sums += (i + num / i)
        
    i += 1

print(sums//2)
