#ifndef __Vector_hpp__
#define __Vector_hpp__

#include "../Point/Point.hpp"


namespace JirungEngine {
    class Vector {
        public: float x;
        public: float y;
        public: float z;

    public:
        Vector();
        Vector(const Vector& vector);
        Vector(float x, float y, float z = 0.0);

        Vector operator=(const Vector& vector);
        Vector operator+(const Vector& vector) const;
        Vector operator-(const Vector& vector) const;
        float scalarProduct(const Vector& vector) const;
        static float scalarProduct(const Vector& vector1, const Vector& vector2) const;
        Vector crossProduct(const Vector& vector) const;
        static Vector crossProduct(const Vector& vector1, const Vector& vector2) const;
        float operator*(const Vector& vector) const;            // scalar product
        Vector operator*(float n) const;
        Vector operator/(float n) const;
        Vector operator+=(const Vector& vector);
        Vector operator-=(const Vector& vector);
        Vector operator*=(float n);
        Vector operator/=(float n);

    public:
    
    };
}

#endif