// 力扣第3题，无重复字符的最长子串
/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s){
        string sub_s = "";
        int n = s.size();
        int max_length = 0;
        for (int i = 0; i < n; i++){
            
            if (sub_s.find(s[i] != s.npos)){
                if (sub_s.size() > max_length)
                    max_length = sub_s.size();
                sub_s = sub_s.substr(sub_s.find(s[i]) + 1);
            }
            sub_s.push_back(s[i]);
        }
        if (sub_s.size() > max_length){
            max_length = sub_s.size();
        }
        return max_length;
    }
};


int main()
{
    string s = "abcabcbb";
    
    Solution s00;
    int max_length = s00.lengthOfLongestSubstring(s);
    cout << "max substr length of string s = " << max_length << endl;
    
    cin.get();
    return 0;
}

