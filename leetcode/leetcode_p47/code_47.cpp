// 力扣第47题，全排列
/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void print(vector<int>&);
void print(vector<vector<int>>&);

class Solution {
public:
    vector<vector<int>> result;
    int length;
    void dfs(unordered_map<int, vector<int>>& nd, vector<int>& l){
        if (l.size() == length)
            result.emplace_back(l);
        else
        {
            for (auto p = nd.begin(); p != nd.end(); p++){
                if (p->second.size() != 0){
                    l.emplace_back(p->first);
                    (*p).second.pop_back();
                    dfs(nd, l);
                    (*p).second.emplace_back(p->first);
                    l.pop_back();
                }
            }
        }
        
    };

    vector<vector<int>> permuteUnique(vector<int>& nums){
        length = nums.size();
        unordered_map<int, vector<int>> numdict;
        for (int i : nums)
            numdict[i].emplace_back(i);
        vector<int> l =  {};
        dfs(numdict, l);
        return result;
    }
};


int main()
{
    vector<int> nums = {1, 1, 2};
    cout << "nums:\n";
    print(nums);
    
    Solution sl;
    vector<vector<int>> result = sl.permuteUnique(nums);
    cout << "\npermute:\n";
    print(result);

    cin.get();
    return 0;
}

void print(vector<int> & vi){
    for (auto i: vi)
        cout << i << ' ';
    cout << endl;
}

void print(vector<vector<int>>& vvi){
    for (auto vi = vvi.begin(); vi != vvi.end(); vi++){
        for (auto i: *vi)
            cout << i << ' ';
        cout << endl;
    }
}