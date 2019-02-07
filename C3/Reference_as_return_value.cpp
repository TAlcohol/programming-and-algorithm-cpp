#include <iostream>
using namespace std;

int n = 4;
int &SetValue() { return n; } // 函数的返回值的类型是一个整型的引用，也就是n

int main()
{
    SetValue() = 40; // 相当于给n赋值为40
    cout << n;       // 输出n等于40
    return 0;
}
