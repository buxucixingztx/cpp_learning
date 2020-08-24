// switch.cpp -- using the switch statement
#include <iostream>

using namespace std;

void showmenu();
void comfor();
void report();


int main()
{
    showmenu();
    int choice;
    cin >> choice;
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            cout << "\a\n";
            break;

        case 2:
            report();
            break;
        
        case 3:
            cout << "The boss was in all day.\n";
            break;
        
        case 4:
            comfor();
            break;
        
        default:
            cout << "That's not a choice.\n";
        }
        showmenu();
        cin >> choice;
    }
    cout << "Bye!\n";

    return 0;
}

void report()
{
    cout << "It's been an excellent week for business.\n"
                    "Sales are up 120%, Expenses are down 35%.\n";
}

void showmenu()
{
    cout << "Please enter 1, 2, 3, 4, or 5:\n"
                    "1) alarm               2) report\n"
                    "3) alibi                   4) comfort\n"
                    "5) quit\n";
}

void comfor()
{
    cout << "Your employees think you are the finest CEO\n"
                    "in the industry. The board of directors think\n"
                    "your are the finest CEO in the industry.\n";
}
