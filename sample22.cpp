// 接口和抽象类

#include <iostream>

using namespace std;

// 1，抽象类用于描述现实世界中的抽象概念；
// 2，抽象类只能被继承不能创建对象；
// 3，C++ 中没有抽象类的概念；
// 4，C++ 中通过纯虚函数实现抽象类；
// 5，类中只存在纯虚函数时成为接口；
// 6，接口是一种特殊的抽象类；

class Shape
{
public:
    virtual int getArea() = 0;
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(int r);
    int getArea();
};

Circle::Circle(int r)
{
    radius = r;
}

int Circle::getArea()
{
    return 3.1415926 * radius * radius;
}

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h);
    int getArea();
};

Rectangle::Rectangle(int w, int h)
{
    width = w;
    height = h;
}

int Rectangle::getArea()
{
    return width * height;
}

int main()
{
    Rectangle rectangle(10, 4);
    cout << rectangle.getArea() << endl;

    Shape* circle = new Circle(3);
    cout << circle->getArea() << endl;
    delete circle;

    return 0;
}