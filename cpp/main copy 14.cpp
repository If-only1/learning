#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void print_vector(const vector<T>& a) {
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> a{1, 2, 3};
    a.insert(a.begin(), 2);
    print_vector(a);
    return 0;
}
