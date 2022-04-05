#include <iostream>

#include "vec2d.h"

using namespace std;

int main() {
    Vec2d v1(1, 2);
    cout << "v1: " << v1.to_string() << endl;
    cout << "-v1: " << (-v1).to_string() << endl;
    return 0;
}