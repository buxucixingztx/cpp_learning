// 力扣第398题，随机数索引
// 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引，可以假设给定的数字一定存在与数组中。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    vector<int> nums_vector;
    unordered_map<int, vector<int>> dict;
    int count = 0;
    Solution(vector<int>& nums){
        nums_vector = nums;
    }
    int pick(int target){
        int n = nums_vector.size();
        if (dict.find(target) == dict.end()){
            vector<int> temp;
            for (int i = 0; i < n; ++i)
            {
                if (target == nums_vector[i]){
                    temp.push_back(i);
                }
            }
            dict.emplace(target, temp);
        }
        count++;
        vector<int> index_list = dict.at(target);
        int rand = count % index_list.size();
        int index = index_list[rand];
        return index;
    }
};

int main()
{
    unordered_map<int, string> intstrMap;
    intstrMap.emplace(1, "num1");
    if (intstrMap.find(1) != intstrMap.end())
        cout << "intstrMap at 1: " << intstrMap.at(1) <<endl;
    if (intstrMap.find(0) == intstrMap.end())
        cout << "0 not in intstrMap!" << endl;
    
    vector<int> nums = {1, 2, 3, 3, 3, 4, 5};
    int target = 3;

    Solution * obj = new Solution(nums);
    int index0 = obj->pick(target);
    cout << "find target " << target << " in " << index0 << endl;

    cin.get();
    return 0;
}