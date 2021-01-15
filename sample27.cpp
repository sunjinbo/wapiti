// 宏定义

#include <iostream>

using namespace std;

#define MAX_MACRO true
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a>b?b:a

int main()
{
#if MAX_MACRO
    int max = MAX(10, 9);
    cout << max << endl;
#else
    int min = MIN(10, 9);
    cout << min << endl;
#endif // 

    return 0;
}