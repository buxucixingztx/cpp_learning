// 力扣第一题，两数之和
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

#include <iostream>
#include <vector>
// #include <hash_map>
#include <unordered_map>

std::vector<int> twoSum_one(std::vector<int>& nums, int target);
std::vector<int> twoSum_two(std::vector<int>& nums, int target);
std::vector<int> twoSum_three(std::vector<int>& nums, int target);

int main()
{
    using namespace std;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> indexs_one;
    vector<int> indexs_two;
    vector<int> indexs_three;
    indexs_one = twoSum_one(nums, target);
    indexs_two = twoSum_two(nums, target);
    indexs_three = twoSum_three(nums, target);
    cout << "nums = [";
    for (int i = 0; i < nums.size() - 1; i++)
        cout << nums[i] << ", ";
    cout << nums[nums.size() - 1] << "], target = " << target << endl;

    if (indexs_one.size() > 1)
        cout << "#1 result: [" << indexs_one[0] << ", " << indexs_one[1] << ']' << endl;
    else
        cout << "#1 result.size(): " << indexs_one.size() << endl;

    if (indexs_two.size() == 2)
        cout << "#2 result: [" << indexs_two[0] << ", " << indexs_two[1] << ']' << endl;
    else
        cout << "#2 result.size(): " << indexs_two.size() << endl;

    if (indexs_three.size() == 2)
        cout << "#3 result: [" << indexs_three[0] << ", " << indexs_three[1] << ']' << endl;
    else 
        cout << "#3 result.size(): " << indexs_three.size() << endl;

    cin.get();
    return 0;
}

std::vector<int> twoSum_one(std::vector<int>& nums, int target)
{
    using namespace std;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

std::vector<int> twoSum_two(std::vector<int>& nums, int target)
{
    using namespace std;
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
        m[nums[i]] = i;

    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target-nums[i]) != m.end() && m[target-nums[i]] != i)
            return {i, m[target-nums[i]]};
    }

    return {};
}

std::vector<int> twoSum_three(std::vector<int>& nums, int target)
{
    using namespace std;
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] = i; 
        if (m.find(target-nums[i]) != m.end())
            return {m[target-nums[i]], i};
    }

    return {};    
}

