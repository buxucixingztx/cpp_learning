// 力扣第60题，第k个排列
/*
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution_00{
public:
    string getPermutation(int n, int k){
        vector<int> fact_list(1, 1);
        vector<char> store_list;
        int fact = 1;
        for (int i = 1; i <= n; i++){
            fact *= i;
            fact_list.push_back(fact);
            store_list.push_back(char(48+i));
        }
        string result = "";
        for (int i = 1; i <= n; i++){
            if (k == 1){
                for (char ch: store_list)
                    result += ch;
                break;
            }
            int index = (k - 1) / fact_list[n-i];
            result += store_list[index];
            store_list.erase(store_list.begin()+index);
            k = k - fact_list[n-i]*index;
        }
        // cout << "result: " << result << endl;
        return result;
    }
};

int main()
{
    Solution_00 sl0;
    int n = 4;
    int k = 9;
    string result = sl0.getPermutation(n, k);
    cout << "result: " << result << endl;

    // vector<int> ff(1, 1);
    // cout << "ff.size() " << ff.size() << endl;
    // cout << "ff[0]: " << ff[0] << endl;

    // vector<char> vc;
    // for (int i = 1; i <= 5; ++i){
    //     vc.push_back(char(i+48));
    // }
    // cout << "vc.size() = " << vc.size() << endl;
    // cout << "cv.size() = " << vc.size() << endl;


    cin.get();
    return 0;
}
