# 力扣第1054题，距离相等的条形码
"""
在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。

请你重新排列这些条形码，使其中两个相邻的条形码 不能 相等。 
你可以返回任何满足该要求的答案，此题保证存在答案.
"""
class Solution:
    def rearrangeBarcodes(self, barcodes):
        bar_count = dict()
        for bar in barcodes:
            bar_count[bar] = bar_count.get(bar, 0) + 1
        bar_count = sorted(bar_count.items(), key=lambda x: x[1], reverse=True)
        bar_count = [list(bar) for bar in bar_count]
        length = len(barcodes)

        result = length * [0]
        for i in range(0, length, 2):
            if bar_count[0][1] == 0:
                bar_count.pop(0)
            val = bar_count[0][0]
            bar_count[0][1] -= 1
            result[i] = val
        for i in range(1, length, 2):
            if bar_count[0][1] == 0:
                bar_count.pop(0)
            val = bar_count[0][0]
            bar_count[0][1] -= 1
            result[i] = val
        return result


if __name__ == "__main__":
    pass
