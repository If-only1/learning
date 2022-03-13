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
    int a[]{1, 2, 3};
    char c[]{"sdfjkhadf"};
    fstream out{p1, ios::out | ios::trunc};
    out.put(c[0]);
    out.write(reinterpret_cast<char *>(a), sizeof(a));
    out.close();
    fstream in(p1, ios::in);
    char buf[100];
    int i = 0;
    while (!in.read(buf, 1).eof())
    {
        cout << "read " << i << ":  " << buf << endl;
        i++;
    }

    return 0;
}
