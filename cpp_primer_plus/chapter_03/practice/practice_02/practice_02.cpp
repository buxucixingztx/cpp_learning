// 2. 编写一个程序，要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。（使用3个变量来存储这些信息。）
// 该程序报告其BMI(Body Mass Index, 体重指数)。为了计算BMI，该程序以英寸的方式指出用户的身高（1英尺为12英寸），
// 并将以英寸为单位的身高转换为以米为单位的身高（1英寸=0.0254米）。然后，将以磅为单位的体重转换为以千克为单位
// 的体重（1千克=2.2磅）。最后，计算相应的BMI--体重（千克）除以身高（米）的平方。用符合常量表示各种转换因子。

#include <iostream>
const int foot_to_inch = 12;
const double kg_to_pd = 2.2;
const double inch_to_m = 0.0254;

int main()
{
    using namespace std;
    double h_inch;
    double h_foot;
    double w_pound;
    cout << "Please enter your height. " << endl;
    cout << "foot: " << endl;
    cin >> h_foot;
    cout << "inch: " << endl;
    cin >> h_inch;
    cout << "Please enter your weight(pound): " << endl;
    cin >> w_pound;

    double t_h_inch = h_foot * foot_to_inch + h_inch;
    double t_h_m = t_h_inch * inch_to_m;
    double t_w_kg = w_pound / kg_to_pd;

    double bmi = t_w_kg / (t_h_m * t_h_m);
    cout << "your BMI is " << bmi;

    return 0;
}