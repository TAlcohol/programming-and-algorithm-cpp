/*一个类的成员函数，作为另一类的友元函数*/
#include <iostream>
using namespace std;
class A;
class B //由于类B中的函数要作为类A的友元类，因此类B需要先定义
{
  public:
    void funB(A &a);
};
//void B::funB(A &a)//不会出错
//{
//	cout<<"shao"<<endl;
//}
class A
{
  public:
    A(int i) { m = i; }
    friend void B::funB(A &a); //将一个类的成员函数作为另一个类的友元函数时，函数名应该用该函数所属的类名字加以限定。
  private:
    int m;
};
void B::funB(A &a)
{
    cout << a.m << endl; //这里引用了类的私有成员m,需要将其放在类A的定义之后（若放在类B和类A的定义之间，会报错）。
                         //类B的成员函数fanB设置为友元，主要是为了访问类A的成员。
}
int main(void)
{
    A obj(10);
    B b;
    b.funB(obj);
    //funB(obj);
}
