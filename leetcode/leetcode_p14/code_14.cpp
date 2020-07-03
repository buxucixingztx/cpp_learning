// 力扣14题
// 编写一个函数来查找字符串数组中的最长公共前缀

#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string> & strs);

int main()
{
    using namespace std;

    vector<string> strs = {"flower","flow","flight"};
    string pres;
    pres = longestCommonPrefix(strs);
    cout << "prefix: " << pres << endl;

    cin.get();

    return 0;
}

std::string longestCommonPrefix(std::vector<std::string> & strs)
{
    using namespace std;
    string prefix = "";
    int index = 0;
    bool flag = false;

    while (strs.size() > 0)
    {
        if (strs[0].size() == index)
        {
            return prefix;
        }
        prefix += strs[0][index];
        for (int i = 0; i < strs.size(); i++)
        {
            if (index > strs[i].size())
            {
                flag = true;
                break;
            }

            if (strs[i][index] != prefix[index])
            {
                flag = true;
                break;
            }
        }

        if (flag)
            return prefix.substr(0, index);
        
        index += 1;
    }

    return "";
}