// 4. 编写一个程序，要求用户以整数方式输入秒数（使用long或long long变量存储），然后以天、小时、分钟和秒
// 的方式显示这段时间。使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多少秒。
// 该程序的输出应与下面类似：
// Enter the number of seconds: 31600000
// 31600000 seconds = 365 days, 17hours, 46 minutes, 40 seconds

#include <iostream>

const int s_to_d = 60 * 60 * 24;
const int s_to_h = 60 * 60;
const int s_to_m = 60;

int main()
{
    using namespace std;
    int long t_seconds;
    int l_seconds;
    cout << "Enter the number of seconds: ";
    cin >> t_seconds;
    int days = t_seconds / s_to_d;
    l_seconds = t_seconds % s_to_d;
    int hours = l_seconds / s_to_h;
    l_seconds = t_seconds % s_to_h;
    int minutes = l_seconds / s_to_m;
    int seconds = l_seconds % s_to_m;

    cout << t_seconds << " seconds = " << days << " days, " << hours << " hours, "
         << minutes << " minutes, " << seconds << " seconds" << endl;
    
    return 0;
}