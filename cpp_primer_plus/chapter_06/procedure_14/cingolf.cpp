// cingolf.cpp -- non-numeric input skipped
#include <iostream>

const int Max = 5;

int main()
{
    using namespace std;
    int score[Max];

    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";

    for (int i = 0; i < Max; i++)
    {
        cout << "round #" << i + 1<< ": ";
        while (!(cin >> score[i]))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Please enter a number: ";
        }
    }

    double total = 0.0;
    for (int i = 0; i < Max; i++)
        total += score[i];

    cout << total / Max << " = average score " << Max << " rounds.\n";

    return 0;
}