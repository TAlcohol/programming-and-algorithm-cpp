#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int Try(char *q)
{
    printf("addr: %p \n", q);
    //q = "hi";
    *q = 'g';
    printf("addr: %p \n", q);
    cout << q << endl;
    return 1;
}

int main()
{
    char str = 'c';
    char *p = &str;
    cout << p << endl;
    Try(p);
    cout << p << endl;
    return 0;
}