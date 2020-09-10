// 力扣第915题，分割数组
/*
给定一个数组 A，将其划分为两个不相交（没有公共元素）的连续子数组 left 和 right， 使得：

left 中的每个元素都小于或等于 right 中的每个元素。
left 和 right 都是非空的。
left 要尽可能小。
在完成这样的分组后返回 left 的长度。可以保证存在这样的划分方法。

提示：
2 <= A.length <= 30000
0 <= A[i] <= 10^6
可以保证至少有一种方法能够按题目所描述的那样对 A 进行划分。
*/
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& vc);

class Solution00{
public:
    int partitionDisjoint(vector<int>& A){
        int leftmax = A[0];
        int findedmax = leftmax;
        int num = 1;
        for (int i = 0; i < A.size(); ++i){
            if (A[i] > findedmax)
                findedmax = A[i];
            if (A[i] < leftmax){
                num = i + 1;
                leftmax = findedmax;
            }
        }
        cout << "left: ";
        print(vector<int>(A.begin(), A.begin()+num+1));

        cout << "right: ";
        print(vector<int>(A.begin()+num+1, A.end()));
        return num;
    }
};


int main()
{
    vector<int> A = {5, 0, 3, 8, 6};
    cout << "A: ";
    print(A);

    Solution00 sl0;
    int result = sl0.partitionDisjoint(A);
    cout << "result: " << result << endl;

    cin.get();
    return 0;
}

void print(const vector<int>& vc){
    for (auto p :vc)
        cout << p << ' ';
    cout << endl;
}
