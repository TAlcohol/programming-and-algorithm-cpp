#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[3][4] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23};
    int(*p)[4], i, j;
    p = a;
    cin >> i >> j;
    cout << setw(3) << *(*(p + i) + j); // 相当于 p[i][j]
    return 0;
}
