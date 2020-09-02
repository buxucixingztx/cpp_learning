// 力扣第1309题，解码字母到整数映射
/*
给你一个字符串 s，它由数字（'0' - '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：

字符（'a' - 'i'）分别用（'1' - '9'）表示。
字符（'j' - 'z'）分别用（'10#' - '26#'）表示。 
返回映射之后形成的新字符串。

题目数据保证映射始终唯一。
*/
#include <iostream>
#include <string>
using namespace std;


class Solution{
public:
    string freqAlphabets(string s){
        int n = s.size() - 1;
        string des = "";
        while (n >= 0){
            if (s[n] == '#'){
                int num = stoi(s.substr(n-2, n), 0, 10);
                des = char(num+96) + des;
                n -= 2;
            }
            else    
                des = char(s[n]+48) + des;
            n --;
        }
        return des;
    }
};


int main()
{
    string s = "1326#";
    Solution sl;
    string des = sl.freqAlphabets(s);
    cout << "s = " << s << endl;
    cout << "des = " << des << endl;

    cin.get();
    return 0;
}
