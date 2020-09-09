# 力扣第39题，组合总和
"""
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
"""


class Solution00:
    def combinationSum(self, candidates, target):
        result = set()
        candidates = sorted(candidates)
        def dfs(t, li):
            for c in candidates:
                if t - c < 0:
                    break
                elif t - c == 0:
                    re = sorted(li+[c])
                    result.add(tuple(re))
                else:
                    dfs(t-c, li+[c])

        dfs(target, [])
        result = [list(re) for re in result]
        print(result)
        return result


class Solution01:
    def combinationSum(self, candidates, target):
        length = len(candidates)
        result = []
        candidates = sorted(candidates)
        def dfs(target, index, li):
            nonlocal candidates
            if index >= length:
                return
            if target - candidates[index] == 0:
                result.append(li+[candidates[index]])
            elif target - candidates[index] < 0:
                return
            else:
                dfs(target-candidates[index], index, li+[candidates[index]])
                dfs(target, index+1, li)
        dfs(target, 0, [])
        print(result)


if __name__ == "__main__":
    candidates = [2, 3, 6, 7]
    target = 7

    # sl0 = Solution00()
    # sl0.combinationSum(candidates, target)

    sl1 = Solution01()
    sl1.combinationSum(candidates, target)

