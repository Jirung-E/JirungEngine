#include "Object.hpp"

using namespace std;
using namespace JirungEngine;


list<Object*> Object::object_list;

Object::Object(string id, const Point& position) : id { id }, position { position }, image { nullptr }, 
    prev_frame_position { position } {
    collider.push_front(Collider(prev_frame_position, Vector(position - prev_frame_position)));
    setId(id);
    object_list.push_back(this);
}

Object::Object(const Object& object) : Object { object.id + "-clone", object.position } {
    image = new TextImage { *object.image };
    
}

Object::~Object() {
    object_list.remove(this);
}


void Object::setId(std::string id) {
    if(getById(id) != nullptr) {
        const string origin_id = id;
        int num = 1;
        while(true) {
            id = origin_id + "(" + to_string(num) + ")";
            if(getById(id) != nullptr) {
                num++;
            }
            else {
                break;
            }
        }
    }
    
    this->id = id;
}

void Object::changeId(std::string id) {
    setId(id);
}

std::string Object::getId() const {
    return id;
}

void Object::update() {
    prev_frame_position = position;
    prev_frame_physics = physics;
    
    physics.velocity += physics.acceleration + physics.gravity;
    position += Point { physics.velocity.x, physics.velocity.y, physics.velocity.z };
    for(Collider& c : collider) {
        c.start_point += Point { physics.velocity.x, physics.velocity.y, physics.velocity.z };
    }

    collider.front() = Collider { prev_frame_position, Vector(position - prev_frame_position) };
}

void Object::backToPrevFrame() {
    position = prev_frame_position;
    physics = prev_frame_physics;
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

size_t Object::getNumOfColliders() const {
    return collider.size();
}

Object* Object::getById(std::string id) {
    for(Object* o : object_list) {
        if(id == o->id) {
            return o;
        }
    }
    return nullptr;
}