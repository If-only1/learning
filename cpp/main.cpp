#include <iostream>

#include "vec2d.h"

using namespace std;

int main() {
    Vec2d v1(1, 2);
    Vec2d v2(3, 4);
    float v = 2;
    //测试成员函数
    cout << "测试成员函数" << endl;
    cout << "v1: " << v1.to_string() << endl;
    cout << "v2: " << v2.to_string() << endl;

    cout << "v1 + v2: " << v1.add(v2).to_string() << endl;
    cout << "v1 + v: " << v1.add(v).to_string() << endl;

    cout << "v1 - v2: " << v1.sub(v2).to_string() << endl;
    cout << "v1 - v: " << v1.sub(v).to_string() << endl;

    cout << "v1 * v: " << v1.multi(v).to_string() << endl;
    cout << "v1 / v: " << v1.div(v).to_string() << endl;

    cout << "v1 * v2: " << v1.dot(v2) << endl;
    cout << "v1 neg: " << v1.neg().to_string() << endl;
    cout << "v1 inc: " << v1.inc().to_string() << endl;
    cout << "v1 dec: " << v1.dec().to_string() << endl;
    cout << "v1 length: " << v1.length() << endl;
    cout << "v1 degree: " << v1.degree() << endl;
    cout << "v1 compare v2: " << v1.compare(v2) << endl;

    cout << "v1@0: " << v1[0] << endl;
    cout << "v1@1: " << v1[1] << endl;
    v1[0] = 10;
    v1[1] = 20;
    cout << "v1@0: " << v1[0] << endl;
    cout << "v1@1: " << v1[1] << endl;
    v1.at(0) = 100;
    v1.at(1) = 200;
    cout << "v1@0: " << v1[0] << endl;
    cout << "v1@1: " << v1[1] << endl;

    //测试运算符重载
    cout << "测试运算符重载" << endl;
    cout << "v1 + v2: " << (v1 + v2).to_string() << endl;
    cout << "v1 + v: " << (v1 + v).to_string() << endl;
    cout << "v + v1: " << (v + v1).to_string() << endl;

    cout << "v1 - v2: " << (v1 - v2).to_string() << endl;
    cout << "v1 - v: " << (v1 - v).to_string() << endl;
    cout << "v - v1: " << (v - v1).to_string() << endl;

    cout << "v1 * v: " << (v1 * v).to_string() << endl;
    cout << "v * v1: " << (v * v1).to_string() << endl;

    cout << "v1 / v: " << (v1 / v).to_string() << endl;

    cout << "v1 * v2: " << (v1 * v2) << endl;
    cout << "v1 " << v1.to_string() << endl;
    v1 += 1;
    cout << "v1 += 1;" << v1.to_string() << endl;

    return 0;
}