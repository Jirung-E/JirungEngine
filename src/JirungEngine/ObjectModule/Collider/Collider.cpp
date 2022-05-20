#include "Collider.hpp"

using namespace JirungEngine;


Collider::Collider(const Point& start_point, const Vector& vector) : start_point { start_point }, vector { vector } {
    
}

Collider::Collider(const Collider& new_collider) : start_point { new_collider.start_point }, vector { new_collider.vector } {
    
}


bool Collider::isCollidingWith(const Collider& other) const {
    if(isExistPointOfContactWith(other.line())) {
        return true;
    }
    return false;
}

Point Collider::getEndPoint() const {
    return Point { start_point.x + vector.x, start_point.y + vector.y, start_point.z + vector.z };
}

Segment Collider::line() const {
    Segment segment { start_point, vector };
    segment.start_point = new Point(this->start_point);
    segment.end_point = new Point(this->getEndPoint());
}