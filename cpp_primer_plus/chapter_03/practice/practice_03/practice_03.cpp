// 3. 编写一个程序，要求用户以度、分、秒的方式输入一个维度，然后以度为单位显示该维度。1度为60分，
// 一分等于60秒，请以符合常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。
// 下面是该程序运行时的情况。
// Enter a latitude in degrees, minutes, and seconds:
// First, enter the degrees: 37
// Next, enter the minutes of arc: 51
// Finally, enter the seconds of arc: 19
// 37 degrees, 51 minutes, 19 seconds = 37.8553 degrees

#include <iostream>

const int trans = 60;

int main()
{
    using namespace std;
    int degrees;
    int minutes;
    int seconds;

    cout << "Enter a latitude in degrees, minuts, and seconds: " << endl;
    cout << "First, enter the degrees: ";
    cin >> degrees;
    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;
    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;

    double t_degrees = degrees + double(minutes) / 60 + double(seconds) / 60 / 60;
    cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = "
     << t_degrees << " degrees";

    return 0;
}