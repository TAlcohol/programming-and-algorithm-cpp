#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}

// 运行
// g++ Command_line_argument.cpp
// ./a.out 1 2
// 输出
// ./a.out
// 1
// 2

// 如果不想生成叫a.out的文件，可以这样：
// g++ -o C_p Command_line_argument.cpp
// ./C_p 1 3
// 输出
// ./C_p
// 1
// 3