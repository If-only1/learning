#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
using namespace std;

vector<string> string_split(const string &str, char delim)
{
    stringstream ss(str);
    string item;
    vector<string> elems;
    while (getline(ss, item, delim))
    {
        if (!item.empty())
        {
            elems.push_back(item);
        }
    }
    return elems;
}

bool write_array(fstream &out, char name[], int size, int data[])
{
    out << "name:" << name << endl;
    out << "data:";
    out << "[";
    for (int i = 0; i < size; i++)
    {
        out << data[i];
        out << ',';
    }
    out.seekp(-1, ios::cur);
    out << "]\n";
    return true;
}

bool read_array(fstream &in, char name[], int size, int data[])
{
    string buf;

    while (in >> buf)
    {
        if (buf.compare(0, 5, "data:") == 0)
        {
            buf = string_split(buf, '[')[1];
            buf = string_split(buf, ']')[0];
            auto nums = string_split(buf, ',');
            for (auto i = 0; i < size; i++)
            {
                data[i] = atoi(nums[i].c_str());
            }
        }
    }
    return true;
}

template <typename T>
int getArrayLength2(T &a)
{
    return sizeof(a) / sizeof(a[0]);
}

void print_array(int array[])
{
    auto size = sizeof(array) / sizeof(array[0]);
    cout << "size:" << size << endl;
    cout << " sizeof(array):" << sizeof(array) << endl;
    cout << "sizeof(array[0]:" << sizeof(array[0]) << endl;

    for (auto i = 0; i < size; i++)
    {
        cout << array[i] << ',';
    }
    cout << endl;
}

int main()
{
    filesystem::path p1{"./data/test.txt"};
    filesystem::path pp{p1.parent_path()};
    if (!filesystem::exists(pp))
    {
        filesystem::create_directory(pp);
    }
    int a[]{1000, 2, 3};
    fstream out{p1, ios::out};
    char name[]{"test_array"};
    write_array(out, name, sizeof(a) / sizeof(a[0]), a);
    out.close();
    fstream in{p1, ios::in};
    int b[3]{1, 2, 3};
    read_array(in, name, sizeof(a) / sizeof(a[0]), b);
    print_array(a);
    print_array(b);
    return 0;
}
