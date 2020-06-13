// ourfunc.cpp -- defining your own function

#include <iostream>
void simon(int);

int main()
{
    using namespace std;
    simon(3);
    int count;
    cin >> count;
    simon(count);
    return 0;
}

void simon(int n)
{
    using namespace std;
    cout << "Simon syas touch your toes " << n << " times." << endl;
}