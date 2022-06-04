#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
void test(const int a[]) {
    cout << typeid(a).name() << endl;
    int v = 1000;
    a = &v;
    cout << typeid(a).name() << endl;
}

int main() {
    int a[]{1, 23};
    const int* p = a;
    int v = 1000;
    p = &v;
    cout << typeid(a).name() << endl;
    cout << typeid(p).name() << endl;
    test(a);
    cout << a[0];
    cout << a[1];
}
