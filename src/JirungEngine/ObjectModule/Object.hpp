#ifndef __Object_hpp__
#define __Object_hpp__

#include "../MathModule/Point/Point.hpp"
#include "../GraphicModule/Image/TextImage.hpp"
#include "Collider/Collider.hpp"
#include "Collider/BoxCollider.hpp"
#include "EventListener/EventListener.hpp"
#include "Physics/Physics.hpp"

#include "../../Util/UtilType.hpp"

#include <list>


namespace JirungEngine {
    class Object {
        public: std::string id;
        public: Point position;
        public: Physics physics;
        
        public: TextImage* image;

    public:
        Object(std::string id, const Point& position = Point { 0, 0, 0 });
        ~Object();

        void update();
    };
}

#endif