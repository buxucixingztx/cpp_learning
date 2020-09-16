// 力扣lcp02，分式化简
/*
有一个同学在学习分式。他需要将一个连分数化成最简分数，你能帮助他吗？

输入：cont = [3, 2, 0, 2]
输出：[13, 4]
解释：原连分数等价于3 + (1 / (2 + (1 / (0 + 1 / 2))))。注意[26, 8], [-13, -4]都不是正确答案。

限制：
cont[i] >= 0
1 <= cont的长度 <= 10
cont最后一个元素不等于0
答案的n, m的取值都能被32位int整型存下（即不超过2 ^ 31 - 1）。
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> fraction(vector<int>& cont){
        if (cont.size() == 0)
            return {};
        int n = cont.size();
        n--;
        int num = cont[n];
        vector<int> result = {num, 1};
        for (int i = n-1; i >= 0; i--){
            num = cont[i] * result[0] + result[1];
            result[1] = result[0];
            result[0] = num;
        }
        return result;
    }
};


int main()
{
    vector<int> cont = {3, 2, 0, 2};
    Solution sl;
    vector<int> result = sl.fraction(cont);
    for (int n: result)
        cout << n << ' ';
    cout << endl;

    cin.get();
    return 0;
}