#ifndef __Geometry_hpp__
#define __Geometry_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"
#include "../Line/Line.hpp"


namespace Math {
    class Geometry {
    private:
        Point position;
        Line x_axis;
        Line y_axis;
        Line z_axis;        // pivot 없애고 쿼터니언 적용하면 이거 변수로 저장할 필요가 없어짐. 따라서 position을 퍼블릭으로 설정 할수 있고, 축별 회전값도 퍼블릭 변수로 설정 가능함.

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