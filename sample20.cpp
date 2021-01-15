// 函数指针

#include <iostream>

using namespace std;

int foo();
double goo();
int hoo(int x);

int main()
{
    // 给函数指针赋值
    int (*funcPtr1)() = foo; // 可以
    //int (*funcPtr2)() = goo; // 错误！返回值不匹配！
    double (*funcPtr4)() = goo; // 可以
    //funcPtr1 = hoo; // 错误，因为参数不匹配，funcPtr1只能指向不含参数的函数，而hoo含有int型的参数
    int (*funcPtr3)(int) = hoo; // 可以，所以应该这么写

    return 0;
}

int foo()
{
    return 1;
}

double goo()
{
    return 3.14;
}

int hoo(int x)
{
    return x * x;
}
