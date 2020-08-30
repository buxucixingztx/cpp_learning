// arrfun3.cpp -- array functions and const
#include <iostream>

const int Max = 5;

int fill_array(double ar[], int);
void show_array(double ar[], int);
void revalue(double, double ar[], int);

int main()
{
    using namespace std;
    double property[Max];

    int size = fill_array(property, Max);
    show_array(property, size);
    cout << "Enter revaluation factor: ";
    double factor;
    while ( !(cin >> factor))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Bad input; Please enter a number: ";
    }
    revalue(factor, property, size);
    show_array(property, size);
    cout << "Done.\n";

    return 0;
}

int fill_array(double ar[], int n){
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < n; i++){
        cout << "Enter value #" << i + 1 << ": ";
        cin >> temp;
        if (!cin){
            cout << "Bad intpu! ternate!\n";
            break;
        }
        else if (temp < 0)
            break;
        else 
            ar[i] = temp;
    }

    return i;
}

void show_array(double ar[], int n){
    using namespace std;
    for (int i = 0; i < n; i++)
        cout << "Property #" << i << ": $" << ar[i] << endl;
}

void revalue(double factor, double ar[], int n){
    for (int i = 0; i < n; i++)
        ar[i] = ar[i] * factor;
}