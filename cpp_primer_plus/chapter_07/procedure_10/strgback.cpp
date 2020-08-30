// strgback.cpp -- a function that returns a pointer to char
#include <iostream>

char * buildstr(char ch, int n);

int main()
{
    using namespace std;
    int n;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter a integer: ";
    cin >> n;

    char * temp = buildstr(ch, n);
    cout << temp << endl;
    delete [] temp;
    temp = buildstr('+', 20);
    cout << temp << "-DONE-" << temp << endl;

    return 0;
 }

char * buildstr(char ch, int n){
    char *pstr = new char[n+1];
    pstr[n] = '\0';
    while (n-- > 0)
        pstr[n] = ch;
    return pstr;
}