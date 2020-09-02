// 力扣第231题，2的幂
/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/

#include <iostream>
using namespace std;

class Solution_00{
public:
    bool isPowerOfTwo(int n){
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        int i = 1;
        while (i < n){
            i *= 2;
            if (i == n)
                return true;
        }
        return false;
    }
};

class Solution_01
{
public:
    bool isPowerOfTwo(int n){
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        int i = 1;
        while (i < n){
            i = i << 1;
            if (i == n)
                return true;
        }
        return false;
    }
};

class Solution_02
{
public:
    bool isPowerOfTwo(int n){
        if (n < 1)
            return false;
        if (n == 1)
            return true;
        while (true){
            int l = n % 2;
            if (l != 0)
                return false;
            n /= 2;
            if (n == 1)
                return true;
        }
    }
};


int main()
{
    Solution_00 s00;
    int n = 1825;
    cout << n << " is power of 2 in solution0: " << boolalpha << s00.isPowerOfTwo(n) << endl;

    Solution_01 s01;
    cout << n << " is power of 2 in solution1: " << boolalpha << s01.isPowerOfTwo(n) << endl;

    Solution_02 s02;
    cout << n << " is power of 2 in solution2: " << boolalpha << s02.isPowerOfTwo(n) << endl;

    cin.get();
    return 0;
}