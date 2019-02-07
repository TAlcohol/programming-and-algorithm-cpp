#include <iostream>
#include <fstream>
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
    ifstream inFile("aa.txt", ios::in | ios::binary);
    if (!inFile)
    {
        cout << "error" << endl;
        return 0;
    }
    while (inFile.read((char *)&s, sizeof(s)))
    {
        int nReadedBytes = inFile.gcount(); // 看刚才读了多少字节
        cout << s.szName << " " << s.nScore << " " << nReadedBytes << endl;
    }
    inFile.close();
    return 0;
}
