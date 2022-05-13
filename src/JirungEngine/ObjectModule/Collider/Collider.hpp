#ifndef __Collider_hpp__
#define __Collider_hpp__

#include "../../MathModule/Point/Point.hpp"
#include "../../MathModule/Vector/Vector2D.hpp"
//#include "../Object/Object.hpp"


namespace JirungEngine {
    class Collider {
        public: Point start_point;
        public: Vector2D vector;
        //private: Object* parent;

    public:
        Collider(const Point& start_point, const Vector2D& vector);
        Collider(const Collider& new_collider);

    public:
        
    };
}

#endif