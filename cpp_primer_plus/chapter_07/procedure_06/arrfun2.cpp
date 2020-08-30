// arrfun2.cpp -- functions with an array argument
#include <iostream>

const int ArSize = 8;
int sum_arr(int [], int n);

int main()
{
    int arr[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    std::cout << arr << " = array address, " << sizeof arr << " = sizeof cookies\n";
    int sum = sum_arr(arr, ArSize);
    std::cout << "Total cookies eaten: " << sum << std::endl;

    sum = sum_arr(arr, 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";

    sum = sum_arr(arr+4, 4);
    std::cout << "Last four eaters ate " << sum << " cookies.\n";

    return 0;
}

int sum_arr(int arr[], int n)
{
    std::cout << arr << " = arr, " << sizeof arr << " = sizeof arr\n";
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    
    return total;
}