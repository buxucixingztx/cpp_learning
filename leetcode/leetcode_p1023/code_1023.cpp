// 力扣第1023题，驼峰式匹配
/*
如果我们可以将小写字母插入模式串 pattern 得到待查询项 query，那么待查询项与给定模式串匹配。
（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）

给定待查询列表 queries，和模式串 pattern，返回由布尔值组成的答案列表 answer。
只有在待查项 queries[i] 与模式串 pattern 匹配时， answer[i] 才为 true，否则为 false。
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        if (queries.size() == 0)
            return {};
        
        vector<bool> result;
        int np = pattern.size();
        for (string query: queries){
            int ip = 0;
            bool flag = false;
            for (int iq = 0; iq < query.size(); iq++){
                char q = query[iq];
                if (q == pattern[ip])
                    ip++;
                else if (isupper(q)){
                    flag = true;
                    break;
                }
            }
            if (ip != np || flag)
                result.emplace_back(false);
            else 
                result.emplace_back(true);
        }
        return result;
    }
};


int main()
{
    vector<string> queries = {"IXfGawluvnCa","IsXfGaxwulCa","IXfGawlqtCva","IXjfGawlmeCa","IXfGnaynwlCa","IXfGcamwelCa"};
    string pattern = "IXfGawlCa";

    Solution sl;
    vector<bool> result = sl.camelMatch(queries, pattern);
    for (auto r:result)
        cout << boolalpha << r << ' ';
    cout << endl;

    cin.get();
    return 0;
}



