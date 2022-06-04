#include <iostream>

template <typename T>
void print() {
    std::cout << T(1.0);
}

int main() {
    print<int>();
    return 0;
}
