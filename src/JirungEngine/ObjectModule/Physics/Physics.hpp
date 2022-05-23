#ifndef __Physics_hpp__
#define __Physics_hpp__

#include "../../MathModule/Point/Point.hpp"
#include "../../MathModule/Vector/Vector.hpp"


namespace JirungEngine {
    class Physics {
        public: float elasticity;  // max: 1   if x > 1   ->   x = 1
        public: float density;     // max: 1
        public: Vector velocity;
        public: Vector acceleration;
        public: Vector gravity;
        public: float rotate_speed;
        public: Point rotate_pivot;
        
    public:
        Physics() = default;
        Physics(const Physics&) = default;
    };
}

#endif