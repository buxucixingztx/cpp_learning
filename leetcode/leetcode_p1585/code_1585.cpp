// 力扣第1585题， 检查字符串是否可以通过排序子字符串得到另一个字符串
/*
给你两个字符串 s 和 t ，请你通过若干次以下操作将字符串 s 转化成字符串 t ：

选择 s 中一个 非空 子字符串并将它包含的字符就地 升序 排序。
比方说，对下划线所示的子字符串进行操作可以由 "14234" 得到 "12344" 。

如果可以将字符串 s 变成 t ，返回 true 。否则，返回 false 。

一个 子字符串 定义为一个字符串中连续的若干字符
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <string>
using namespace std;

class Solution{
public:
    bool isTransformable(string s, string t){
        if (s.size() != t.size())
            return false;
        int s_len = s.size();
        unordered_map<int, deque<int>> s_dict;
        for (int i = 0; i < s_len; i++){
            s_dict[s[i]-'0'].emplace_back(i);
        }

        for (int i = 0; i < s_len; i++){
            int num = t[i]-'0';
            if (s_dict[num].empty())
                return false;
            for (int j = 0; j < num; j++){
                if (!s_dict[j].empty() && s_dict[j][0] < s_dict[num][0])
                    return false;
            }
            s_dict[num].pop_front();
        }

        return true;
    }
};


int main()
{
    string s = "84532";
    string t = "34852";

    Solution sl;
    bool result = sl.isTransformable(s, t);
    cout << "string s = " << s << ", t = " << t << endl;
    cout << "result = " << boolalpha << result << endl;

    cin.get();
    return 0;
}
