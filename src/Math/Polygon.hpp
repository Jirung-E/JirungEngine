#ifndef __Polygon_hpp__
#define __Polygon_hpp__

#include "Point.hpp"
#include "Vector.hpp"
#include "Line.hpp"


namespace Math {
    class Polygon {
    public:
        Point p1;
        Point p2;
        Point p3;

    public:
        Polygon();
        Polygon(const Point& p1, const Point& p2, const Point& p3);
        Polygon(const Polygon&) = default;

    public:
        Vector getNormal() const;
        Point getCenterOfGravity() const;

        void moveTo(const Point& point);
        void transformNormalVectorTo(const Vector& vector);
        void rotate(float radian);
        void rotate(const Line& axis, float radian);

        Polygon operator*(float n) const;
        Polygon operator/(float n) const;
        Polygon operator*=(float n);
        Polygon operator/=(float n);
    };
}

#endif