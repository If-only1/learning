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
    std::cout << max(1, 2) << std::endl;
    std::cout << max("ab", "sdss") << std::endl;
    std::cout << max("sdss", "ab") << std::endl;

    return 0;
}
