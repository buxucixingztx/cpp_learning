// 力扣201题，数字范围按位与
#include <iostream>

int main()
{
    using namespace std;
    int m = 7;
    int n = 5;
    int shift = 0;

    while (m != n)
    {
        m = m >> 1;
        n = n >> 1;
        shift ++;
    }
    int result = m << shift;
    cout << "result = " << result << endl;
    return 0;
}