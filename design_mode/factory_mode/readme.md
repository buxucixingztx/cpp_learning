c++常用设计模式  --- 工厂模式
参考博客：https://www.cnblogs.com/chengjundu/p/8473564.html

在工厂模式中，我们在创建对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的对象。
工厂模式作为一个创建模式，一般在创建复杂对象时，考虑使用；在创建简单对象时，建议直接new完成一个实例对象的创建。

常用的工厂模式有如下三种：

1. 简单工厂模式
主要特点是需要在工厂类中做判断，从而创建相应的产品，当增加新产品时，需要修改工厂类。
使用简单工厂模式，我们只需要知道具体的产品型号就可以创建一个产品。

缺点：工厂类集中了所有产品类的创建逻辑，如果产品量较大，会使得工厂类变得非常臃肿。
关键代码：创建过程在工厂类中完成。
步骤：
    先定义抽象产品类；
    再定义好具体产品类；
    定义工厂类，根据具体产品型号来创建具体的产品类。

注：一个工厂可以根据不同产品型号生成不同的产品。


2. 工厂方法模式
定义一个创建对象的接口，其子类去具体实现这个接口以完成具体的创建工作。如果需要增加新的产品类，只需要扩展一个相应的工厂类即可。

缺点：产品类数据较多时，需要实现大量的工厂类，这无疑增加了代码量。
关键代码：创建过程在其子类执行。
步骤：
    先定义抽象产品类；
    再具体产品类；
    定义抽象工厂类，定义生成抽象产品的虚方法；
    再定义具体工厂类，重载生成产品的方法，用于生成具体的产品实例。

注：一个工厂只生产一种产品。


3. 抽象工厂模式
抽象工厂模式提供创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
当存在多个产品系列，而客户端只使用一个系列的产品时，可以考虑使用抽象工厂模式。

缺点：当增加一个新系列的产品时，不仅需要实现具体的产品类，还需要增加一个新的创建接口，扩展相对困难。
关键代码：在一个工厂里聚合多个同类产品
步骤：
    先定义抽象产品类，比如上衣、裤子；
    再具体产品类，比如黑色上衣、黑色裤子，白色上衣、白色裤子；
    定义抽象工厂类，定义生产相关系列抽象产品的虚方法，比如生产上衣、生产裤子的方法；
    具体工厂类，重载生成产品的方法，用于生成具体的产品实例，比如白色衣服工厂，生成白色上衣和白色裤子。

注：一个工厂可以生产一系列的产品。