// 1.3 返回一个reference指向local static对象

/* 
在程序的单线程启动阶段手工调用所有reference-returning 函数。
*/
#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton& getInstance();

private:
    Singleton(){}
    Singleton(const Singleton&) = delete;               // 明确拒绝
    Singleton& operator=(const Singleton&) = delete;    // 明确拒绝
};


Singleton& Singleton::getInstance()
{
    static Singleton singleton;
    return singleton;
}


int main()
{
    Singleton& sl = Singleton::getInstance();
    cout << "sl = " << &sl << endl;

    Singleton& sl1 = Singleton::getInstance();
    cout << "sl1 = " << &sl1 << endl;

    Singleton& sl2 = Singleton::getInstance();
    cout << "sl2 = " << &sl2 << endl;

    cin.get();
    return 0;
}