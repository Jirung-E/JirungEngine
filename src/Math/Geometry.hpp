#ifndef __Geometry_hpp__
#define __Geometry_hpp__

#include "Point.hpp"
#include "Vector.hpp"
#include "Line.hpp"


namespace Math {
    class Geometry {
    protected:
        Point position;
        Line x_axis;
        Line y_axis;
        Line z_axis;

    public:
        Geometry();

    public:
        Point getPosition() const;
        void moveTo(const Point& point);

        Line getXAxis() const;
        Line getYAxis() const;
        Line getZAxis() const;

        void rotateX(float radian);
        void rotateY(float radian);
        void rotateZ(float radian);
        void rotate(const Line& axis, float radian);
    };
}

#endif