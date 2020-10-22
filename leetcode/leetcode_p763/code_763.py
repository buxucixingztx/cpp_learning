# 力扣第763题，划分字母区间
"""
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。
返回一个表示每个字符串片段的长度的列表。
"""
import collections

class Solution:
    def partitionLabels(self, S):
        alph_index = collections.defaultdict(list)
        for i,s in enumerate(S):
            alph_index[s].append(i)
        
        print(alph_index)

        result = []

        end = 0
        for index in alph_index.values():
            if index[0] < end:
                end = max(end, index[-1])
            else:
                result.append(index[0])
                end = index[-1]
        result.append(end+1)
        result = [result[i+1]-result[i] for i in range(len(result)-1)]
        return result


class Solution_01:
    def partitionLabels(self, S):
        last = [0] * 26
        for i,ch in enumerate(S):
            last[ord(ch)-ord('a')] = i
        
        partition = list()
        start = end = 0
        for i,ch in enumerate(S):
            end = max(end, last[ord(ch) - ord('a')])
            if i == end:
                partition.append(end - start + 1)
                start = end + 1
        return partition


if __name__ == "__main__":
    pass
    
