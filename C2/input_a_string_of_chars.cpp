#include <iostream>
using namespace std;

int main()
{
    char a[10][10];
    int n = 0;
    cin >> n;
    cin.get(); // 如果没有这句，会有问题。具体见 Coursera “C语言基础视频” - “一串字符的输入” 课程视频的第 22 分钟
    // 问题大概是，上一句的 cin >> n 会把缓冲区的指针停留在输入的 n 后面，回车前面。所以后面的循环，会先把回车读入，
    // 作为第一个循环的值。导致后面只能读入 n-1 行，不符合读入 n 行数据的预期
    // 这句话 cin.get(), 把后面的回车符号读走，让指针转到下一行。并且cin.get()会忽略回车字符。
    // https://www.coursera.org/learn/jisuanji-biancheng/lecture/sHqrF/chuan-zi-fu-de-shu-ru
    for (int i = 0; i < n; i++)
        cin.getline(a[i], 10);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}
