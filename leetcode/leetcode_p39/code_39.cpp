// 力扣第39题，组合总和
/*
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
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution00{
public:
    int length;
    void dfs(vector<vector<int>>& result, const vector<int>& candidates, int index, int target, vector<int>& li){
        if (index >= length)
            return;
        if (target - candidates[index] < 0)
            return;
        else if (target - candidates[index] == 0){
            li.emplace_back(candidates[index]);
            result.emplace_back(li);
            li.pop_back();
        }
        else
        {
            dfs(result, candidates, index+1, target, li);
            li.emplace_back(candidates[index]);
            dfs(result, candidates, index, target-candidates[index], li);
            li.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        length = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> li;
        dfs(result, candidates, 0, target, li);
        return result;
    }
};


int main()
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    Solution00 sl0;
    vector<vector<int>> result = sl0.combinationSum(candidates, target);
    for (int i = 0; i < result.size(); ++i){
        for (int j = 0; j < result[i].size(); ++j)
            cout << result[i][j] << ' ';
        cout << endl;
    }

    // cout << "candidates:\n";
    // for (int c: candidates)
    //     cout << c << ' ';
    // cout << endl;
    // cout << "after sort:\n";
    // sort(candidates.begin(), candidates.end());
    // for (int c: candidates)
    //     cout << c << ' ';
    // cout << endl;


    cin.get();
    return 0;
}