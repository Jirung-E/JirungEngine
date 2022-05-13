#ifndef __Vector_hpp__
#define __Vector_hpp__

namespace JirungEngine {
    class Vector {
        public: int x;
        public: int y;
        public: int z;

    public:
        Vector();
        Vector(const Vector& vector);
        Vector(int x, int y, int z);

        Vector operator=(const Vector& vector);
        Vector operator+(const Vector& vector);
        Vector operator-(const Vector& vector);
        int operator*(const Vector& vector);            // scalar product
        Vector operator*(int n);
        Vector operator/(int n);
    };
}

#endif