#ifndef __Physics_hpp__
#define __Physics_hpp__

#include "../../MathModule/Point/Point.hpp"
#include "../../MathModule/Vector/Vector.hpp"


namespace JirungEngine {
    class Physics {
        public: unsigned short int elasticity;  // max: 1   if x > 1   ->   x = 1
        public: unsigned short int density;     // max: 1
        public: Vector velocity;
        public: float rotate_speed;
        public: Point rotate_pivot;
    };
}

#endif