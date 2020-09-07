# 力扣第60题，第k个排列
"""
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
"""

n = 4
k = 9


n_fact = 1
n_fact_list = [1, ]
store_list = []
for i in range(1, n+1):
    n_fact *= i
    n_fact_list.append(n_fact)
    store_list.append(str(i))

print('store_list:', store_list)
print('n_fact_list:', n_fact_list)
take_list = []
for i in range(1, n+1):
    if k == 1:
        take_list.extend(store_list)
        break
    index = int((k-1) // (n_fact_list[n-i]))
    take_value = store_list.pop(index)
    take_list.append(take_value)
    k = k - index*(n_fact_list[n-i])
    print(f'index: {i},  take_value: {take_value}')

    
print('take_list:', take_list)

