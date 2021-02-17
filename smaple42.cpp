// 友元类

#include <iostream>

using namespace std;

class A
{
private:
    int x, y;

public:
    A(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    friend class B;
};

class B
{
private:
    int x, y;

public:
    B(A a)
    {
        x = a.x;
        y = a.y;
    }

    void print()
    {
        cout << x << " " << y << endl;
    }
};

int main(int argc, char** argv)
{
    A* a = new A(1, 2);
    B* b = new B(*a);
    b->print();

    return 0;
}