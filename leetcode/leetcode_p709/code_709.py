# 力扣709题，转换成小写字母

strs = "Hello"
str_list = []
for i,s in enumerate(strs):
    if s.isupper():
        str_list.append(s.lower())
    else:
        str_list.append(s)

print(''.join(str_list))