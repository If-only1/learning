#include <iostream>
using namespace std;

int getArrLen1(int *&a)
{ // error

    return sizeof(a) / sizeof(a[0]);
}
int getArrLen2(int *a)
{

    return sizeof(a) / sizeof(a[0]);
}
template <typename T>
int getArrayLength1(T a)
{
    return sizeof(a) / sizeof(a[0]);
}
/**
正确的获取数组长度的函数（虽然是模板）
*/
template <typename T>
int getArrayLength2(T &a)
{
    return sizeof(a) / sizeof(a[0]);
}

int main()
{
    int *p = new int[200];
    int size = *(p - 4);
    cout << size << endl;
    size = *(p - 3);
    cout << size << endl;
    size = *(p - 2);
    cout << size << endl;
    size = *(p - 1);
    cout << size << endl;

    int a[100];
    cout << "a address:" << a << endl;
    cout << "&a address:" << &a << endl;
    cout << getArrLen2(a) << endl;
    cout << getArrayLength1(a) << endl; // 1
    cout << getArrayLength2(a) << endl; // 100
    return 0;
}
