// convert.cpp -- converts stone to pounds
#include <iostream>

int stonetolib(int);

int main()
{
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
    int pounds;
    pounds = stonetolib(stone);
    cout << stone << " stone = " << pounds << " pounds." << endl;

    return 0; 
}

int stonetolib(int sts)
{
    return 14 * sts;
}