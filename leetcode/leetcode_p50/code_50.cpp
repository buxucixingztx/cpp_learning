// 力扣第50题，Pow(x, n)，实现pow(x, n)，即计算x的n次幂函数
#include <iostream>
using namespace std;

class Solution
{
public:
    double halfcal(double x, int N)
    {
        if (N == 0){
            return 1.0;
        }
        double y = halfcal(x, N/2);
        double result = (N % 2 == 0) ? y * y : y * y * x;
        return result;
    }
    double myPow(double x, int n)
    {
        double result = halfcal(x, n);
        return (n > 0) ? result : 1 / result;
    }
};

class Solution_01
{
private:
    double halfcal(double x, long long N)
    {
        double i = x;
        double result = 1.0;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                result *= i;
            }
            i *= i;
            N /= 2;
        }
        return result;
    };

public:
    double myPow(double x, int n)
    {
        long long N = n;
        return (N >= 0) ? halfcal(x, N) : 1 / halfcal(x, -N);
    }
};


int main()
{
    int x = 2.0;
    int n = -2147483648;

    Solution sl;
    double result = sl.myPow(x, n);
    cout << "result = " << result << endl;

    Solution_01 sl1;
    double result1 = sl1.myPow(x, n);
    cout << "result1 = " << result1 << endl;

    cin.get();
    return 0;
}