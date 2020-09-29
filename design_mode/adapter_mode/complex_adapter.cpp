// 1. 使用复合实现适配器模式

/*
关键代码：适配器继承或依赖已有的对象，实现想要的目标接口。
以下示例中，假设我们之前有了一个双端队列，新的需求要求使用栈和队列来完成。
双端队列可以在头尾删除或增加元素。而栈是一种先进后出的数据结构，添加数据时添加到栈的顶部，
删除数据时先删除栈顶部的数据。因此我们完全可以将一个现有的双端队列适配成一个栈。
*/
#include <iostream>
using namespace std;


// 双端队列，被适配类
class Deque
{
public:
    void push_back(int x)
    {
        cout << " push_back: " << x << endl;
    }
    void push_front(int x)
    {
        cout << " push_front: " << x << endl;
    }
    void pop_back()
    {
        cout << " pop_back!" << endl;
    }
    void pop_front()
    {
        cout << " pop_front!" << endl;
    }
};


// 顺序类，抽象目标类
class Sequence
{
public:
    virtual void push(int x) = 0;
    virtual void pop() = 0;
};

// 栈，后进先出，适配类
class Stack: public Sequence
{
public:
    Stack(Deque dq): m_deque(dq){}

    // 将元素添加到堆栈的顶部
    void push(int x) override
    {
        cout << "Stack";
        m_deque.push_back(x);
    }

    // 从堆栈中删除顶部元素
    void pop() override
    {
        cout << "Stack";
        m_deque.pop_back();
    }

private:
    Deque m_deque;
};

// 队列，先进先出，适配类
class Queue: public Sequence
{
public:
    Queue(Deque dq): m_deque(dq){};

    // 将元素添加到队列尾部
    void push(int x) override
    {
        cout << "Queue";
        m_deque.push_back(x);
    }
    void pop() override
    {
        cout << "Queue";
        m_deque.pop_front();
    }

private:
    Deque m_deque;
};


int main()
{
    Deque dq;

    Stack* sk = new Stack(dq);
    sk->push(4);
    sk->pop();

    Queue* qe = new Queue(dq);
    qe->push(3);
    qe->pop();

    delete sk;
    sk = nullptr;

    delete qe;
    qe = nullptr;
    
    cin.get();
    return 0;
}