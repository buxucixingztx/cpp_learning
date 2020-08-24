// lotto.cpp -- probability of winning
#include <iostream>

using namespace std;

long double probability(unsigned numbers, unsigned picks);

int main()
{
    int total;
    int choices;

    cout << "Enter the total number of choices on the game card and \n";
    cout << "the number of picks allowed:\n";
    while (cin >> total >> choices && choices <=total)
    {
        cout << "You have one chance in " << probability(total, choices) << " of winning.\n";
        cout << "Next tow numbers (q to quit): ";
    }

    cout << "bye.\n";

    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double total=1.0;
    double p;
    int n;
    for (n = numbers, p = picks; p > 0; --p, --n)
        total = total * n / p;
    return total;
}