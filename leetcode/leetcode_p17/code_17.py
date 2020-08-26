# 力扣17题，电话号码的字母组合
# 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合

print(chr(97))
print(chr(97+25))


chs = '8'
def leeterCombinations(chs):
    if len(chs) == 0:
        return ['']
    ch_list = ['']
    for i,ch in enumerate(chs):
        number = int(ch)
        if 2 <= number < 7:
            chars = [chr(97+j+(number-2)*3) for j in range(3)]
        elif number == 7:
            chars = [chr(97+j+(number-2)*3) for j in range(4)]
        elif number == 8:
            chars = [chr(97+j+(number-2)*3+1) for j in range(3)]
        elif number == 9:
            chars = [chr(97+j+(number-2)*3+1) for j in range(4)]
        else:
            return ''
        ch_list = [pre+ cur for cur in chars for pre in ch_list]
    print(ch_list)

leeterCombinations(chs)


