#ifndef __BoxCollider_hpp__
#define __BoxCollider_hpp__

#include "Collider.hpp"

#include "../../MathModule/Point/Point.hpp"


namespace JirungEngine {
    class BoxCollider {
        private: Point top_left;
        private: Point top_right;
        private: Point bottom_right;
        private: Point bottom_left;
        private: Collider side[4];

    public:
        BoxCollider(const Point& top_left, const Point& bottom_right);
        BoxCollider(const BoxCollider& box_collider);

    public:
        Collider getTopSide() const;
        Collider getRightSide() const;
        Collider getBottomSide() const;
        Collider getLeftSide() const;

        Point getTopLeftPoint() const;
        Point getTopRightPoint() const;
        Point getBottomRightPoint() const;
        Point getBottomLeftPoint() const;

        void setTopLeftPoint(const Point& point);
        void setTopRightPoint(const Point& point);
        void setBottomRightPoint(const Point& point);
        void setBottomLeftPoint(const Point& point);
    };
}

#endif