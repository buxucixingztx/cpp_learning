// 力扣第77题，组合
/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution00{
public:
    void findCom(vector<int>sub, vector<int>li, vector<vector<int>>& result, int k){
        if (k == 1){
            for (int v: li){
                sub.push_back(v);
                result.emplace_back(sub);
                sub.pop_back();
            }
            return;
        }
        for (int i = 0; i < li.size(); i++){
            sub.emplace_back(li[i]);
            findCom(sub, vector<int>(li.begin()+i+1, li.end()), result, k-1);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> result;
        vector<int> sub;
        vector<int> li;
        for (int i = 1; i <= n; i++)
            li.emplace_back(i);
        findCom(sub, li, result, k);

        return result;
    }
};


class Solution01{
public:
    void findCom(vector<int>sub, vector<int>&li, vector<vector<int>>& result, int start, int k){
        if (k == 1){
            for (int i = start; i < li.size(); ++i){
                sub.push_back(li[i]);
                result.emplace_back(sub);
                sub.pop_back();
            }
            return;
        }
        for (int i = start; i < li.size(); i++){
            sub.emplace_back(li[i]);
            findCom(sub, li, result, i+1, k-1);
            sub.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> result;
        vector<int> sub;
        vector<int> li;
        for (int i = 1; i <= n; i++)
            li.emplace_back(i);
        int start = 0;
        findCom(sub, li, result, start, k);

        return result;
    }
};

class Solution_02{
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k){
        if (temp.size() + (n - cur + 1) < k){
            return;
        }
        if (temp.size() == k){
            ans.push_back(temp);
        }
        temp.push_back(cur);
        dfs(cur+1, n, k);

        temp.pop_back();
        dfs(cur+1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};


int main()
{
    int n = 3, k = 3;
    Solution00 sl0;
    vector<vector<int>> combination0 = sl0.combine(n, k);
    cout << "combination0:\n";
    for (auto p = combination0.begin(); p != combination0.end(); ++p){
        for (auto sp = (*p).begin(); sp != (*p).end(); ++sp)
            cout << (*sp) << " ";
        cout << endl;
    }

    cout << "-------------------" << endl;

    Solution01 sl1;
    vector<vector<int>> combination1 = sl1.combine(n, k);
    cout << "combination1:\n";
    for (auto p = combination1.begin(); p != combination1.end(); ++p){
        for (auto sp = (*p).begin(); sp != (*p).end(); ++sp)
            cout << (*sp) << " ";
        cout << endl;
    }

    cin.get();
    return 0;
}