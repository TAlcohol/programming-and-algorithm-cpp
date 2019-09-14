#include <iostream>
using namespace std;

int main()
{
    freopen("freopen_test.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << (a > b ? a : b) << endl;
    }
}