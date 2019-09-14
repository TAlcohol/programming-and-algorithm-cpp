#include <iostream>
#include <map>
#include <string>
using namespace std;

class CStudent
{
  public:
    struct CInfo // 类的内部还可以定义类
    {
        int id;
        string name;
    };
    int score;
    CInfo info; // 内部类的实例化出的对象。应该也可以把这个 CInfo 类定义在外面，但这样写或许比较散乱
};

typedef multimap<int, CStudent::CInfo> MAP_STD; // first 是整型的，second 类型是 CStudent::CInfo 这种类型的
int main()
{
    MAP_STD mp;
    CStudent st;
    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "Add")
        {
            cin >> st.info.name >> st.info.id >> st.score;
            mp.insert(MAP_STD::value_type(st.score, st.info));
            // 改成 mp.insert(make_pair(st.score,st.info)) 也是一样的
        }
        else if (cmd == "Query")
        {
            int score;
            cin >> score;
            MAP_STD::iterator p = mp.lower_bound(score);
            if (p != mp.begin())
            {                     // p 如果等于 mp.begin()，说明找到的区间是从 begin 到 begin，区间为空。所以是没找到。
                --p;              // lower_bound 找到的值，往前推一个，就会都比 score 小
                score = p->first; // 比要查询分数低的最高分
                MAP_STD::iterator maxp = p;
                int maxId = p->second.id;
                for (; p != mp.begin() && p->first == score; --p)
                { // 遍历所有成绩与 score 相等的学生
                    if (p->second.id > maxId)
                    {
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                // 如果上面循环是因为 p == mp.begin() 而终止，则 p 指向的元素还要处理
                if (p->first == score)
                {
                    if (p->second.id > maxId)
                    {
                        maxp = p;
                        maxId = p->second.id;
                    }
                }
                cout << maxp->second.name << " " << maxp->second.id << " " << maxp->first << endl;
            }
            else
                // lower_bound 的结果就是 begin，说明每人比查询分数低
                cout << "Nobody" << endl;
        }
    }
    return 0;
}