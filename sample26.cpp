// 内联函数

#include <iostream>

using namespace std;

class MyTest 
{
private:
    int x;
    int y;
    int z;

public:
    MyTest(int _x, int _y, int _z);

    inline int getX() {return x;}
    inline int getY() {return y;}
    inline int getZ() {return z;}
};

MyTest::MyTest(int _x, int _y, int _z)
{
    x = _x;
    y = _y;
    z = _z;
}

void printXYZ(MyTest* test)
{
    cout << test->getX() << endl;
    cout << test->getY() << endl;
    cout << test->getZ() << endl;
}

int main()
{
    MyTest myTest(1, 2, 3);
    printXYZ(&myTest);

    return 0;
}