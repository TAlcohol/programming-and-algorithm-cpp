#include <iostream>
using namespace std;

// cin.get能把空格和回车从输入缓冲区读取出来，cin则会忽略这两者

int main()
{
    char c;
    cout << "enter a sentence:" << endl;
    while ((c = cin.get()) != EOF)
        cout << c;
    return 0;
}

// 作用和上面的一样

// int main()
// {
//     char c;
//     cout << "enter a sentence:" << endl;
//     while (cin.get(c))
//         // 读入一个字符赋给字符变量c
//         // 读入的是错误的时候，cin.get这个函数返回一个假（0），否则返回真
//         cout << c;
//     return 0;
// }

// getchar 不跳过任何字符，甚至能把输入结束标志都当作数据读取进来

// int main()
// {
//     char c;
//     cout << "enter a sentence:" << endl;
//     while (c = getchar()) // 不跳过任何字符
//         cout << c;
//     return 0;
// }
