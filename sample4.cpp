// 实现两个数相加

#include <iostream>

using namespace std;

int main()
{
    // 使用 C++ 获取用户的输入两个数字，并将两个数字相加，然后输出到屏幕
    int firstNumber, secondNumber;

    cout << "Please input two numbers:" << endl;
    cin >> firstNumber >> secondNumber;

    int sum = firstNumber + secondNumber;
    cout << firstNumber << "+" << secondNumber << "=" << sum << endl;

    return 0;
}