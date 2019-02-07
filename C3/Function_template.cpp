#include <iostream>
using namespace std;

template <class T1, class T2>
T1 myFunction(T1 arg1, T2 arg2)
{
    cout << arg1 << " " << arg2 << "\n";
    return arg1;
}

int main()
{
    myFunction(5, 7);     // replace T1 and T2 with int, return int
    myFunction(5.8, 8.4); // replace T1 and T2 with double, return double
    myFunction(5, 8.4);   // replace T1 with int, T2 with double, return int
    return 0;
}
