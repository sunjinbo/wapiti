// 重载、覆盖、重写

// Overwrite(重写)：是指派生类的函数屏蔽了与其同名的基类函数，规则如下：
// （1）如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏（注意别与重载混淆）。
// （2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏（注意别与覆盖混淆）。

#include <iostream>

using namespace std;

class A
{
public:
    virtual void print()
    {
        cout << "this is A." << endl;
    }

    virtual void test() 
    {
        cout << "this is Test." << endl;
    }

    void ok() {
        cout << "this is Ok." << endl;
    }
};

class B : public A
{
public:
    virtual void print() override
    {
        cout << "this is B." << endl;
    }

    void test(int a)
    {
        cout << "this is Test." << endl;
    }

    void ok() {
        cout << "this is NOT Ok." << endl;
    }
};

int main()
{
    A a;
    a.print();
    a.test();
    a.ok();
    B b;
    b.print();
    b.test(2);
    // b.test(); // compile error, 如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏
    b.ok();
}