#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;
int main()
{
    fs::path p1{"./data/test.txt"};
    fs::path pp{p1.parent_path()};
    if (!fs::exists(pp))
    {
        fs::create_directory(pp);
    }
    array a{1000, 2, 3};
    fstream out{p1, ios::out};
    out << "[";
    for (auto i : a)
    {
        cout << i << ' ';
    }

    return 0;
}
