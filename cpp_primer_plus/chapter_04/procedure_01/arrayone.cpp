// arrayone.cpp -- small arrays of integers
#include <iostream>

int main()
{
    using namespace std;
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 6;

    int yamcosts[3] = {20, 30, 5};  
    cout << "Total yams = " << yams[0] + yams[1] + yams[2] << endl;
    cout << "The package with " << yams[1] << " yams costs " << yamcosts[1] << " cents per yam.\n";
    cout << "The total yam expense is " << yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2]
        << " cents.\n";
    
    cout << "Size of yams array = " << sizeof yams << " bytes.\n";
    cout << "Size of one element = " << sizeof yams[0] << " bytes.\n";

    return 0;
}