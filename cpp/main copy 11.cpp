#include <iostream>

template <typename T>
T max(T x, T y) {
    if (x >= y)
        return x;
    else
        return y;
}

template <int>
int max(int, int);
int main() {
    int a, b;
    std::cout << max(a, b) << std::endl;
    return 0;
}
