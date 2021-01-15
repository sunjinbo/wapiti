// 实现两个数相加

#include <iostream>

using namespace std;

int main()
{
    int firstNumber, secondNumber;

    cout << "Please input two numbers：" << endl;
    cin >> firstNumber >> secondNumber;

    int sum = firstNumber + secondNumber;
    cout << firstNumber << "+" << secondNumber << "=" << sum << endl;

    return 0;
}