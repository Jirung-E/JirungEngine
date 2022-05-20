#include "Collider.hpp"

using namespace JirungEngine;


Collider::Collider(const Point& start_point, const Vector& vector) : start_point { start_point }, vector { vector } {
    
}

Collider::Collider(const Collider& new_collider) : start_point { new_collider.start_point }, vector { new_collider.vector } {
    
}


bool Collider::isCollidingWith(const Collider& other) const {
    Point* contact = line().getPointOfContactWith(other.line());
    if(contact == nullptr) {
        return false;
    }
    if(!(start_point.x <= contact->x && contact->x <= getEndPoint().x)) {
        return false;
    }
    if(!(start_point.y <= contact->y && contact->y <= getEndPoint().y)) {
        return false;
    }
    if(!(start_point.z <= contact->z && contact->z <= getEndPoint().z)) {
        return false;
    }

    return true;
}

Point Collider::getEndPoint() const {
    return Point { start_point.x + vector.x, start_point.y + vector.y, start_point.z + vector.z };
}

Segment Collider::line() const {
    return Segment { start_point, vector };
}