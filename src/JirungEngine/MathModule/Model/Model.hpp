#ifndef __Model_hpp__
#define __Model_hpp__

#include "../Polygon/Polygon.hpp"
#include "../Geometry/Geometry.hpp"

#include <vector>                                   // list?


namespace JirungEngine {
    class Model : public Geometry {
    public:
        std::vector<Polygon> polygons;

    public:
        Model();

    public:
        void moveTo(const Point& point);            // 중심축의 위치를 기준으로 모델을 이동시킴. Polygon들의 위치를 이동시켜야해서 반드시 필요. 때문에 position은 반드시 private

        void rotateX(float radian);
        void rotateY(float radian);
        void rotateZ(float radian);
        void rotate(const Line& axis, float radian);
        
        // void addPolygon(const Polygon& polygon);     // 이게 필요할까?

        Model operator*(float n) const;
        Model operator/(float n) const;
        Model operator*=(float n);
        Model operator/=(float n);
    };
}

#endif