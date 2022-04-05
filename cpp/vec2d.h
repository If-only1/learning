#include <string>
class Vec2d {
   public:
    Vec2d(float x, float y);
    Vec2d add(const Vec2d &v) const;
    Vec2d add(float v) const;
    Vec2d operator+(const Vec2d &v) const;
    Vec2d operator+(float v) const;
    Vec2d operator+=(float v);
    Vec2d friend operator+(float v, const Vec2d &v2);

    Vec2d sub(const Vec2d &v) const;
    Vec2d sub(float v) const;
    Vec2d operator-(const Vec2d &v) const;
    Vec2d operator-(float v) const;
    Vec2d operator-=(float v) const;
    Vec2d friend operator-(float v, const Vec2d &v2);

    Vec2d multi(float v) const;
    Vec2d operator*(float v) const;
    Vec2d operator*=(float v) const;
    Vec2d friend operator*(float v, const Vec2d &v2);

    Vec2d div(float v) const;
    Vec2d operator/(float v) const;

    float dot(const Vec2d &v) const;
    float operator*(const Vec2d &v) const;

    Vec2d neg() const;
    Vec2d inc();
    Vec2d dec();
    float length() const;
    float degree() const;
    bool compare(const Vec2d &v) const;

    std::string to_string() const;

    float &at(const int i);
    float &operator[](const int &i);

    Vec2d operator-() const;

   private:
    float x;
    float y;
};
