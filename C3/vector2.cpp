#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int> > v(3); // 二维vector数组
    for (int i = 0; i < v.size(); ++i)
        for (int j = 0; j < 4; ++j)
            v[i].push_back(j); // 放到每一个一维数组最后
    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
