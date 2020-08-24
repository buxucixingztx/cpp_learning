// sumafile.cpp -- functions with an array argument
#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{
    using namespace std;

    char filename[50];
    cout << "Enter name of data file: " << endl;
    cin.getline(filename, 50);

    ifstream inFile;
    inFile.open(filename);
    if (! inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double item;
    double total = 0.0;
    int count = 0;

    inFile >> item;
    while (inFile.good())
    {
        total += item;
        count++;
        inFile >> item;
    }
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else 
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";

    else
    {
            cout << "Items read: " << count << endl;
            cout << "Sum: " << total << endl;
            cout << "Average: " << total / count << endl;
    }

    inFile.close();

    return 0;
}