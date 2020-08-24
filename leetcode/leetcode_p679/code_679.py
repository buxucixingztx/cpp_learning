# 力扣679题，判断能否通过*, /, +, -, (, )的运算得到24。
# print("Hello World!")


op = ['*', '/', '+', '-']
l = [4, 1, 8, 7]

delta = 0.001

def permutation(li, n):
    result_list = []
    if n == 2:
        result_list.append(list(li))
        li[-1], li[-2] = li[-2], li[-1]
        result_list.append(list(li))
        return result_list
    else:
        result_list.extend(permutation(li, n - 1))
        for i in range(1, n):
            l = list(li)
            l[len(li)-n], l[i-n] = l[i-n], l[len(li)-n]
            result_list.extend(permutation(l, n - 1))
    return result_list

def operator(x, y, op_str):
    if op_str == '*':
        return x * y
    elif op_str == '/':
        return x / y
    elif op_str == '+':
        return x + y
    elif op_str == '-':
        return x - y
    else:
        raise ValueError

def get_all_op():
    op_list = '+-*/'
    all_op = []
    for i in range(4):
        for j in range(4):
            for k in range(4):
                all_op.append(op_list[i]+op_list[j]+op_list[k])
    return all_op


permu_list = permutation(l, 4)


all_operator = get_all_op()
print('numbers of operator:', len(all_operator))


def find_solution(d_li, o_li):
    for i, op_i in enumerate(o_li):
        mediu_value = operator(d_li[i], d_li[i+1], op_i)
        if i == 0:
            d_l = [mediu_value] + d_li[i+2:]
            o_l = o_li[i+1:]
        elif i == len(o_li)-1:
            d_l = d_li[:i] + [mediu_value]
            o_l = o_li[:i]
        else:
            d_l = d_li[:i] + [mediu_value] + d_li[i+2:]
            o_l = o_li[:i] + o_li[i+1:]
        for j, op_j in enumerate(o_l):
            mediu_value = operator(d_l[j], d_l[j+1], op_j)
            if j == 0:
                result = operator(mediu_value, d_l[-1], o_l[-1])
            else:
                result = operator(d_l[0],  mediu_value, o_l[0])
            if abs(result - 24) < delta:
                print("I get the solution!!!", [d_li, o_li, (i, j)])
                return True, (i, j)
            # print("solution", [d_li, o_li, (i, j), result, [d_l], mediu_value, o_l])
    return False, (0, 0)

flag = False
for data in permu_list:
    for ope in all_operator:
        try:
            result = find_solution(data, ope)
            if result[0]:
                print("The data can get 24")
                flag = True
                break
        except:
            pass
        
    if flag:
        break


