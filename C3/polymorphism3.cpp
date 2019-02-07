#include <iostream>
using namespace std;

class myclass
{
  public:
    virtual void hello()
    {
        cout << "hello from myclass" << endl;
    };
    virtual void bye()
    {
        cout << "bye from myclass" << endl;
    };
};

// 派生类中和基类中虚函数同名同参数表的函数，不加virtual也自动成为虚函数

class son : public myclass
{
  public:
    void hello()
    {
        cout << "hello from son" << endl;
    };
    son()
    {
        hello();
    };
    ~son()
    {
        bye();
    };
};

class grandson : public son
{
  public:
    void hello()
    {
        cout << "hello from grandson" << endl;
    };
    void bye()
    {
        cout << "bye from grandson" << endl;
    };
    grandson()
    {
        cout << "constructing grandson" << endl;
    };
    ~grandson()
    {
        cout << "destructing grandson" << endl;
    };
};

int main()
{
    grandson gson; // 先构造myclass，但其构造函数没有cout，就不输出；再构造son，
    // 构造函数中没有多态，所以son中的构造函数的son的hello()，直接用son自己的hello()，输出hello from son
    // 接下来构造grandson，用的也是grandson自己的hello()，所以输出constructing grandson
    son *pson;
    pson = &gson;
    pson->hello(); // 多态，pson是son这个类的指针，与grandson相比，son是它的基类。
    // hello是两个里面的同名函数，用grandson的。输出hello from grandson
    return 0;
}
// 最后，析构grandson，输出destructing grandson
// 再析构son，用的是son自己的bye()，可是son自己没有bye()，就用的是上一层class类的bye()，
// 输出 bye from myclass

// output:
// hello from son
// constructing grandson
// hello from grandson
// destructing grandson
// bye from myclass