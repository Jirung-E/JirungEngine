#include "Plane.hpp"

#include <cmath>

using namespace std;
using namespace JirungEngine;


Plane(Point point, Vector normal_vector) : point { point }, normal_vector { normal_vector } {
    
}

Plane(Vector normal_vector) : Plane { Point { 0, 0, 0 }, normal_vector } {
    
}


bool Plane::isContactWith(const Point& point) const {
    Vector ptop { point - this->point };
    if(Vector::scalarProduct(normal_vector, ptop) == 0.0f) {
        return true;
    }
    return false;
}

Point* Plane::getPointOfContactWith(const Line& line) const {           // 미완
    return nullptr;
}

Point Plane::getFootOfPerpendicularFrom(const Point& point) const {     // 미완
    return Point();
}

float Plane::getDistanceTo(const Point& point) const {
    if(isContactWith(point)) {
        return 0.0f;
    }

    return abs(vector.getUnitVector() * Vector(point - this->point));
}

float Plane::getDistanceTo(const Line& line) const {
    if(isParallelTo(line)) {
        return getDistanceTo(line.point);
    }

    return 0.0f;
}

float Plane::getDistanceTo(const Plane& other) const {
    if(isParallelTo(other)) {
        return getDistanceTo(other.point);
    }

    return 0.0f;
}

bool Plane::isParallelTo(const Line& line) const {
    if(Vector::scalarProduct(this->normal_vector, line.vector) == 0.0f) {
        return true;
    }
    return false;
}

bool Plane::isParallelTo(const Plane& other) const {
    if(this->normal_vector.getUnitVector() == other.normal_vector.getUnitVector()) {
        return true;
    }
    return false;
}