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

        protected: std::list<Collider> collider;
        protected: std::list<BoxCollider> box_collider;

    public:
        Object(std::string id = "object", const Point& position = Point { 0, 0, 0 }, Object* parent_object = nullptr);
        Object(std::string id, Object* parent_object);
        ~Object();

        void update();

        void addCollider(const Point& start_point, const Vector& vector);
        //void addCollider(BoxCollider& collider);
    };
}

#endif