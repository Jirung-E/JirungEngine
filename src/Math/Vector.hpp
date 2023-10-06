#ifndef __Vector_hpp__
#define __Vector_hpp__

#include "Point.hpp"


namespace Math {
    class Vector {
    public:
        float x;
        float y;
        float z;

    public:
        Vector(float x, float y, float z = 0.0);
        Vector(const Vector& vector);
        Vector(const Point& point);
        Vector();

        operator Point() const;

    public:
        Vector operator+(const Vector& vector) const;
        Vector operator-(const Vector& vector) const;
        float operator*(const Vector& vector) const;            // scalar product

        Vector operator*(float n) const;
        Vector operator/(float n) const;

        Vector operator-();

        Vector& operator+=(const Vector& vector);
        Vector& operator-=(const Vector& vector);
        Vector& operator*=(float n);
        Vector& operator/=(float n);

        bool operator==(const Vector& vector) const;
        bool operator!=(const Vector& vector) const;

        Vector unit() const;
        Vector cross(const Vector& vector) const;
        float magnitude() const;

        static Vector i();
        static Vector j();
        static Vector k();
    };

    float angleBetween(const Vector& vector1, const Vector& vector2);
    bool isParallel(const Vector& vector1, const Vector& vector2);
    bool isOrthogonal(const Vector& vector1, const Vector& vector2);

    Vector operator*(float n, const Vector& vector);

    Vector operator-(const Point& point1, const Point& point2);
    Point operator+(const Point& point, const Vector& vector);
    Point operator-(const Point& point, const Vector& vector);
    Point& operator+=(Point& point, const Vector& vector);
    Point& operator-=(Point& point, const Vector& vector);
}

#endif