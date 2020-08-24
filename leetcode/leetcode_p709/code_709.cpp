// 力扣709题，转换成小写字母
#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string str);

int main()
{
    string str = "al&phaBET";
    cout << "row str: " << str << endl;
    string new_str = toLowerCase(str);
    cout << "tolower str: " << new_str << endl;

    cin.get();
    return 0;
}

string toLowerCase(string str)
{
    for (string::iterator i = str.begin(); i != str.end(); i++)
    {
        if (*i <= 90 && *i >= 65)
            *i += 32;
    }
    return str;
}

