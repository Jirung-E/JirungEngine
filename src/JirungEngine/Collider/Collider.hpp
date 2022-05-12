#ifndef __Collider_hpp__
#define __Collider_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector2D.hpp"
//#include "../Object/Object.hpp"


namespace JirungEngine {
    class Collider {
        public: Point start_point;
        public: Vector2D vector;
        //private: Object* parent;

    public:
        Collider(const Point& start_point, const Vector2D& vector);//, Object* parent = nullptr);

    public:
        
    };
}

#endif