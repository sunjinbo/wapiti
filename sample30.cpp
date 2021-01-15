// 静态变量

#include <iostream>

using namespace std;

int getNum();
static int num = 10;

int main()
{
    cout << num << endl;

    static int num = 11;

    cout << num << endl;

    num += 1;

    cout << num << endl;

    for (int i = 0; i < 3; ++i)
    {
        cout << getNum() << endl;
    }

    return 0;
}

int getNum()
{
    static int num = 13;

    return num++;
}
