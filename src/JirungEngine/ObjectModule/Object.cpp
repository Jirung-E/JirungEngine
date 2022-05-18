#include "Object.hpp"

using namespace std;
using namespace JirungEngine;


list<string> Object::object_id_list;

Object::Object(string id, const Point& position, Object* parent_object) : id { id }, position { position }, parent_object { parent_object }, image { nullptr } {
    object_id_list.push_back(id);
}

Object::Object(string id, Object* parent_object) : Object { id, Point { 0, 0, 0 }, parent_object } {
    
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

void Object::update() {
    physics.velocity += physics.acceleration + physics.gravity;
    position += Point { physics.velocity.x, physics.velocity.y, physics.velocity.z };
}