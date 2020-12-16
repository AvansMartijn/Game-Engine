#pragma once
#include <valarray>

const float PI = 3.141592741f;
const float EPSILON = 0.0001f;
/// <summary>
/// Helper class for complex operations & calculations.
/// </summary>
struct Vec2
{
    union {
        float m[1][1];
        float v[2];

        struct {
            float x;
            float y;
        };
    };

    Vec2() {
        x = 0;
        y = 0;
    }

    Vec2(float x_, float y_): x(x_) , y(y_) {
    }

    void Set(float x_, float y_) {
        x = x_;
        y = y_;
    }

    Vec2 operator-(void) const {
        return Vec2(-x, -y);
    }

    Vec2 operator*(float s) const {
        return Vec2(x * s, y * s);
    }

    Vec2 operator/(float s) const {
        return Vec2(x / s, y / s);
    }

    void operator*=(float s) {
        x *= s;
        y *= s;
    }

    Vec2 operator+(const Vec2& rhs) const {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 operator+(float s) const {
        return Vec2(x + s, y + s);
    }

    void operator+=(const Vec2& rhs) {
        x += rhs.x;
        y += rhs.y;
    }

    Vec2 operator-(const Vec2& rhs) const {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    void operator-=(const Vec2& rhs) {
        x -= rhs.x;
        y -= rhs.y;
    }

    float LenSqr(void) const {
        return x * x + y * y;
    }

    float Len(void) const {
        return std::sqrt(x * x + y * y);
    }

    void Rotate(float radians) {
        float c = std::cos(radians);
        float s = std::sin(radians);

        float xp = x * c - y * s;
        float yp = x * s + y * c;

        x = xp;
        y = yp;
    }

    void Normalize(void) {
        float len = Len();

        if (len > EPSILON) {
            float invLen = 1.0f / len;
            x *= invLen;
            y *= invLen;
        }
    }
};
