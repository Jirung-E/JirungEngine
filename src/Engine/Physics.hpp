#ifndef __Physics_hpp__
#define __Physics_hpp__

#include "../Math/Vector.hpp"


namespace Engine {
    class Physics {
    public:
        Math::Vector velocity;
        Math::Vector acceleration;
        float mass;
        // rotate?
        
    public:
        // Physics();
        
        void update();
    };
}

#endif