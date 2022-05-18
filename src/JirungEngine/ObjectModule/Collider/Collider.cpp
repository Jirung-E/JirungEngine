#include "Collider.hpp"

using namespace JirungEngine;


Collider::Collider(const Point& start_point, const Vector& vector) : start_point { start_point }, vector { vector } {
    
}

Collider::Collider(const Collider& new_collider) : start_point { new_collider.start_point }, vector { new_collider.vector } {
    
}


bool Collider::isCollidingWith(const Collider& other) const {
    
}