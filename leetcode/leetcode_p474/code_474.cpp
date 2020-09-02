// 力扣第474题，1和0
/*
在计算机界中，我们总是追求用有限的资源获取最大的收益。

现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。

你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

注意:

给定 0 和 1 的数量都不会超过 100。
给定字符串数组的长度不会超过 600。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        int max_value = 0;
        for (int s = 0; s < strs.size(); ++s){
            int *mn = count_01(strs[s]);
            cout << "mn[0]: " << mn[0] << "mn[1]: " << mn[1] << endl;
            for (int mi = m; mi >= 0; --mi){
                if (mi - mn[0] < 0)
                    break;
                for (int ni = n; ni >= 0; --ni){
                    if (ni - mn[1] < 0)
                        break;
                    // cout << "dp[mi-mn[0]][ni-mn[1]]+1: " << dp[mi-mn[0]][ni-mn[1]]+1 << endl;
                    dp[mi][ni] = max(dp[mi-mn[0]][ni-mn[1]]+1, dp[mi][ni]);
                    if (dp[mi][ni] > max_value)
                        max_value = dp[mi][ni];
                }
            }
            delete [] mn;
        }

        return max_value;
    }

    int *count_01(string s){
        int num0 = count(s.begin(), s.end(), '0');
        int num1 = count(s.begin(), s.end(), '1');
        int * num01 = new int[2]{num0, num1};
        return num01;
    }
};


int main()
{
    string s = "00011";
    int num0 = count(s.begin(), s.end(), '0');
    int num1 = count(s.begin(), s.end(), '1');
    int num2 = count(s.begin(), s.end(), '2');
    cout << "num0 = " << num0 << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    Solution sl;
    int result = sl.findMaxForm(strs, m, n);
    cout << "result: " << result << endl;

    cin.get();
    return 0;
}
