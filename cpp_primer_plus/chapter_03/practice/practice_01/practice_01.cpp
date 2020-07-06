// 1. 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸.
// 该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。

#include <iostream>
const int transform = 12;

int main()
{
    using namespace std;
    int ch;
    cout << "please enter your height(inch):______\b\b\b\b\b\b";
    cin >> ch;
    int h_foot = ch / transform;
    int h_inch = ch % transform;
    cout << "your height is " << h_foot << " foot, " << h_inch << " inch." << endl;

    return 0;
}