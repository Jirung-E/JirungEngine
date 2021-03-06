#include "Plane.hpp"

#include <cmath>

using namespace std;
using namespace JirungEngine;


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

Point* Plane::getPointOfContactWith(const Line& line) const {
    if(this->isParallelTo(line)) {
        if(this->getDistanceTo(line) == 0.0f) {
            return new Point { line.point };
        }
        return nullptr;
    }
    
    Point A { line.point };
    // Point H { getFootOfPerpendicularFrom(A) };
    float AH = getDistanceTo(A);
    float theta = Vector::getAngleBetween(this->normal_vector, line.vector);
    float AP = AH / cos(theta);
    Vector V { line.vector.getUnitVector() * AP };
    return new Point { A - Point(V.x, V.y, V.z) };
}

Line* Plane::getLineOfIntersectionWith(const Plane& other) const {
    if(this->isParallelTo(other)) {
        return nullptr;
    }

    Point S { other.point };
    Point E { S + Point { other.normal_vector.x, other.normal_vector.y, other.normal_vector.z } };
    Point H { getFootOfPerpendicularFrom(S) };
    Point F { getFootOfPerpendicularFrom(E) };

    Vector line_vector { Vector::crossProduct(this->normal_vector, other.normal_vector) };
    Point line_point;

    if(this->getDistanceTo(S) == 0.0f) {
        return new Line { S, line_vector };
    }

    float theta = Vector::getAngleBetween(this->normal_vector, other.normal_vector);
    if(theta == M_PI/2.0f) {
        return new Line { H, line_vector };
    }
    
    float dist = abs(Point::getDistanceBetween(S, H)/tan(theta));
    Vector vec { Vector(F-H).getUnitVector() };
    if(theta > M_PI/2.0f) {
        vec *= -1;
    }
    line_point = H + Point(vec.x, vec.y, vec.z)*dist;

    return new Line { line_point, line_vector };
}

Point Plane::getFootOfPerpendicularFrom(const Point& point) const {
    Vector v { this->normal_vector.getUnitVector() * this->getDistanceTo(point) };
    if(this->normal_vector * Vector(point - this->point) > 0.0f) {
        return point - Point { v.x, v.y, v.z };
    }
    return point + Point { v.x, v.y, v.z };
}

float Plane::getDistanceTo(const Point& point) const {
    if(isContactWith(point)) {
        return 0.0f;
    }

    return abs(normal_vector.getUnitVector() * Vector(point - this->point));
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
    return abs(M_PI/2.0f - Vector::getAngleBetween(this->normal_vector, line.vector));
}

float Plane::getAngleWith(const Plane& other) const {
    float theta = Vector::getAngleBetween(this->normal_vector, other.normal_vector);
    if(theta > M_PI/2.0f) {
        theta = M_PI - theta;
    }
    return theta;
}

bool Plane::isParallelTo(const Line& line) const {
    if(Vector::isOrthogonal(this->normal_vector, line.vector)) {
        return true;
    }
    return false;
}

bool Plane::isParallelTo(const Plane& other) const {
    if(Vector::isParallel(this->normal_vector, other.normal_vector)) {
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