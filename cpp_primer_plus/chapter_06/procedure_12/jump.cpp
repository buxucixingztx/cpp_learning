// jump.cpp -- using continue and break
#include <iostream>

const int ArSize = 80;

int main()
{
    using namespace std;
    char line[ArSize];
    int spaces = 0;

    cout << "Enter a line of text:\n";
    cin.getline(line, ArSize);
    cout << "Complete line:\n";
    cout << line << endl;
    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];
        if (line[i] == '.')
            break;
        if (line[i] != ' ')
            continue;
        ++spaces;
    }
    cout << '\n' << spaces << " spaces.\n";

    cout << "Done.\n";
    
    return 0;
}