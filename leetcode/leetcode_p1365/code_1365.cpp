// 力扣第1365题，有多少小于当前数字的数字
/*
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i]。

以数组形式返回答案。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums){
        vector<int> result;
        for (auto num: nums){
            int count = 0;
            for (int n: nums){
                if (n < num){
                    count ++;
                }
            }
            result.emplace_back(count);
        }
        return result;
    }
};


class Solution_01{
public:
    vector<int> samllerNumbersThanCurrent(vector<int>& nums){
        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); i++){
            data.emplace_back(nums[i], i);
        };
        sort(data.begin(), data.end());

        vector<int> result(data.size(), 0);
        for (int i = 0; i < data.size(); i++){
            if (i == 0){
                result[data[i].second] = 0;
            }
            else
            {
                if (data[i].first == data[i-1].first){
                    result[data[i].second] = result[data[i-1].second];
                }
                else
                {
                    result[data[i].second] = i;
                } 
            }
        }
        return result;
    }
};


void print_vector(vector<int>& nums){
    for(int n: nums){
      cout << n << ' ';  
    }
    cout << endl;
};

void print_vector(vector<pair<int, int>>& data){
    for (auto n: data){
        cout << n.first << ' ' << n.second << ", ";
    }
    cout << endl;
}


main()
{
    vector<int> nums = {8, 1, 2, 2, 3};
    Solution sl;
    vector<int> result = sl.smallerNumbersThanCurrent(nums);
    // cout << result.size() << endl;
    cout << "Solution:\n";
    print_vector(result);

    Solution_01 sl1;
    result = sl1.samllerNumbersThanCurrent(nums);
    cout << "Solution:\n";
    print_vector(result);

    cin.get();
    return 0;
}