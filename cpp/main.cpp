#include <iostream>

#include "vec2d.h"

using namespace std;

int main() {
    Vec2d v1(1, 2);
    cout << v1 << endl;
    cout << 1.0 + double(v1);
    return 0;
}