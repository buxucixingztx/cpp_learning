// 力扣第486题，预测赢家
/*
给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，
然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。
最终获得分数总和最多的玩家获胜。

给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool PredictTheWinner(vector<int>&nums){
        vector<int> dp = nums;
        int n = nums.size();
        for (int i = n-2; i >= 0; i--){
            for (int j = i+1; j < n; ++j)
                dp[j] = max(nums[i]-dp[j], nums[j]-dp[j-1]);
        }
        return dp[n-1] >= 0;
    }
};


int main()
{
    vector<int> nums = {1, 5, 2, 4, 6};
    Solution sl;
    bool result = sl.PredictTheWinner(nums);
    cout << "The result: " << boolalpha << result << endl;

    cin.get();
    return 0;
}



