#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
template <typename T1, typename T2>
void print_map(const map<T1, T2>& a) {
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << i->first << ':' << i->second << endl;
    }
}

int main() {
    map<string, int> a;
    a.insert(map<string, int>::value_type("li", 1));
    a["li"] = 2;
    a["li2"] = 2;

    cout << a["li"];
    print_map(a);
    return 0;
}
