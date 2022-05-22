#include "Object.hpp"

using namespace std;
using namespace JirungEngine;


Object::Object(string id, const Point& position) : id { id }, position { position }, image { nullptr } {
    
}

Object::~Object() {
    
}


void Object::update() {
    physics.velocity += physics.acceleration + physics.gravity;
    position += Point { physics.velocity.x, physics.velocity.y, physics.velocity.z };
}

void Object::addCollider(const Point& start_point, const Vector& vector) {
    this->collider.push_back(Collider(start_point, vector));
}

// void Object::addCollider(BoxCollider& collider) {

// }