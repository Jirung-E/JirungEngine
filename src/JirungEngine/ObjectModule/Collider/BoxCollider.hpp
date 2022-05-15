#ifndef __BoxCollider_hpp__
#define __BoxCollider_hpp__

#include "Collider.hpp"

#include "../../MathModule/Point/Point.hpp"


namespace JirungEngine {
    class BoxCollider {
        private: Point top_left;
        private: Point top_right;
        private: Point buttom_right;
        private: Point buttom_left;
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

        void setTopLeftPoint(const Point& point);
        void setTopRightPoint(const Point& point);
        void setButtomRightPoint(const Point& point);
        void setButtomLeftPoint(const Point& point);
    };
}

#endif