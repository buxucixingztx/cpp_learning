// textin3.cpp -- reading chars to end of file
#include <iostream>

int main()
{
    using namespace std;

    char ch;
    int count = 0;
    
    while (cin.get(ch).fail() == false)
    {
        cout << ch;
        ++count;
    }

    cout << endl << count << " characters read.\n";
    return 0;
}