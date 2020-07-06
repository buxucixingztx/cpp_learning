// 7. 编写一个程序，要求用户按欧洲风格输入汽车的耗油量（每100公里消耗的汽油量（升）），然后将其转换为
// 美国风格的耗油量--每加仑多少英里。注意，除了使用不同的单位计量外，美国方法（距离/燃料）与欧洲方法(燃料/距离)
// 相反。100公里等于62.14英里，1加仑等于3.875升。因此，19mpg大约为12.41/100km, 27mpg大约合8.71/100km。

#include <iostream>

const double gal_to_l = 3.875;
const double km100_to_mile = 62.14;

int main()
{
    using namespace std;
    double consume_gas_e;
    double consume_gas_a;
    cout << "Please enter car's consume(gas per 100km): ";
    cin >> consume_gas_e;
    consume_gas_a = 62.14 / (consume_gas_e / gal_to_l);
    cout << "Your car's consume in mpg is " << consume_gas_a << endl;

    return 0;
}