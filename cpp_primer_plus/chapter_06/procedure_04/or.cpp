// or.cpp -- using the logical OR operator
#include <iostream>

int main()
{
    using namespace std;

    char ch;
    cout << "This program may reformat your hard disk\n"
                << "and destroy all your data.\n"
                << "Do you wish to continue? <y/n> ";
    
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
        cout << "You were warned!\a\a\n";
    else if(ch == 'n' or ch == 'N')
        cout << "A wise choice ... bye\n";
    else 
        cout << "That wasn't a y or n! Apparently you "
                    << " can't follow\ninstructions, so "
                    << "I'll trash your disk anyway.\a\a\n";
    
    return 0;
}