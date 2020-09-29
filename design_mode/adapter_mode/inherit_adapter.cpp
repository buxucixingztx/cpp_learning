// 2. 使用继承实现适配器模式

#include <iostream>
using namespace std;

// 双端队列，被适配类
class Deque
{
public:
    void push_back(int x)
    {
        cout << " push_back: " << x <<endl;
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
class Stack: public Sequence, private Deque
{
public:
    void push(int x)
    {
        cout << "Stack";
        push_back(x);
    }

    void pop()
    {
        cout << "Stack";
        pop_back();
    }
};

// 队列，先进后出，适配类
class Queue: public Sequence, private Deque
{
public:
    void push(int x)
    {
        cout << "Queue";
        push_back(x);
    }

    void pop()
    {
        cout << "Queue";
        pop_front();
    }
};


int main()
{
    Stack sk;
    sk.push(4);
    sk.pop();
    
    Queue qe;
    qe.push(3);
    qe.pop();

    cin.get();
    return 0;
}