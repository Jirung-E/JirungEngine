#ifndef __Geometry_hpp__
#define __Geometry_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"
#include "../Line/Line.hpp"


namespace JirungEngine {
    class Geometry {
    private:
        Point position;
        Point pivot;
        Line x_axis;
        Line y_axis;
        Line z_axis;

    public:
        Geometry();

    public:
        Point getPosition() const;
        void moveTo(const Point& point);

        Point getPivot() const;
        void setPivot(const Point& point);

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