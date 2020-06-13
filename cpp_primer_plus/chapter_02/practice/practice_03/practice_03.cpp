// 编写一个C++程序，它使用3个用户定义的函数（包括main())，并生成下面的输出：
// Three blind mice
// Three blind mice
// See how they run 
// See how they run 

#include <iostream>

void mice();
void run();

int main()
{
    using namespace std;
    cout << "Let's call some other function.\n";

    mice();
    run();

    return 0;
}

void mice()
{
    std::cout << "Three blind mice\n";
    std::cout << "Three blind mice\n";
}

void run()
{
    std::cout << "See how they run.\n";
    std::cout << "See how they run.\n";
}