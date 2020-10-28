#pragma once
#include <cmath> // abs, sqrt
#include <cassert> // assert
#include <algorithm> // max, min


typedef float real;
typedef double real64;
typedef signed char	int8;
typedef signed short int16;
typedef signed int int32;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
#ifdef WIN32 // these types are not standard, only exist in windows
typedef __int64 int64;
typedef unsigned __int64 uint64;
#endif
typedef float f32;
typedef double f64;

const real PI = 3.141592741f;
const real EPSILON = 0.0001f;
/// <summary>
/// Helper class for complex operations & calculations.
/// </summary>
struct Vec2
{
    union
    {
        real m[1][1];
        real v[2];

        struct
        {
            real x;
            real y;
        };
    };

    Vec2() {
        x = 0;
        y = 0;

    }
    Vec2(real x_, real y_)
        : x(x_)
        , y(y_)
    {
    }

    void Set(real x_, real y_)
    {
        x = x_;
        y = y_;
    }

    Vec2 operator-(void) const
    {
        return Vec2(-x, -y);
    }

    Vec2 operator*(real s) const
    {
        return Vec2(x * s, y * s);
    }

    Vec2 operator/(real s) const
    {
        return Vec2(x / s, y / s);
    }

    void operator*=(real s)
    {
        x *= s;
        y *= s;
    }

    Vec2 operator+(const Vec2& rhs) const
    {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    Vec2 operator+(real s) const
    {
        return Vec2(x + s, y + s);
    }

    void operator+=(const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
    }

    Vec2 operator-(const Vec2& rhs) const
    {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    void operator-=(const Vec2& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
    }

    real LenSqr(void) const
    {
        return x * x + y * y;
    }

    real Len(void) const
    {
        return std::sqrt(x * x + y * y);
    }

    void Rotate(real radians)
    {
        real c = std::cos(radians);
        real s = std::sin(radians);

        real xp = x * c - y * s;
        real yp = x * s + y * c;

        x = xp;
        y = yp;
    }

    void Normalize(void)
    {
        real len = Len();

        if (len > EPSILON)
        {
            real invLen = 1.0f / len;
            x *= invLen;
            y *= invLen;
        }
    }
};

inline Vec2 operator*(float s, const Vec2& v)
{
    return Vec2(s * v.x, s * v.y);
}

inline Vec2 Min(const Vec2& a, const Vec2& b)
{
    return Vec2(std::min(a.x, b.x), std::min(a.y, b.y));
}

inline Vec2 Max(const Vec2& a, const Vec2& b)
{
    return Vec2(std::max(a.x, b.x), std::max(a.y, b.y));
}

inline real Dot(const Vec2& a, const Vec2& b)
{
    return a.x * b.x + a.y * b.y;
}

inline real DistSqr(const Vec2& a, const Vec2& b)
{
    Vec2 c = a - b;
    return Dot(c, c);
}

inline Vec2 Cross(const Vec2& v, real a)
{
    return Vec2(a * v.y, -a * v.x);
}

inline Vec2 Cross(real a, const Vec2& v)
{
    return Vec2(-a * v.y, a * v.x);
}

inline real Cross(const Vec2& a, const Vec2& b)
{
    return a.x * b.y - a.y * b.x;
}

// Comparison with tolerance of EPSILON
inline bool Equal(real a, real b)
{
    // <= instead of < for NaN comparison safety
    return std::abs(a - b) <= EPSILON;
}

inline real Sqr(real a)
{
    return a * a;
}

inline real Clamp(real min, real max, real a)
{
    if (a < min) return min;
    if (a > max) return max;
    return a;
}

inline int32 Round(real a)
{
    return (int32)(a + 0.5f);
}

inline real Random(real l, real h)
{
    real a = (real)rand();
    a /= RAND_MAX;
    a = (h - l) * a + l;
    return a;
}

inline bool BiasGreaterThan(real a, real b)
{
    const real k_biasRelative = 0.95f;
    const real k_biasAbsolute = 0.01f;
    return a >= b * k_biasRelative + a * k_biasAbsolute;
}

const f32 gravityScale = 5.0f;
const Vec2 gravity(0, 10.0f * gravityScale);
const float dt = 1.0f / 60.0f;

