#include <iostream>
using namespace std;

int main()
{
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            for (int z = 0; z <= 100; z++)
            {
                if ((x + y + z == 100) && (3 * x + 2 * y + 0.5 * z == 100))
                {
                    cout << x << ' ' << y << ' ' << z << endl;
                }
            }
        }
    }
}