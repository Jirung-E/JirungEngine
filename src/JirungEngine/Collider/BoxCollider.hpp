#ifndef __BoxCollider_hpp__
#define __BoxCollider_hpp__

#include "../Point/Point.hpp"


namespace JirungEngine {
    class BoxCollider {
        public: Point top_left;
        public: Point buttom_right;

    public:
        BoxCollider();
        BoxCollider(const Point& top_left, const Point& buttom_right);
    };
}

#endif