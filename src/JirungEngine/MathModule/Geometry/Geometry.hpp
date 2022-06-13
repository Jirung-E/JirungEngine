#ifndef __Geometry_hpp__
#define __Geometry_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"
#include "../Line/Line.hpp"


namespace JirungEngine {
    class Geometry {
    public:
        Point position;
        Point pivot;
        Line x_axis;
        Line y_axis;
        Line z_axis;
        float rotation_x;
        float rotation_y;
        float rotation_z;

    public:
        Geometry();

    public:
        void moveTo(const Point& point);
        void rotateX(float radian);
        void rotateY(float radian);
        void rotateZ(float radian);
    };
}

#endif