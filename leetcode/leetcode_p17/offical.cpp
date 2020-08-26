// 官方题解，使用回溯的方法
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> letterCombinations(string digits);
void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string & combination);

int main()
{
    string digits = "23";
    vector<string> com = letterCombinations(digits);
    for (auto p = com.begin(); p != com.end(); ++p)
        cout << *p << endl;
    cin.get();
    return 0;
}

vector<string> letterCombinations(string digits){
    vector<string> combinations;
    if (digits.empty())
        return combinations;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "gkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string combination;
    backtrack(combinations, phoneMap, digits, 0, combination);
    return combinations;
}


void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string & combination){
    if (index == digits.length())
        combinations.push_back(combination);
    else
    {
        char digit = digits[index];
        const string & letters = phoneMap.at(digit);
        for (const char& letter: letters){
            combination.push_back(letter);
            backtrack(combinations, phoneMap, digits, index+1, combination);
            combination.pop_back();
        }
    }
    
}


