// and.cpp -- using the logical AND operator
#include <iostream>
int const ArSize = 6;

int main()
{
    using namespace std;

    int i = 0;
    int temp;
    float naaq[ArSize];

    cout << "Enter the NAAQs (New Age Awareness Quotients) of\n"
              << "your neightbors. Program terminates when you make "
              << ArSize << " entries or enter a negative value.\n";

    cout << "First value: ";
    cin >> temp;
    while (i < ArSize && temp >= 0)
    {
        naaq[i] = temp;
        ++i;
        if (i < ArSize)
        {
            cout << "Next value: ";
            cin >> temp;
        }
    }
    if (i == 0)
        cout << "No data -- bye\n";
    else
    {
        float you;
        cout << "Enter your NAAQ: ";
        cin >> you;

        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (naaq[j] > you)
                ++count;
        }
        cout << count << " of your neighbors have greater awareness of \nthe New Age than you do.\n";
    }
    
    return 0;
}