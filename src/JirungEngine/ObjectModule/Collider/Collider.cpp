#include "Collider.hpp"

using namespace JirungEngine;


Collider::Collider(const Point& start_point, const Vector& vector) : start_point { start_point }, vector { vector } {
    
}

Collider::Collider(const Collider& new_collider) : start_point { new_collider.start_point }, vector { new_collider.vector } {
    
}


Collider Collider::operator=(const Collider& new_collider) {
    start_point = new_collider.start_point;
    vector = new_collider.vector;
    return *this;
}

bool Collider::operator==(const Collider& new_collider) const {
    if(this == &new_collider) {
        return true;
    }
    return false;
}


bool Collider::isCollidingWith(const Collider& other) const {
    if(this->line().isExistPointOfContactWith(other.line())) {
        Point point_of_contact { Segment::getFootOfPerpendicular(this->line(), other.line()) };
        if(point_of_contact.isInRange(this->start_point, this->getEndPoint()) && point_of_contact.isInRange(other.start_point, other.getEndPoint())) {
            return true;
        }
    }
    return false;
}

Point Collider::getEndPoint() const {
    return Point { start_point.x + vector.x, start_point.y + vector.y, start_point.z + vector.z };
}

Segment Collider::line() const {
    Segment segment { start_point, vector };
    return segment;
}