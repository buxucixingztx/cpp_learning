// textin1.cpp -- reading chars with a while loop
#include <iostream>

int main()
{
    using namespace std;
    char ch;
    int count;
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;
    while (ch != '#')
    {
        cout << ch;
        cin >> ch;
        count ++;
    }

    cout << endl << count << " characters read\n";
    return 0;
}