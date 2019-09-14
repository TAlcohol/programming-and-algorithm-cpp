#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<double> priorities;
    priorities.push(3.6);
    priorities.push(9.8);
    priorities.push(9.8);
    priorities.push(5.4);
    while (!priorities.empty())
    {
        cout << priorities.top() << " ";
        priorities.pop();
    }
    // 不可以这样：
    // priorities.top() = 2;
    // 因为 priority_queue 不可以修改头部元素，返回值是一个 const_reference
    return 0;
}