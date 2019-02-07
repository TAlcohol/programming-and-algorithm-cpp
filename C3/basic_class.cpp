#include <iostream>
using namespace std;

class CRectangle
{
  public:
    int w, h;
    void Init(int w_, int h_)
    {
        w = w_;
        h = h_;
    }
    int Area()
    {
        return w * h;
    }
    int Perimeter()
    {
        return 2 * (w + h);
    }
};

// 也可以写一个函数
void PrintRectangle(CRectangle &r)
{
    cout << r.Area() << "," << r.Perimeter();
}
// 在main函数里可以这样做：
// CRectangle r3;
// r3.Init(3, 4);
// PrintRectangle(r3);

int main()
{
    CRectangle r1, r2; // r是一个对象

    // 用对象进行访问
    // r1.w = 5;
    // r2.Init(3, 4);

    // 用对象的指针进行访问
    CRectangle *p1 = &r1;
    CRectangle *p2 = &r2;
    p1->w = 5;
    p2->Init(3, 4);

    // 用对象的引用进行访问
    // CRectangle r2;
    // CRectangle & rr = r2;
    // rr.w = 5;
    // rr.Init(3,4); // rr的值变了，r2的值也变

    cout << r2.Area() << endl
         << r2.Perimeter() << endl
         << r1.w << endl;

    CRectangle r3;
    r3.Init(3, 4);
    PrintRectangle(r3);

    return 0;
}
