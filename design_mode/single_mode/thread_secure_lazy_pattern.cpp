// 1.2 线程安全的懒汉单例模式

#include <iostream>
#include <mutex>
#include <thread>
// std::mutex mt;
using namespace std;


class Singleton
{
public:
    static Singleton* getInstance();

private:
    Singleton(){}                                       // 构造函数私有
    Singleton(const Singleton&) = delete;               // 明确拒绝
    Singleton& operator=(const Singleton&) = delete;    // 明确拒绝

    static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
    if (m_pSingleton == NULL)
    {
        // mt.lock();
        if (m_pSingleton == NULL)
        {
            m_pSingleton = new Singleton();
        }
        // mt.unlock();
    }
    return m_pSingleton;
}


int main()
{
    Singleton* sl = Singleton::getInstance();
    cout << "sl = " << sl << endl;

    Singleton* sl1 = Singleton::getInstance();
    cout << "sl1 = " << sl1 << endl;

    Singleton* sl2 = Singleton::getInstance();
    cout << "sl2 = " << sl2 << endl;

    cin.get();
    return 0;
}

/* 
注：
在windows下，使用mutex会报错，但逻辑基本上是这样的。

但这种单例模式实现方式多线程可能存在不确定性：任何一种non-const static对象，不论它是local或non-local，在多线程环境下
“等待某事发生”都会有麻烦。
解决的方法：在程序的单线程启动阶段手工调用所有reference-returning函数。这种实现方法的好处是不需要去delete它。
*/

