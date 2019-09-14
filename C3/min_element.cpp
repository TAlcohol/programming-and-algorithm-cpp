#include <iostream>
#include <algorithm>
using namespace std;

class A
{
  public:
    int n;
    A(int i) : n(i){};
};

// 奇怪的小于号重载
// 只有第一个元素是3，第二个是7，3<7 的时候才是 true
bool operator<(const A &a1, const A &a2)
{
    cout << "<called" << endl;
    if (a1.n == 3 && a2.n == 7)
        return true;
    return false;
}

// min_element 和 max_element 都调用小于号

int main()
{
    A aa[] = {3, 5, 7, 2, 1};
    cout << min_element(aa, aa + 5)->n << endl;
    cout << max_element(aa, aa + 5)->n << endl;
    return 0;
}

/*
输出：

<called
<called
<called
<called
3
<called
<called
<called
<called
7

min_element: 没有元素比它小
max_element: 没有元素比他大

min_element 原理：先假设3最小，比较：5<3，根据重载的小于号规则，返回false，
比较 7<3，2<3，1<3，都是false，其他四个都遍历
一遍后，都不小于3，所以3最小。

max_element 原理：先假设3最大，比较：3<5，根据重载的小于号规则，返回false，
比较 3<7，返回true，所以最大更新为 7，
比较 7<2，7<1，都是false，其他四个都遍历
一遍后，所以7最大。

*/