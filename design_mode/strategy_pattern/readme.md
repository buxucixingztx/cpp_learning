c++常用设计模式  --- 策略模式
参考博客：https://www.cnblogs.com/chengjundu/p/8473564.html

策略模式是值定义一系列的算法，把它们单独封装起来，并且使它们可以相互替换，使得算法可以独立于使用它的客户端而变化，
也就是说这些算法所完成的功能类型是一样的，对外接口也是一样的，只是不同的策略为不同的环境角色表现出不同的行为。

相比于使用大量的if...else，使用策略模式可以降低复杂度，使得代码更容易维护。

缺点：可能需要定义大量的策略类，并且这些策略类都要提供给客户端。
[环境角色]持有一个策略类的引用，最终给客户端调用。

1. 传统的策略模式实现
关键代码：实现同一个接口。
步骤：
    先定义抽象策略类，提供一个公共的虚函数接口；
    再具体策略类，实现具体的虚函数；
    再定义环境角色类，传入策略类的指针参数，


2. 使用函数指针实现策略模式
使用函数指针代替策略类
步骤：
    先定义具体的策略函数；
    再定义环境角色类，环境角色类可以接受不同的策略函数指针，并调用策略函数。