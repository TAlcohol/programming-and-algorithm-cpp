#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string str = "231";
    char szStr[] = "324";
    while (next_permutation(str.begin(), str.end()))
    // 只要 next_permutation 的返回值是 true，就会继续输出
    {
        cout << str << endl;
    }
    cout << "****" << endl;
    while (next_permutation(szStr, szStr + 3))
    {
        cout << szStr << endl;
    }
    /*
输出
312
321
****
342
423
432
*/

    sort(str.begin(), str.end());
    // string 也是可以 sort 的

    cout << "****" << endl;
    while (next_permutation(str.begin(), str.end()))
    {
        cout << str << endl;
    }
    /*
输出:
132
213
231
312
321

因为第一个循环执行完了之后，str里面的东西已经变成了 321
把它sort一下，它又重新变成了 123
所以 next_permutation 第一个输出的是 132

*/
    return 0;
}