#include <iostream>
#include <cstring>
using namespace std;

class String
{
  private:
    char *str;

  public:
    String() : str(NULL) {}
    const char *c_str() { return str; }
    String &operator=(const char *s);
    ~String();
};
String &String::operator=(const char *s)
{
    if (str)
        delete[] str;
    if (s)
    {                                  // s 不为NULL才会被复制
        str = new char[strlen(s) + 1]; // 考虑最后有一个'\0'
        strcpy(str, s);
    }
    else
        str = NULL;
    return *this;
}
String::~String()
{
    if (str)
        delete[] str;
};
int main()
{

    String s;
    s = "Good luck,";
    cout << s.c_str() << endl;
    // String s2 = "hello";  这条语句不注释就会出错，因为这是
    // 初始化语句，不是赋值号“=”，String类没有编写参数类型为 char * 的构造函数
    s = "Shenzhou 8!";
    cout << s.c_str() << endl;

    char *c = "hello";
    String a, b;
    (a = b) = c;
    cout << a.c_str() << b.c_str() << c << endl;
    return 0;
}