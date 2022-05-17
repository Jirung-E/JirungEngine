#ifndef __Vector2D_hpp__
#define __Vector2D_hpp__

namespace JirungEngine {
    class Vector2D {
        public: float x;
        public: float y;

    public:
        Vector2D();
        Vector2D(const Vector2D& vector2d);
        Vector2D(float x, float y);

        Vector2D operator=(const Vector2D& vector2d);
        Vector2D operator+(const Vector2D& vector2d) const;
        Vector2D operator-(const Vector2D& vector2d) const;
        float operator*(const Vector2D& vector2d) const;            // scalar product
        Vector2D operator*(float n) const;
        Vector2D operator/(float n) const;
        Vector2D operator+=(const Vector2D& vector2d);
        Vector2D operator-=(const Vector2D& vector2d);
        Vector2D operator*=(float n);
        Vector2D operator/=(float n);
    };
}

#endif