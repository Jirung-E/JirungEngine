#ifndef __BoxCollider_hpp__
#define __BoxCollider_hpp__

#include "Collider.hpp"

#include "../../MathModule/Point/Point.hpp"


namespace JirungEngine {
    class BoxCollider : public Collider {
        private: Point top_left;
        private: Point buttom_right;
        private: Collider side[4];

    public:
        BoxCollider(const Point& top_left, const Point& buttom_right);
        BoxCollider(const BoxCollider& box_collider);

    public:
        Collider getTopSide() const;
        Collider getRightSide() const;
        Collider getButtomSide() const;
        Collider getLeftSide() const;

        Point getTopLeftPoint() const;
        Point getTopRightPoint() const;
        Point getButtomRightPoint() const;
        Point getButtomLeftPoint() const;
    };
}

#endif