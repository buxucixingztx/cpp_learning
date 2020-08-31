// topfive.cpp -- handling an array of string objects
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;
void display(const string [], int);

int main()
{
    string names[SIZE];
    cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << i + 1 << ": ";
        getline(cin, names[i]);
    }

    cout << "Your list:\n";
    display(names, SIZE);
    return 0;
}

void display(const string ar[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << i + 1 << ": " << ar[i] << endl;
}