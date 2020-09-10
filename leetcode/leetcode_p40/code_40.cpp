// 力扣第40题，组合总和II
/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<int>& vc);
void print(const vector<vector<int>>& vc);


class Solution00{
public:
    vector<vector<int>> result;
    int length;
    void dfs(int i, int t, vector<int>& cd, vector<int> sub){
        // cout << "length = " << length << " | t = " << t << " | ";
        // cout << "sub.size(): " << sub.size() << endl;
        if (i > length - 1)
            return;
        if (t - cd[i] == 0){
            sub.emplace_back(cd[i]);
            result.emplace_back(sub);
        }
        else if (t - cd[i] > 0){
            sub.emplace_back(cd[i]);
            dfs(i+1, t-cd[i], cd, sub);
            sub.pop_back();
            while (i < length - 1 && cd[i] == cd[i+1])
                i++;
            if (i == length - 1)
                return;
            dfs(i+1, t, cd, sub);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        length = candidates.size();
        vector<int> sub = {};
        dfs(0, target, candidates, sub);

        return result;
    }
};


int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    cout << "candidates: ";
    print(candidates);

    Solution00 sl0;
    vector<vector<int>> result = sl0.combinationSum2(candidates, target);
    cout << "result.size: " << result.size() << endl;
    cout << "result:\n";
    print(result);

    cin.get();
    return 0;
}


void print(const vector<int>& vc){
    for (auto v: vc)
        cout << v << ' ';
    cout << endl;
}

void print(const vector<vector<int>>& vc){
    for (int i = 0; i < vc.size(); i++){
        cout << "[ ";
        for (int j = 0; j < vc[i].size(); j++){
            cout << vc[i][j] << ' ';
        }
        cout << "]\n";
    }
    cout << endl;
}