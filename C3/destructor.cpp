#include <iostream>
using namespace std;

class String
{
  private:
    char *p;

  public:
    String()
    {
        p = new char[10];
        strcpy(p, "hello");
        cout << *p << endl;
        cout << "Constructor used" << endl;
    }
    ~String();
};

String::~String()
{
    delete[] p;
    cout << "Destructor used" << endl;
    cout << *p << endl;
}

int main()
{
    String s;
    cout << "end" << endl;
    return 0;
}