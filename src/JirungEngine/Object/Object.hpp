#ifndef __Object_hpp__
#define __Object_hpp__

#include "../Point/Point.hpp"
#include "../Collider/BoxCollider/BoxCollider.hpp"

#include "../../Util/UtilType.hpp"

#include <list>


namespace JirungEngine {
    class Object {
        public: std::string id;
        public: Point position;
        public: BoxCollider* box_collider;
        public: Object* parent_object;
        private: std::list<Object*> child_object;

        private: static std::list<std::string> object_id_list;

    public:
        Object(std::string id, const Object* parent_object = nullptr);
        Object(std::string id, const Point& position = Position { 0, 0, 0 }, const Object* parent_object = nullptr);
        ~Object();

        Object* getParent();
        Object* getChildById(std::string id);
    };
}

#endif