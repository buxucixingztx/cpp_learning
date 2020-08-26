// 力扣第507，寻找完美数
// 对于一个正整数，如果它和除了自身以外的所有正因子之和相等，我们称它为“完美数”

#include<iostream>
using namespace std;

int main()
{
    int number = 120;
    int sum;
    for (int i = 1; i < number/2+1; ++i){
        if (number % i == 0)
            sum += i;
    }

    cout << "number " << number << " | sum = " << sum << endl;

    cin.get();
    
    return 0;
}