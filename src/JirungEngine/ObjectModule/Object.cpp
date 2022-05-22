#include "Object.hpp"

using namespace std;
using namespace JirungEngine;


list<Object*> Object::object_list;

Object::Object(string id, const Point& position) : id { id }, position { position }, image { nullptr }, 
    prev_frame_position { position }, prev_to_current { prev_frame_position, Vector(position - prev_frame_position) } {
    collider.push_back(prev_to_current);
    object_list.push_back(this);
}

Object::~Object() {
    object_list.remove(this);
}


void Object::update() {
    collider.remove(prev_to_current);
    
    prev_frame_position = position;
    prev_frame_physics = physics;
    
    physics.velocity += physics.acceleration + physics.gravity;
    position += Point { physics.velocity.x, physics.velocity.y, physics.velocity.z };
    for(Collider& c : collider) {
        c.start_point += Point { physics.velocity.x, physics.velocity.y, physics.velocity.z };
    }

    prev_to_current.start_point = prev_frame_position;
    prev_to_current.vector = Vector(position - prev_frame_position);
    collider.push_back(prev_to_current);
}

void Object::backToPrevFrame() {
    position = prev_frame_position;
    physics = prev_frame_physics;
    collider.remove(prev_to_current);
}

void Object::addCollider(const Point& start_point, const Vector& vector) {
    this->collider.push_back(Collider(start_point, vector));
}

// void Object::addCollider(BoxCollider& collider) {

// }

bool Object::isCollidingWith(const Object& other) const {
    for(const Collider& c : collider) {
        for(const Collider& other_c : other.collider) {
            if(c.isCollidingWith(other_c)) {
                return true;
            }
        }
    }
    return false;
}

bool Object::isCollide() {
    if(event_listener.getEvent() == Condition::Collide) {
        return true;
    }
    return false;
}