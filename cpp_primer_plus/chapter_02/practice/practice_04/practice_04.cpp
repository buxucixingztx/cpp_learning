// 编写一个程序，其中的main()调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值）。
// 该程序按下面的格式要求用户输入摄氏温度值，并显示结果：
// Please enter a Celsius value: 20
// 20 degrees Celsius is 68 degrees Fahrenheit.
// 下面是转换公式：
// 华氏温度 = 1.8 x 摄氏温度 + 32.0

#include <iostream>

double cel_to_fah(double);

int main()
{
    using namespace std;
    double cel_deg;
    cout << "Please enter a Celsius value: ";
    cin >> cel_deg;
    double fah_deg = cel_to_fah(cel_deg);
    cout << cel_deg << " degrees Celsius is " << fah_deg << " degrees Fahrenheit.\n";

    return 0;
}

double cel_to_fah(double cel)
{
    return 1.8 * cel + 32.0;
}