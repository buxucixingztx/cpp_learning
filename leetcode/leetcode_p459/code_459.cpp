// 力扣459题，重复的子字符串

#include <iostream>
#include <string>
using namespace std;

bool repeatedSubstringPattern(string & s);

int main()
{
    // string s = "abcabcabcabc";
    string s = "aabaaba";
    bool result = repeatedSubstringPattern(s);
    cout << s << endl;
    cout << "result: " << result << endl;

    cin.get();
    return 0;
}


bool repeatedSubstringPattern(string & s)
{
    int length = s.size();
    if (length <= 1)
        return 0;
    string sub_s = "";
    sub_s += s[0];
    for (int i = 1; i < length/2+1; i++)
    {
        bool flag = true;
        if (length % sub_s.size() == 0)
        {
            for (int j = i; j < length; j++)
            {
                if (s[j] != sub_s[j%i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
            cout << sub_s << endl;
            return true;
            }
        }
        
        sub_s += s[i];
    }
    return false;
}
