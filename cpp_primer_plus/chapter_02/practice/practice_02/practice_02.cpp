// 编写一个C++程序，它要求用户输入一个以long为单位的距离，然后将它转换为码（-long等于220码）

#include <iostream>

int longtoyard(int);

int main()
{
    using namespace std;
    cout << "Enter a int distance(long): ";
    int long_dis;
    cin >> long_dis;
    int yard_dis;
    yard_dis = longtoyard(long_dis);
    cout << "After convert " << long_dis << " is " << yard_dis << " yards.\n";

    return 0;
}

int longtoyard(int l)
{
    return l * 220;
}