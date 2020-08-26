// 力扣第17题，电话号码的字母组合
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits);


int main()
{
    string digits = "23";
    string alpha = "abc";
    cout << "digits: " << digits << endl;
    cout << "alpha: " << alpha << endl;
    cout << digits[0] << "= " << int(digits[0]) << endl;
    cout << alpha[0] << "= " << int(alpha[0]) << endl;
    letterCombinations(digits);
    cin.get();
    return 0;
}


vector<string> letterCombinations(string digits){
    int length = digits.size();
    vector<string> char_list = {""};
    for (int i = 0; i < length; ++i){
        vector<char> alpha;
        vector<string> temp = char_list;
        char_list.clear();
        if (digits[i] == '7'){
            for (int j = 0; j < 4; ++j)
                alpha.push_back(char(97+5*3+j));
        }
        else if(digits[i] == '8'){
            for (int j = 0; j < 3; ++j)
                alpha.push_back(char(97+6*3+1+j));
        }
        else if (digits[i] == '9'){
            for (int j = 0; j < 3; ++j)
                alpha.push_back(char(97+7*3+1+j));
        }
        else if (digits[i] < '7' && digits[i] > '1')
        {
            for (int j = 0; j < 3; ++j)
                alpha.push_back(char(97+(int(digits[i])-50)*3+j));
        }
        for (auto p = alpha.begin(); p != alpha.end(); ++p){
            for (auto q = temp.begin(); q != temp.end(); ++q){
                string qp = *q + *p;
                char_list.push_back(qp);
                cout << qp << ", ";
            }
            cout << endl;
        }
    }

    return char_list;
}
