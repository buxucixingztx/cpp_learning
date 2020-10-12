// 力扣第1071题，字符串的最大公因子
/*
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2){
        if (str1 + str2 != str2 + str1) return "";
        int n1 = str1.size();
        int n2 = str2.size();
        int n = n1 < n2 ? n1 : n2;
        int gcd = 1;
        for (int i = 2; i <= n; i++){
            if (n1 % i == 0 && n2 % i == 0)
                gcd = i;
        }
        return str1.substr(0, gcd);
    }
};


int main()
{
    string str1 = "ABCABC";
    string str2 = "ABC";

    Solution sl;
    string result = sl.gcdOfStrings(str1, str2);
    cout << "result = " << result << endl;

    cin.get();
    return 0;
}