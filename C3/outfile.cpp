#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class CStudent
{
  public:
    char szName[20];
    int nScore;
};

int main()
{
    CStudent s;
    ofstream OutFile("aa.dat", ios::out | ios::binary);
    while (cin >> s.szName >> s.nScore)
    {
        if (strcmp(s.szName, "exit") == 0) // 名字为exit 则结束
            break;
        OutFile.write((char *)&s, sizeof(s));
    }
    OutFile.close();
    return 0;
}
