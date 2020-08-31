// 力扣第528题，按权重随机选择
/*
给定一个正整数数组 w ，其中 w[i] 代表下标 i 的权重（下标从 0 开始），请写一个函数 pickIndex ，它可以随机地获取下标 i，选取下标 i 的概率与 w[i] 成正比。

例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

也就是说，选取下标 i 的概率为 w[i] / sum(w) 。
*/
#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Solution
{
public:
    vector<int> psum;
    int tot = 0;
    mt19937 rng{random_device{} ()};
    uniform_int_distribution<int> uni;

    Solution(vector<int> w){
        for (int x: w){
            tot += x;
            psum.push_back(tot);
        }
        uni = uniform_int_distribution<int> {0, tot - 1};
    }

    int pickIndex(){
        int targ = uni(rng);
        int lo = 0, hi = psum.size() - 1;
        while (lo != hi){
            int mid = (lo + hi) / 2;
            if (targ >= psum[mid]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};


int main()
{
    mt19937 rng{random_device{} ()};
    uniform_int_distribution<int> uni(0, 4);
    for (int i = 0; i < 5; i++)
        cout << uni(rng) << ", ";
    
    cout << endl;

    cin.get();
    return 0;
}

