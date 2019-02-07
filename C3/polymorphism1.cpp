#include <iostream>
using namespace std;

// 派生类的指针可以赋值给基类指针
// 通过基类指针调用基类和派生类中的同名虚函数时，
// （1）若该指针指向一个基类的对象，那么被调用的是基类的虚函数；
// （2）若该指针指向一个派生类的对象，那么被调用的是派生类的虚函数
// 这种机制叫做“多态”

class A
{
  public:
    virtual void Print()
    {
        cout << "A::Print" << endl;
    }
};

class B : public A
{
  public:
    virtual void Print()
    {
        cout << "B::Print" << endl;
    }
};

class D : public A
{
  public:
    virtual void Print()
    {
        cout << "D::Print" << endl;
    }
};

class E : public B
{
  public:
    virtual void Print()
    {
        cout << "E::Print" << endl;
    }
};

int main()
{
    A a;
    B b;
    E e;
    D d;
    A *pa = &a;
    B *pb = &b;
    D *pd = &d;
    E *pe = &e;

    // 调用哪个虚函数，取决于p指向哪种类型的对象
    pa->Print();
    pa = pb;
    pa->Print();
    pa = pd;
    pa->Print();
    pa = pe;
    pa->Print();
    return 0;
}