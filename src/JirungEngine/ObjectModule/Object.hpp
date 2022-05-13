#ifndef __Object_hpp__
#define __Object_hpp__

#include "../MathModule/Point/Point.hpp"
#include "Collider/Collider.hpp"
#include "Physics/Physics.hpp"

#include "../../Util/UtilType.hpp"

#include <list>


namespace JirungEngine {
    class Object {
        public: std::string id;
        public: Point position;
        public: Physics physics;
        
        public: std::list<Collider*> collider;
        public: Object* parent_object;
        private: std::list<Object*> child_object;

        private: static std::list<std::string> object_id_list;

    public:
        Object(std::string id, Object* parent_object = nullptr);
        Object(std::string id, const Point& position = Point { 0, 0, 0 }, Object* parent_object = nullptr);
        ~Object();

        Object* getParent();
        Object* getChildById(std::string id);
    };
}

#endif