#include "Plane.hpp"

#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <iostream>

using namespace Math;


Plane::Plane(Point point, Vector normal_vector) : point { point }, normal_vector { normal_vector } {
    
}

Plane::Plane(Vector normal_vector) : Plane { Point { 0, 0, 0 }, normal_vector } {
    
}


bool Plane::isContactWith(const Point& point) const {
    if(normal_vector * Vector { point - this->point } == 0.0f) {
        return true;
    }
    return false;
}

Point Plane::getPointOfContactWith(const Line& line) const {
    if(this->isParallelTo(line)) {
        if(this->getDistanceTo(line) == 0.0f) {
            return line.point;
        }
        std::cerr << "Error: Plane::getPointOfContactWith(const Line& line) const: line is parallel to plane but not contact with plane" << std::endl;
    }
    
    Point A { line.point };
    // Point H { getFootOfPerpendicularFrom(A) };
    float AH = getDistanceTo(A);
    float theta = angleBetween(this->normal_vector, line.vector);
    float AP = AH / cos(theta);
    Vector V { line.vector.unit() * AP };
    return Point { A - V };
}

Line Plane::getLineOfIntersectionWith(const Plane& other) const {
    if(this->isParallelTo(other)) {
        std::cerr << "Error: Plane::getLineOfIntersectionWith(const Plane& other) const: planes are parallel" << std::endl;
    }

    Point S { other.point };
    Point E { S + Point { other.normal_vector.x, other.normal_vector.y, other.normal_vector.z } };
    Point H { getFootOfPerpendicularFrom(S) };
    Point F { getFootOfPerpendicularFrom(E) };

    Vector line_vector { this->normal_vector.cross(other.normal_vector) };
    Point line_point;

    if(this->getDistanceTo(S) == 0.0f) {
        return Line { S, line_vector };
    }

    float theta = angleBetween(this->normal_vector, other.normal_vector);
    if(theta == M_PI/2.0f) {
        return Line { H, line_vector };
    }
    
    float dist = abs(Point::getDistanceBetween(S, H)/tan(theta));
    Vector vec { Vector(F-H).unit() };
    if(theta > M_PI/2.0f) {
        vec *= -1;
    }
    line_point = H + Point(vec.x, vec.y, vec.z)*dist;

    return Line { line_point, line_vector };
}

Point Plane::getFootOfPerpendicularFrom(const Point& point) const {
    Vector v { this->normal_vector.unit() * this->getDistanceTo(point) };
    if(this->normal_vector * Vector(point - this->point) > 0.0f) {
        return point - v;
    }
    return point + v;
}

float Plane::getDistanceTo(const Point& point) const {
    if(isContactWith(point)) {
        return 0.0f;
    }

    return abs(normal_vector.unit() * Vector(point - this->point));
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

float Plane::getAngleWith(const Line& line) const {
    return (float)abs(M_PI/2.0f - angleBetween(this->normal_vector, line.vector));
}

float Plane::getAngleWith(const Plane& other) const {
    float theta = angleBetween(this->normal_vector, other.normal_vector);
    if(theta > M_PI/2.0f) {
        theta = M_PI - theta;
    }
    return theta;
}

bool Plane::isParallelTo(const Line& line) const {
    if(isOrthogonal(this->normal_vector, line.vector)) {
        return true;
    }
    return false;
}

bool Plane::isParallelTo(const Plane& other) const {
    if(isParallel(this->normal_vector, other.normal_vector)) {
        return true;
    }
    return false;
}


Plane Plane::xy() {
    return Plane { Vector { 0, 0, 1 } };
}

Plane Plane::xz() {
    return Plane { Vector { 0, 1, 0 } };
}

Plane Plane::yz() {
    return Plane { Vector { 1, 0, 0 } };
}