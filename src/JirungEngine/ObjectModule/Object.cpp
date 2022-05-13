#include "Object.hpp"

using namespace std;
using namespace JirungEngine;


std::list<std::string> Object::object_id_list;

Object::Object(string id, Object* parent_object) : id { id }, position { 0, 0, 0 }, parent_object { parent_object } {
    object_id_list.push_back(id);
}

Object::Object(string id, const Point& position, Object* parent_object) : id { id }, position { position }, parent_object { parent_object } {
    object_id_list.push_back(id);
}

Object::~Object() {
    object_id_list.remove(id);
}


Object* Object::getParent() {
    return parent_object;
}

Object* Object::getChildById(string id) {
    return nullptr;
}