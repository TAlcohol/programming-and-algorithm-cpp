#include <iostream>
using namespace std;

/*
类型转换构造函数

目的：
实现类型的自动转换

特点：
- 自身是构造函数
- 只有一个参数
- 不是复制构造函数

编译系统会自动调用 --> 转换构造函数
--> 建立一个临时对象/临时变量

*/

class Complex
{
  public:
    double real, imag;
    Complex(int i) //类型转换构造函数
    {
        cout << "IntConstructor called" << endl;
        real = i;
        imag = 0;
    }
    Complex(double r, double i) //构造函数
    {
        real = r;
        imag = i;
    }
};

int main()
{
    Complex c1(7, 8); // 初始化调用的普通的构造函数
    Complex c2 = 12;  // 对c2进行了初始化，等号代表初始化，不是赋值。
    //调用类型转换构造函数时，不生成对象，只把12作为参数传给Complex(int i)来初始化c2
    c1 = 9; // 这是一个赋值语句。编译器不报错。等号左边时Complex类型，右边是int型常量。
    // 编译器自动调用类型转换构造函数。生成一个临时的Complex对象，以9作为实参，调用类型转换构造函数。
    // 变成一个Complex对象，赋值给c1
    cout << c1.real << "," << c1.imag << endl;
    return 0;
}

// 输出：
// IntConstructor called
// IntConstructor called
// 9,0