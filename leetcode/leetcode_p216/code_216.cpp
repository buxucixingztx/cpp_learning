// 力扣地216题，组合总和III
/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


void print(vector<vector<int>> vv){
    for (int i = 0; i < vv.size(); i++){
        for (int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << ' ';
        cout << endl;
    }
}


class Solution_00{
public:
    vector<int> sub;
    vector<vector<int>> result;
    void dfs(int k, int t, int i){
        if (k == 0 && t == 0){
            result.emplace_back(sub);
            return;
        }
        
        if (k <= 0 || t < 0 || i > 9 || i > t)
            return;
        dfs(k, t, i+1);
        sub.emplace_back(i);
        dfs(k-1, t-i, i+1);
        sub.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n){
        dfs(k, n, 1);
        return result;
    }
};

// 二进制（子集）枚举
/*
使用二进制枚举所有的状态。原序列中有9个数，每个数都有两种状态，[被选择]和[不被选择]，状态总数为2^9。

我们使用一个9位二进制数mask来记录当前所有位置的状态，从低到高第i位为0表示i不被选择到子集中，为1表示i被选择到子集中。
当按顺序枚举[0, 2^9-1]中的所有整数时，就可以不重不漏地把每个状态枚举到，对于一个状态mask，我们可以用位运算的方法得到对应的子集序列，
然后再判断是否满足上面的两个条件，如果满足，就记录答案。

通过位运算来判断是否选择当前的数字，对第i个位置，判断(1 << i) & mask是否为0，如果不为0则说明i在子集当中。
*/
class Solution_01{
public:
    vector<int> temp;
    vector<vector<int>> ans;

    bool check(int mask, int k , int n){
        temp.clear();
        for (int i = 0; i < 9; i++){
            int j = 1 << i;
            if ((1 << i) & mask){
                temp.push_back(i + 1);
            }
        }
        return temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == n;
    }

    vector<vector<int>> combinationSum3(int k , int n){
        for (int mask = 0; mask < (1 << 9); ++mask){
            if (check(mask, k ,n)){
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};


class Solution_02{
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k, int sum){
        if (temp.size() + (n - cur + 1) < k || temp.size() > k)
            return;
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum){
            ans.emplace_back(temp);
            return;
        }
        temp.emplace_back(cur);
        dfs(cur + 1, n, k, sum);;
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n){
        dfs(1, 9, k, n);
        return ans;
    }
};


int main()
{
    Solution_00 sl0;
    vector<vector<int>> result0 = sl0.combinationSum3(3, 7);
    cout << "result0:\n";
    print(result0);

    Solution_01 sl1;
    cout << "\nconstructure Solution_01:\n";
    vector<vector<int>> result1 = sl1.combinationSum3(3, 7);
    cout << "result1:\n";
    print(result1);

    Solution_02 sl2;
    cout << "\nconstructure Solution_02:\n";
    vector<vector<int>> result2 = sl2.combinationSum3(3, 7);
    cout << "result2:\n";
    print(result1);

    cin.get();
    return 0;
}

