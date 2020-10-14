# 力扣第1002题，查找常用字符
"""
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。
"""

A = ["bella","label","roller"]

class Solution:
    def commonChars(self, A):
        result = list(A[0])
        
        for a in A[1:]:
            new = []
            for alph in a:
                try:
                    index = result.index(alph)
                except:
                    continue
                new.append(result[index])
                result.pop(index)
            result = new
        
        return result


class Solution_01:
    def commonChars(self, A):
        count = dict()
        for a in A[0]:
            count[a] = count.get(a, 0) + 1

        for i,word in enumerate(A[1:]):
            new = {}
            for a in word:
                if count.get(a, 0) != 0:
                    count[a] -= 1
                    new[a] = new.get(a, 0) + 1
            count = new

        result = []
        for i,v in count.items():
            result.extend(list(v*i))
        print('result:', result)


