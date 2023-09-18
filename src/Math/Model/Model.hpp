#ifndef __Model_hpp__
#define __Model_hpp__

#include "../Polygon/Polygon.hpp"
#include "../Geometry/Geometry.hpp"

#include <vector>                                   // list?


namespace Math {
    class Model : public Geometry {
    public:
        std::vector<Polygon> polygons;

    public:
        Model();

    public:
        void moveTo(const Point& point);

        void rotateX(float radian);
        void rotateY(float radian);
        void rotateZ(float radian);
        void rotate(const Line& axis, float radian);

        Model operator*(float n) const;
        Model operator/(float n) const;
        Model operator*=(float n);
        Model operator/=(float n);
    };
}

#endif