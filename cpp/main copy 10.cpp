#include <iostream>

#include "range_exception.h"
#include "vec2d.h"

using namespace std;

int main() {
    try {
        Vec2d a = Vec2d(1, 2);
        cout << a[3];

    } catch (exception& e) {
        std::cerr << e.what() << '\n';
    }
}