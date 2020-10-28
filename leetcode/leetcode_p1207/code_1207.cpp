// 力扣第1207题，独一无二的出现次数
/*
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。

如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution{
public:
    bool uniqueOccurrences(vector<int>&arr){
        unordered_map<int, int> count;
        for (auto num: arr){
            count[num]++;
        }
        vector<int> occ;
        for(auto i = count.begin(); i != count.end(); i++){
            for (auto o: occ){
                if (i->second == o){
                    return false;
                }
            }
            occ.emplace_back(i->second);
        }
        return true;
    }
};


class Solution_01{
public:
    bool uniqueOccurrences(vector<int>& arr){
        unordered_map<int, int> count;
        for (auto num: arr){
            count[num]++;
        }
        unordered_set<int> occ;
        for (auto i = count.begin(); i != count.end(); i++){
            occ.insert(i->second);
        }
        return count.size() == occ.size();
    }
};


int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    Solution sl;
    bool result = sl.uniqueOccurrences(arr);
    cout << "Solution result: " << boolalpha << result << endl;

    Solution_01 sl1;
    result = sl1.uniqueOccurrences(arr);
    cout << "Solution_01 result: " << boolalpha << result << endl;

    cin.get();
    return 0;
}
