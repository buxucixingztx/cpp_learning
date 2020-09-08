// 力扣第1347题，制造字母异位词的最小步骤数
/*
给你两个长度相等的字符串 s 和 t。每一个步骤中，你可以选择将 t 中的 任一字符 替换为 另一个字符。

返回使 t 成为 s 的字母异位词的最小步骤数。

字母异位词 指字母相同，但排列不同（也可能相同）的字符串。

提示：

1 <= s.length <= 50000
s.length == t.length
s 和 t 只包含小写英文字母
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution_00{
public:
    int minSteps(string s, string t){
        unordered_map<char, int> s_dict;
        int count = 0;
        for (char ss: s)
            s_dict[ss]++;
        for (char tt: t){
            if (s_dict[tt] != 0){
                s_dict[tt]--;
            }
            else
                count++;
        }
        return count;
    }
};


int main()
{
    string s = "bab", t = "aba";
    Solution_00 sl0;
    int result0 = sl0.minSteps(s, t);
    cout << "result0: " << result0 << endl;
    
    cin.get();
    return 0;
}