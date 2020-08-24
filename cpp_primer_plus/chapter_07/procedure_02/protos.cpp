// protos.cpp -- using prototypes and function calls
#include <iostream>

void cheers(int);
double cube(double x);

int main()
{
    using namespace std;
    cheers(5);
    cout << "Give me a number: ";
    double n;
    cin >> n;
    cout << "A " << n << "-foot cube has a volume of ";
    cout << cube(n) << " cubic feet.\n";
    cheers(cube(2));
    cout << endl;

    return 0;
}

void cheers(int n)
{
    using namespace std;
    for (int i = 0; i < n; i ++)
        cout << "Cheers! ";
    cout << endl;
}

double  cube(double x)
{
    return x * x * x;
}