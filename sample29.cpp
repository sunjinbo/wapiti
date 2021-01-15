// 模版方法

#include <iostream>

using namespace std;

template <typename T>
inline T const& Max (T const& a, T const& b) 
{ 
    return a < b ? b:a; 
}

int main()
{
    int i1 = 10;
    int i2 = 11;

    double d1 = 10.3;
    double d2 = 11.03;

    cout << Max(i1, i2) << endl;
    cout << Max(d1, d2) << endl;

    return 0;
}