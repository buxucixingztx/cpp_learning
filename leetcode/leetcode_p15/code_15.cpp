// 力扣第15题，三数之和
/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution_00 {
public:
    vector<vector<int>> threeSum(vector<int> & nums){
        vector<vector<int>> result = {};

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            if (nums[i] > 0)
                break;
            int left = -nums[i];
            int k = n - 1;
            for (int j = i+1; j < k; ++j){
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                while (j < k && nums[j] + nums[k] > left)
                    --k;
                if (j >= k)
                    break;
                if (nums[j] + nums[k] == left){
                    vector<int> new_num = {nums[i], nums[j], nums[k]};
                    result.push_back(new_num);
                }
            }
        }
        return result;
    }
};


int main()
{
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {1, 2, -2, -1};
    cout << "before sort nums: " << endl;
    for (auto p = nums.begin(); p != nums.end(); ++p)
        cout << *p << " ";
    cout << endl;

    // sort(nums.begin(), nums.end());
    
    // cout << "after sort nums: " << endl;
    // for (auto p = nums.begin(); p != nums.end(); ++p)
    //     cout << *p << " ";
    // cout << endl;

    Solution_00 s00;
    vector<vector<int>> result_00 = s00.threeSum(nums);
    int n = result_00.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; ++j)
            cout << result_00[i][j] << ",\t";
        cout << endl;
    }

    return 0;
}
