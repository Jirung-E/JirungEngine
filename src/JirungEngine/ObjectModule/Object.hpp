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
        public: std::list<Collider> collider;
        public: std::list<BoxCollider> box_collider;

        protected: Object* parent_object;
        protected: std::list<Object*> child_object;

        public: static std::list<Object*> object_list;
        public: static EventListener event_listener;

    public:
        Object(std::string id, const Point& position = Point { 0, 0, 0 }, Object* parent_object = nullptr);
        Object(std::string id, Object* parent_object);
        ~Object();

        void addChild(Object& object);
        void setParent(Object& object);
        Object* getParent();
        Object* getChildById(std::string id);

        void update();

        bool isCollide() const;
        Object* getCollidedObject() const;
    };
}

#endif