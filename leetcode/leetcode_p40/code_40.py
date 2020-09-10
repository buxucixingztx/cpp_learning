# 力扣第40题，组合总和II
"""
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合
"""


"""
针对这种题目，我们通常的思路是递归加回溯，对当前索引i对应的元素，我们有两种方法：选或者不选，
相当于使用二叉分类，不断以这种方式去递归寻找答案。

但这里有一个要求，不能包含重复的组合，
针对这个要求，我们的解决方法是先对候选数组candidates进行排序，然后在选取元素的时候，对上面两个方法进行调整，
选择当前索引i对应的元素，这个分支保持不变；
如果不选择当前索引i对应的元素vi，则需要判别下一个索引i+1对应的元素v(i+1)是否与vi相同，如果相同，则不选取，同时再往下寻找与vi不同的元素，进行递归
"""
class Solution00:
    def combinationSum2(self, candidates, target):
        length = len(candidates)
        candidates = sorted(candidates)
        result = []
        def dfs(i, t, sub):
            print(i, t, sub)
            if i > length - 1:
                return
            if t - candidates[i] == 0:
                result.append(sub+[candidates[i]])
            elif t - candidates[i] > 0:
                dfs(i+1, t-candidates[i], sub+[candidates[i]])
                while i < length - 1 and candidates[i] == candidates[i+1]:
                    i += 1
                if i == length - 1:
                    return
                dfs(i+1, t, sub)

        dfs(0, target, [])
        print('result:', result)

        for re in result:
            print(re)
        return result



if __name__ == "__main__":
    # candidates = [10, 1, 2, 7, 6, 1, 5]
    # target = 8
    candidates = [2, 5, 2, 1, 2]
    target = 5

    sl0 = Solution00()
    sl0.combinationSum2(candidates, target)
    