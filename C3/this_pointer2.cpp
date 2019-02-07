#include <iostream>
using namespace std;

// 比较怪异的程序，用到了this指针的知识

class A
{
    int i;

  public:
    void Hello()
    {
        cout << "Hello" << endl;
    }
};

int main()
{
    A *p = NULL; // p是一个空指针，还没有指向任何对象
    p->Hello();  // 但因为Hello这个A中的成员函数，恰好没有用到任何对象的内容，只是cout，所以这个程序没错。
    // 相当于把成员函数变成了：
    // void Hello(A *this) {cout << "Hello" << endl;}
    // 但这里this没有起作用
    // 但如果这个成员函数不输出字符串Hello，却输出A中的i，就会有问题。因为此时p是个空指针，没有指向任何对象。
    // 就会不知道输出哪里的i，就会报错。
}

// 输出
// hello