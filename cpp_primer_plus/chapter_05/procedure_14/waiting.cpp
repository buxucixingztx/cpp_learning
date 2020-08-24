// waiting.cpp -- using clock() in a time_delay loop
#include <iostream>
#include <ctime>

int main()
{
    using namespace std;
    
    cout << "Enter the delay time , in seconds: ";
    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;
    clock_t start = clock();
    cout << "starting \a\n";
    while (clock() - start < delay)
    ;
    cout << "done \a\n";

    return 0;
}