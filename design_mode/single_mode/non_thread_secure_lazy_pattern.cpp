// 1.1 非线程安全的懒汉单例模式

#include <iostream>
using namespace std;

/*
关键代码：构造函数是私有的，不能通过赋值运算，拷贝构造等方式实例化对象。
*/

// 懒汉式一般实现：非线程安全，getInstance返回的实例指针需要delete
class Singleton
{
public:
    static Singleton* getInstance();
    ~Singleton(){}

private:
    Singleton(){};                                           // 构造函数私有
    Singleton(const Singleton& obj) = delete;                // 明确拒绝
    Singleton& operator=(const Singleton& obj) = delete;     // 明确拒绝

    static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
    if (m_pSingleton == NULL)
    {
        m_pSingleton = new Singleton;
    }
    return m_pSingleton;
}


int main()
{
    Singleton* sl = Singleton::getInstance();
    cout << "sl: " << sl << endl;

    Singleton* sl1 = Singleton::getInstance();
    cout << "sl1: " << sl1 << endl;


    cin.get();
    return 0;
}