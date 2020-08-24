// not.cpp -- using the not operator
#include <iostream>
#include <climits>

bool is_int(double);

int main()
{
    using namespace std;

    cout << "Yo, dude! Enter an integer value: ";
    double num;
    cin >> num;
    while (!is_int(num))
    {
        cout << "Out of range -- please try again: ";
        cin >> num;
    }
    int val = int(num);
    cout << "You've entered the integer " << val << endl;

    return 0;
}

bool is_int(double x)
{
    if (x <= INT_MAX && x >= INT_MIN)
        return true;
    else 
        return false;
}