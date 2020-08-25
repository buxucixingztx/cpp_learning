// 力扣1392题，最长快乐前缀
// 【快乐前缀】是在原字符串中既是非空前缀也是后缀（不包括原字符串自身）的字符串
// 给定一个字符串s，返回它的最长快乐前缀

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution_00{
public:
    string longestPrefix(string s){
        int n = s.size();
        string happy = "";
        for (int i = 1; i < n; ++i)
        {
            string prefix = s.substr(0, i);
            string suffix = s.substr(n-i, i);
            cout << prefix << " | " << suffix << endl;
            if (prefix == suffix)
                happy = prefix;
        }
        return happy;
    };
};

// 方法一：Rabin-Karp字符串编码
class Solution_01{
public:
    string longestPrefix(string s){
        int n = s.size();
        int prefix = 0, suffix = 0;
        int base = 31, mod = 1000000007, mul = 1;
        int happy = 0;
        for (int i = 1; i < n; ++i){
            prefix = ((long long)prefix * base + (s[i - 1] - 97)) % mod;
            suffix = (suffix + (long long)(s[n-i] - 97) * mul) % mod;
            if (prefix == suffix)
                happy = i;
            mul = (long long)mul * base % mod;
        }
        return s.substr(0, happy);
    };
};


// KMP算法
class Solution_02{
public:
    string longestPrefix(string s){
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i)
        {
            int j = fail[i-1];
            while (j != -1 && s[j+1] != s[i])
                j = fail[j];
            if (s[j+1] == s[i])
                fail[i] = j + 1;
        }
        return s.substr(0, fail[n-1]+1);
    }
};



int main()
{
    string s = "acccbaaacccbaac";
    cout << "s: " << s << endl;
    Solution_00 sl00;
    Solution_01 sl01;
    Solution_02 sl02;

    string s00 = sl00.longestPrefix(s);
    cout << "s00: " << s00 << endl;

    string s01 = sl01.longestPrefix(s);
    cout << "s01: " << s01 << endl;

    string s02 = sl02.longestPrefix(s);
    cout << "s02: " << s02 << endl;

    cin.get();

    return 0;
}