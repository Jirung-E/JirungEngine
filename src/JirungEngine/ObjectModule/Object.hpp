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
        
        protected: Point prev_frame_position;
        protected: Physics prev_frame_physics;
        
        public: TextImage* image;

        protected: Collider prev_to_current;
        protected: std::list<Collider> collider;
        protected: std::list<BoxCollider*> box_collider;

    public:
        Object(std::string id = "object", const Point& position = Point { 0, 0, 0 });
        Object(std::string id);
        ~Object();

        void update();
        void back();

        void addCollider(const Point& start_point, const Vector& vector);
        //void addCollider(BoxCollider& collider);
        
        bool isCollidingWith(const Object& other) const;
    };
}

#endif