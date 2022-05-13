#ifndef __BoxCollider_hpp__
#define __BoxCollider_hpp__

#include "Collider.hpp"

#include "../../MathModule/Point/Point.hpp"


namespace JirungEngine {
    class BoxCollider : public Collider {
        public: Point top_left;
        public: Point buttom_right;
        private: Collider side[4];

    public:
        BoxCollider(const Point& top_left, const Point& buttom_right);
    };
}

#endif