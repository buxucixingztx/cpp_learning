// 力扣第214题，最短回文串
/*
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字符串哈希编码
class Solution_01{
public:
    string shortestPalindrome(string s){
        int n = s.size();
        string new_s = "";
        int base = 131;
        long long mod = 1000000000 + 7;
        long long left, right;
        left = right = 0;
        int best = -1;
        long long mul = 1;
        for (int i = 0; i < n; i++){
            left = (left * base +  int(s[i])) % mod;
            right = (int(s[i]) * mul + right) % mod;
            if (left == right)
                best = i;
            mul = mul * base % mod;
        };
        // cout << "best: " << best << endl;
        for (int b = n-1; b > best; --b)
                new_s += s[b];
        // cout << "new_s:" << new_s << endl;
        return new_s + s;
    }
};


// KMP
class Solution_02{
public:
    string shortestPalindrome(string s){
        int n = s.size();
        vector<int> fail(n, -1);
        // cout << "before for loop faiL:" << endl;
        // for (auto p = fail.begin(); p != fail.end(); ++p)
        //     cout << *p << ' ';
        // cout << endl;
        for (int i = 1; i < n; ++i){
            int j = fail[i-1];
            while (j != -1 && s[i] != s[j+1])
                j = fail[j];
            if (s[j+1] == s[i])
                fail[i] = fail[j+1] + 1;
        }
        // cout << "After first for loop fail: " << endl;
        // for (auto p = fail.begin(); p != fail.end(); ++p)
        //     cout << *p << ' ';
        // cout << endl;

        int best = -1;
        for (int i = n-1; i >= 0; --i){
            while (best != -1 && s[best+1] != s[i])
                best = fail[best];
            if (s[best+1] == s[i])
                best += 1;
        }

        // cout << "best: " << best << endl;
        string new_s = "";
        for (int b = n-1; b > best; --b)
            new_s += s[b];

        return new_s + s;
    }
};


int main()
{
    string s = "aacecaaa";
    Solution_01 sl1;
    string result1 = sl1.shortestPalindrome(s);
    cout << "result1: " << result1 << endl;

    // cin.get();
    // for (auto p = s.begin(); p != s.end(); ++p)
    //     cout << *p << ": " << int(*p) << endl;
    // cout << endl;

    // vector<int> f(10, 2);
    // for (auto p = f.begin(); p != f.end(); ++p)
    //     cout << *p << ' ';
    // cout << endl;

    Solution_02 sl2;
    string result2 = sl2.shortestPalindrome(s);
    cout << "result2: " << result2 << endl;

    return 0;
}