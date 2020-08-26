# 官方题解，使用回溯(递归)

phonemap = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}



def solution_00(digits):
    combinations = []
    if len(digits) == 0:
        return combinations

    def trackback(digit, index, combination):
        if index == len(digit):
            combinations.append(combination)
        else:
            letters = phonemap[digit[index]]
            for letter in letters:
                combination += letter
                trackback(digit, index+1, combination)
                combination = combination[:-1]

    trackback(digits, index=0, combination='')
    
    return combinations


def solution_01(digits):
    if not digits:
        return list()
    
    def backtrack(index):
        if index == len(digits):
            combinations.append("".join(combination))
        else:
            digit = digits[index]
            for letter in phonemap[digit]:
                combination.append(letter)
                backtrack(index+1)
                combination.pop()

    combination = list()
    combinations = list()
    backtrack(index=0)
    return combinations

digits = '23'
result00 = solution_00(digits)
print(result00)


result01 = solution_01(digits)
print(result01)