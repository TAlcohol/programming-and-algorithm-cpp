#include <iostream>
using namespace std;

class Demo
{
    int id;

  public:
    Demo(int i)
    {
        id = i;
        cout << "id=" << id << "Constructed" << endl;
    }
    ~Demo()
    {
        cout << "id=" << id << "Destructed" << endl;
    }
};

// 定义一个全局变量 d1
Demo d1(1);

void Func()
{
    static Demo d2(2); // 静态变量
    Demo d3(3);
    cout << "Func" << endl;
}

int main()
{
    Demo d4(4);
    d4 = 6;
    cout << "main" << endl;
    {
        Demo d5(5);
    }
    Func();
    cout << "main ends" << endl;
    return 0;
}

/*
程序输出：
id=1Constructed
id=4Constructed
id=6Constructed 临时对象的生成
id=6Destructed  临时对象的释放
main
id=5Constructed  5在一个括号里/作用域里，离开作用域之后就要被析构掉
id=5Destructed   5在一个括号里/作用域里，离开作用域之后就要被析构掉
id=2Constructed
id=3Constructed
Func
id=3Destructed  d2是静态的，暂时不会消亡，只消亡d3
main ends
id=6Destructed  main函数结束了，剩下三个没有消亡的。C++语法规定，先被构造的函数最后消亡
id=2Destructed
id=1Destructed
*/