// 力扣第152题，乘积最大子数组
/*
给你一个整数数组nums，请你找出数组中乘积最大的连续子数组(该子数组中至少包含一个数字)，
并返回该子数组所对应的乘积。
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution{
public:
    int maxProduct(vector<int>& nums){
        int result = nums[0];
        int max_value = result;
        int min_value = result;

        for (auto num=nums.begin()+1; num != nums.end(); num++){
            int temp = min_value;
            min_value = min(*num, min((*num)*temp, (*num)*max_value));
            max_value = max(*num, max((*num)*max_value, (*num)*temp));
            if (max_value > result)
                result = max_value;
        }
        return result;
    }
};


int main()
{
    vector<int> num = {3, -2, 4, -1};
    Solution sl;
    int result = sl.maxProduct(num);
    cout << "result = " << result << endl;

    cin.get();
    return 0;
}