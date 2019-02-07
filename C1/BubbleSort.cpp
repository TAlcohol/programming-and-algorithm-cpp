#include <iostream>
using namespace std;

int main()
{
    int n, a[1000]; // n numbers in total, use a save these numbers
    cin >> n;
    // input n numbers
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}

// input
// 8 3 5 6 1
// (1)
// 3 8 5 6 1
// 3 5 8 6 1
// 3 5 6 8 1
// 3 5 6 1 8
// (2)
// 3 5 6 1
// 3 5 6 1
// 3 5 1 6
// (3)
// 3 5 1
// 3 1 5
// (4)
// 1 3