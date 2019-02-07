#include <iostream>
using namespace std;

class Complex
{
  private:
    double real, imag;

  public:
    void Set(double r, double i);
    Complex(double r, double i);
    Complex(double r);
    Complex(Complex c1, Complex c2);
};
Complex::Complex(double r, double i)
{
    real = r;
    imag = i;
}
Complex::Complex(double r)
{
    real = r;
    imag = 0;
}
Complex::Complex(Complex c1, Complex c2);
{
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
}
Complex c1(3), c2(1, 0), c3(c1, c2);
// c1 = {3,0}, c2 = {1,0}, c3 = {4,0}

//************* 构造函数在数组中的使用 *************//
//************* 构造函数在数组中的使用 *************//
//************* 构造函数在数组中的使用 *************//

class CSample
{
    int x;

  public:
    CSample()
    {
        cout << "Constructor 1 Called" << endl;
    }
    CSample(int n)
    {
        x = n;
        cout << "Constructor 2 Called" << endl;
    }
};

int main()
{
    CSample array1[2]; // 因为没有传参数，这个数组两个元素构造时都选择无参数的构造函数，Constructor 1 Called 输出两次
    cout << "step1" << endl;
    CSample array2[2] = {4, 5}; // 两个对象，有两个参数，Constructor 2 Called 输出两次
    cout << "step2" << endl;
    CSample array3[2] = {3}; // 两个对象，只给了第一个对象的参数，先输出 Constructor 2 Called，在输出 Constructor 1 Called
    cout << "step3" << endl;
    CSample *array4 = new CSample[2]; // new 出来的对象都没有传参数，Constructor 1 Called 输出两次
    delete[] array4;                  // delete 收回空间
    return 0;
}

//************* 另一个例子 *************//
//************* 另一个例子 *************//
//************* 另一个例子 *************//

class Test
{
  public:
    Test(int n) {}        //(1)
    Test(int n, int m) {} //(2)
    Test() {}             //(3)
};

Test array1[3] = {1, Test(1, 2)};
// 三个元素分别用(1),(2),(3)初始化

Test array2[3] = {Test(2, 3), Test(1, 2), 1};
// 分别用(2),(2),(1)

Test *pArray[3] = {new Test(4), new Test(1, 2)};
// 如果只有 Test *pArray[3]，不会生成对象！pArray因为是一个指针数组，不是一个对象数组，指针可以不初始化的，对象需要初始化

// 两个元素，分别用(1),(2)初始化，其中最后一个元素pArray[2]，是一个指针，不知道指向哪，pArray[2]这个元素的生成不会导致任何对象的生成。
// pArray[2]这个元素，是一个未经初始化的指针