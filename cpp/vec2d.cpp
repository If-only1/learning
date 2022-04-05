#include "vec2d.h"

#include <math.h>

#include <exception>
#include <sstream>

Vec2d::Vec2d(float x, float y) {
    this->x = x;
    this->y = y;
}

Vec2d Vec2d::add(const Vec2d &v) const { return Vec2d(this->x + v.x, this->y + v.y); }
Vec2d Vec2d::add(float v) const { return Vec2d(this->x + v, this->y + v); }
Vec2d Vec2d::operator+(const Vec2d &v) const { return this->add(v); }
Vec2d Vec2d::operator+(float v) const { return this->add(v); }
Vec2d operator+(float v, const Vec2d &v2) { return v2.add(v); }
Vec2d Vec2d::operator+=(float v) {
    x += v;
    y += v;
    return *this;
}

Vec2d Vec2d::sub(const Vec2d &v) const { return Vec2d(this->x - v.x, this->y - v.y); }
Vec2d Vec2d::sub(float v) const { return Vec2d(this->x - v, this->y - v); }
Vec2d Vec2d::operator-(const Vec2d &v) const { return this->sub(v); }
Vec2d Vec2d::operator-(float v) const { return this->sub(v); }
Vec2d operator-(float v, const Vec2d &v2) { return v2.sub(v); }

Vec2d Vec2d::multi(float v) const { return Vec2d(this->x * v, this->y * v); }
Vec2d Vec2d::operator*(float v) const { return this->multi(v); }
Vec2d operator*(float v, const Vec2d &v2) { return v2.multi(v); }

Vec2d Vec2d::div(float v) const { return Vec2d(this->x / v, this->y / v); }
Vec2d Vec2d::operator/(float v) const { return this->div(v); }

float Vec2d::dot(const Vec2d &v) const { return this->x * v.x + this->y * v.y; }
float Vec2d::operator*(const Vec2d &v) const { return this->dot(v); }

Vec2d Vec2d::neg() const { return Vec2d(-this->x, -this->y); }
Vec2d Vec2d::inc() {
    x++;
    y++;
    return *this;
}
Vec2d Vec2d::dec() {
    x--;
    y--;
    return *this;
}
float Vec2d::length() const { return sqrt(this->x * this->x + this->y * this->y); }
float Vec2d::degree() const { return atan2(this->y, this->x); }
bool Vec2d::compare(const Vec2d &v) const {
    float d1 = this->length();
    float d2 = v.length();
    return d1 >= d2;
}
std::string Vec2d::to_string() const {
    std::stringstream ss;
    ss << "(" << this->x << ", " << this->y << ")";
    return ss.str();
}

float &Vec2d::at(const int i) {
    if (i == 0) {
        return this->x;
    } else if (i == 1) {
        return this->y;
    } else {
        std::out_of_range e("Index out of range");
        throw e;
    }
}
float &Vec2d::operator[](const int &i) { return this->at(i); }
Vec2d Vec2d::operator-() const { return this->neg(); }
