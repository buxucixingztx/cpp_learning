#include <iostream>
#include <cstring>

void fun1();
int fun2();
double fun3();

class A
{
    public:
    static int a;
    int b;
    float c;
    char d;
    int add(int x, int y)
    {
        return x*y;
    }
};
class B
{
};

int main()
{
    using std::cout;
    using std::endl;
    using std::strlen;
    char ss[20] = "0123456789";
    cout << "sizeof(ss) = " << sizeof(ss) << endl;
    cout << "strlen(ss) = " << strlen(ss) << endl;
    
    // char *ss1 = "0123456789";
    // cout << "sizeof(ss1) = " << sizeof(ss1) << endl;
    // cout << "strlen(ss1) = " << strlen(ss1) << endl;
    
    A object;
    cout << "sizeof(object) is " << sizeof(object) << endl;
    int b = object.add(3, 4);
    cout << "sizeof(object) is " << sizeof(object) << endl;

    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(B): " << sizeof(B) << endl;
    // cout << "sizeof(S): " << sizeof(S) << endl;

    return 0;
}

void fun1(){
    std::cout << "void function" << std::endl;
};

int fun2()
{
    return 0;
}

double fun3()
{
    return 0.0;
}
