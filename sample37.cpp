// 引用

#include <iostream>

using namespace std;

void swap(int& a, int& b) 
{
    a ^= b;
    b ^= a;
    a ^= b;
}

int main(int argc, char** argv)
{
    int a = 3, b = 4;

    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    swap(a, b);

    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;

    return 0;
}