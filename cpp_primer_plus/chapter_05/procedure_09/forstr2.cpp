// forstr2.cpp -- reversing an array
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string word;
    cout << "Enter a word: ";
    cin >> word;
    int i, j;
    char temp;
    for (j = 0, i = word.size() - 1; i >= j; --i, ++j)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }

    cout << word << endl;
    cout << "Done.\n";
    
    return 0;
}