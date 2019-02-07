#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

/*
几何形体处理程序
input
第一行是几何形体数目（不超过100），下面有n行，每行以一个字母c开头
若c是“R”，则为矩形，后面跟着两个整数代表宽和高。
若c是“C”，则为圆形，后面跟着一个整数代表半径。
若c是“T”，则为三角形，后面跟着三个整数代表三条边的长度。

output
按面积从小到大依次输出每个几何形体的种类和面积。每行一个几何形体，输出格式为：
形体名称：面积

*/

class CShape
/*
用一个基类概括共同特点，他们的变量没有共同特点，但是方法有共同特点，都能求面积、打印结果。
但方法具体的都不一样，这里用纯虚函数来写。
如果这个类里什么都没有，那为什么要用派生呢？因为之后要用一个基类指针来操作不同的类方法。
*/
{
  public:
    virtual double Area() = 0; // 纯虚函数。意思是连函数体都没有的虚函数。
    virtual void PrintInfo() = 0;
};

class CRectangle : public CShape
{
  public:
    int w, h;
    virtual double Area();
    virtual void PrintInfo();
};

class CCircle : public CShape
{
  public:
    int r;
    virtual double Area();
    virtual void PrintInfo();
};

class CTriangle : public CShape
{
  public:
    int a, b, c;
    virtual double Area();
    virtual void PrintInfo();
};

double CRectangle::Area()
{
    return w * h;
}

void CRectangle::PrintInfo()
{
    cout << "Rectangle:" << Area() << endl;
}

double CCircle::Area()
{
    return 3.14 * r * r;
}

void CCircle::PrintInfo()
{
    cout << "Circle:" << Area() << endl;
}

double CTriangle::Area()
{
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void CTriangle::PrintInfo()
{
    cout << "Triangle:" << Area() << endl;
}

CShape *pShapes[100]; // 用一个基类的指针数组来存放，而基类指针可以指向派生类的对象。否则要开三个数组？反正很麻烦。
int MyCompare(const void *s1, const void *s2);

int main()
{
    int i;
    int n;
    CRectangle *pr;
    CCircle *pc;
    CTriangle *pt;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case 'R':
            pr = new CRectangle();
            cin >> pr->w >> pr->h;
            pShapes[i] = pr;
            break;
        case 'C':
            pc = new CCircle();
            cin >> pc->r;
            pShapes[i] = pc;
            break;
        case 'T':
            pt = new CTriangle();
            cin >> pt->a >> pt->b >> pt->c;
            pShapes[i] = pt;
            break;
        }
    }
    qsort(pShapes, n, sizeof(CShape *), MyCompare);
    for (i = 0; i < n; i++)
    {
        pShapes[i]->PrintInfo();
    }
    return 0;
}

int MyCompare(const void *s1, const void *s2)
{
    double a1, a2;
    CShape **p1; // s1,s2 是 void *，不可写“* s1”来取得s1指向的内容，因为编译器无法从void知道所占存储空间大小
    CShape **p2;
    p1 = (CShape **)s1; // 给s1,s2做强制类型转换。s1,s2 指向pShapes数组中的元素，数组元素的类型是CShape *
    p2 = (CShape **)s2; // 故p1,p2都是指向指针的指针，类型为CShape **
    a1 = (*p1)->Area(); // *p1 的类型是CShape *，是基类指针，故此句为多态
    a2 = (*p2)->Area();
    if (a1 < a2)
        return -1;
    else if (a2 < a1)
        return 1;
    else
        return 0;
}

/*
用基类指针数组存放指向各种派生类对象的指针，然后遍历该数组，
就能对派生类对象做各种操作，是很常用的做法。
*/