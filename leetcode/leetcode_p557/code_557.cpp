// 力扣第557题，反转字符串中的单词III
/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
*/
#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

class Solution_00{
public:
    string reverseWords(string s){
        int n = s.size();
        string rs = "";
        int start = 0;
        for (int i = 0; i < n; ++i){
            if (s[i] == ' '){
                for (int j = i-1; j >= start; --j)
                    rs += s[j];
                rs += ' ';
                start = i + 1;
            }
        }
        for (int j = n-1; j >= start; --j)
            rs += s[j];
        cout << "rs: " << rs << endl;
        return rs;
    }
};


class Solution_01{
public:
    string reverseWords(string s){
        int n = s.size();
        int start = 0;
        for (int i = 0; i <= n; ++i){
            if (i == n || s[i] == ' '){
                for (int j = i-1; j > start; --j, ++start){
                    char ch = s[j];
                    s[j] = s[start];
                    s[start] = ch;
                }
                start = i + 1;
            }
        }
        cout << "inplace s: " << s << endl;
        return s;
    }
};


int main()
{
    string s = "let's take LeetCode contest";
    cout << "before reverse s = " << s << endl;

    Solution_00 s00;
    string re00;
    re00 = s00.reverseWords(s);
    cout << "after  reverse s = " << re00 << endl;
    
    Solution_01 s01;
    string re01;
    re01 = s01.reverseWords(s);
    
    cin.get();
    return 0;
}