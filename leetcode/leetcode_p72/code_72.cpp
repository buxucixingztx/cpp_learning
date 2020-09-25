// 力扣第72题，编辑距离
/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：
    1. 插入一个字符
    2. 删除一个字符
    3. 替换一个字符
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(const vector<int>&);
void print(const vector<vector<int>>&);

class Solution {
public:
    int minDistance(string word1, string word2){
        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 * n2 == 0)
            return n1 + n2;

        vector<vector<int>> dp(n2+1, vector<int>(n1+1, 0));

        for (int i = 0; i <= n2; i++)
            dp[i][0] = i;
        for (int i = 0; i <= n1; i++)
            dp[0][i] = i;
        
        for (int i = 1; i <= n2; i++)
        {
            int ijv;
            for (int j = 1; j <= n1; j++)
            {
                if (word2[i-1] == word1[j-1])
                    ijv = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]-1}) + 1;
                else 
                    ijv = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                dp[i][j] = ijv;  
            }
        }

        cout << "dp:\n";

        return dp[n2][n1];
    }
};


int main()
{
    string word1 = "horse";
    string word2 = "ros";

    Solution sl;
    int result = sl.minDistance(word1, word2);
    cout << "result = " << result << endl;

    cin.get();
    return 0;
}


void print(const vector<int>& vi)
{
    for (int i: vi)
        cout << i << ' ';
    cout << endl;
}

void print(const vector<vector<int>>& vvi)
{
    for (auto vi: vvi)
    {
        for (auto i:vi)
            cout << i << ' ';
        cout << endl;
    }
    cout << endl;
}
