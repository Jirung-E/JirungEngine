#ifndef __Vector2D_hpp__
#define __Vector2D_hpp__

namespace JirungEngine {
    class Vector2D {
        private: int x;
        private: int y;

    public:
        Vector2D();
        Vector2D(const Vector2D& vector2d);
        Vector2D(int x, int y);

        Vector2D operator=(const Vector2D& vector2d);
        Vector2D operator+(const Vector2D& vector2d);
        Vector2D operator-(const Vector2D& vector2d);
        int operator*(const Vector2D& vector2d);            // scalar product
        Vector2D operator*(int n);
        Vector2D operator/(int n);
    };
}

#endif