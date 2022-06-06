#ifndef __Polygon_hpp__
#define __Polygon_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"


namespace JirungEngine {
    class Polygon {
    public:
        Point p1;
        Point p2;
        Point p3;

    public:
        Polygon();

    public:
        Vector getNormal() const;
        Point getCenterOfGravity() const;

        void moveTo(const Point& point);
        void transformNormalVectorTo(const Vector& vector);
        void rotate(float radian);
        void rotate(const Line& axis, float radian);
    };
}

#endif