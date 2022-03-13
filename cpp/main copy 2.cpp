#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <array>
namespace fs = std::filesystem;
using namespace std;
int main()
{

    fs::path p1{"./data/array.dat"};
    fs::path pp{p1.parent_path()};
    if (!fs::exists(pp))
    {
        fs::create_directories(pp);
        cout << "create dir " << pp << endl;
    }

    fstream out{p1, ios::binary | ios::out};
    array<int, 3> a{1, 2, 3};
    float x = 1.233;
    string s{"sdfjkhf"};
    char s1[]{"dsakjhfhajk"};
    out.write(reinterpret_cast<char *>(&a), sizeof(a[0]) * a.size());

    out.close();
    out.open(p1, ios::in);
    int xx;
    while (!out.read(reinterpret_cast<char *>(&xx), sizeof(xx)).eof())
    {
        cout << xx << endl;
    }

    return 0;
}
