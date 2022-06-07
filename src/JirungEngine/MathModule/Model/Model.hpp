#ifndef __Model_hpp__
#define __Model_hpp__

#include "../Polygon/Polygon.hpp"

#include <vector>                                   // list?


namespace JirungEngine {
    class Model {
    private:
        Point position;                             // 포지션이 바뀔경우 축들의 위치도 바뀌어야 하므로 프라이빗으로 설정. 나중에 바뀔수도..

        Point pivot;                                // 필요 없을수도?
        Line x_axis;
        Line y_axis;
        Line z_axis;

        unsigned int num_of_polygons;
        vector<Polygon> polygons;

    public:
        Model();

    public:
        Point getPivot() const;
        void setPivot(const Point& point);          // 중심축을 바꿈

        void moveTo(const Point& point);            // 중심축의 위치를 기준으로 모델을 이동시킴. Polygon들의 위치를 이동시켜야해서 반드시 필요. 때문에 position은 반드시 private

        // void addPolygon(const Polygon& polygon);     // 이게 필요할까?

        void rotateX(float radian);
        void rotateY(float radian);
        void rotateZ(float radian);
        void rotate(const Line& axis, float radian);

        Polygon operator*(float n) const;
        Polygon operator/(float n) const;
        Polygon operator*=(float n);
        Polygon operator/=(float n);
    };
}