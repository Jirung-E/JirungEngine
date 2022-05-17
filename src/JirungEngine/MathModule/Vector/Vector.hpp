#ifndef __Vector_hpp__
#define __Vector_hpp__

namespace JirungEngine {
    class Vector {
        public: float x;
        public: float y;
        public: float z;

    public:
        Vector();
        Vector(const Vector& vector);
        Vector(float x, float y, float z);

        Vector operator=(const Vector& vector);
        Vector operator+(const Vector& vector);
        Vector operator-(const Vector& vector);
        float operator*(const Vector& vector);            // scalar product
        Vector operator*(float n);
        Vector operator/(float n);
        Vector operator+=(const Vector& vector);
        Vector operator-=(const Vector& vector);
        Vector operator*=(float n);
        Vector operator/=(float n);
    };
}

#endif