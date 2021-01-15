// 友元函数

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
        
        friend void printXYZ(MyTest test);
};

MyTest::MyTest(int _x, int _y, int _z)
{
    x = _x;
    y = _y;
    z = _z;
}

void printXYZ(MyTest test)
{
    cout << test.x << endl;
    cout << test.y << endl;
    cout << test.z << endl;
}

int main()
{
    MyTest myTest(2,3,4);
    printXYZ(myTest);

    MyTest* pMyTest = new MyTest(5,5,6);
    printXYZ(*pMyTest);

    return 0;
}