#ifndef __Vector_hpp__
#define __Vector_hpp__

#include "../Point/Point.hpp"


namespace Math {
    class Vector {
        public: float x;
        public: float y;
        public: float z;

    public:
        Vector();
        Vector(const Vector& vector);
        Vector(const Point& point);
        Vector(float x, float y, float z = 0.0);

        Vector operator=(const Vector& vector);
        Vector operator+(const Vector& vector) const;
        Vector operator-(const Vector& vector) const;
        float scalarProduct(const Vector& vector) const;
        static float scalarProduct(const Vector& vector1, const Vector& vector2);
        Vector crossProduct(const Vector& vector) const;
        static Vector crossProduct(const Vector& vector1, const Vector& vector2);
        float operator*(const Vector& vector) const;            // scalar product
        Vector operator*(float n) const;
        Vector operator/(float n) const;
        bool operator==(const Vector& vector) const;
        bool operator!=(const Vector& vector) const;
        Vector operator+=(const Vector& vector);
        Vector operator-=(const Vector& vector);
        Vector operator*=(float n);
        Vector operator/=(float n);

        float magnitude() const;
        Vector getUnitVector() const;
        static Vector unitVectorOf(const Vector& vector);
        float getAngleWith(const Vector& other) const;
        static float getAngleBetween(const Vector& vector1, const Vector& vector2);
        bool isParallelTo(const Vector& other) const;
        static bool isParallel(const Vector& vector1, const Vector& vector2);
        static bool isOrthogonal(const Vector& vector1, const Vector& vector2);

        static Vector i();
        static Vector j();
        static Vector k();
    };

    Vector operator*(float n, const Vector& vector);
}

#endif