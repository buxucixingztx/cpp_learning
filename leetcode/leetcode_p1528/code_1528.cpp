// 力扣第1528题，重新排列字符串
/*
给你一个字符串 s 和一个 长度相同 的整数数组 indices 。

请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。

返回重新排列后的字符串。
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
单纯的一次遍历交换元素不能实现按索引排序;

所以我们在for循环里面嵌入了一个while循环，
重点可能就是始终让s和indices对应着，所以我们在交换s的同时也对indices进行交换。
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices){
        int n = indices.size();
        for (int i = 0; i < n; i++){
            if (indices[i] == i)
                continue;
            swap(s[i], s[indices[i]]);
            swap(indices[i], indices[indices[i]]);

            while (indices[i] != i){
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        return s;
    }
};


int main()
{
    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    Solution sl;
    string result = sl.restoreString(s, indices);
    cout << result << endl;

    cin.get();
    return 0;
}