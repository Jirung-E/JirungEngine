#include "Segment.hpp"

using namespace std;
using namespace JirungEngine;


Segment::Segment(Point point, Vector direction) : point { point }, direction { direction }, start_point { nullptr }, end_point { nullptr } {

}

Segment::Segment(Vector direction) : Segment { Point(0, 0, 0), direction } {

}


float Segment::x(float parameter) const {
    return point.x + direction.x*parameter;
}

float Segment::y(float parameter) const {
    return point.y + direction.y*parameter;
}

float Segment::z(float parameter) const {
    return point.z + direction.z*parameter;
}

bool Segment::isExistPointOfContactWith(const Segment& other) const {
    Vector normal { Vector::crossProduct(*this, other) };
}

float Segment::getDistanceTo(const Segment& other) const {
    
}

bool Segment::isParallelTo(const Segment& other) const {
    if(this->direction.x / other.direction.x == this->direction.y / other.direction.y && this->direction.y / other.direction.y == this->direction.z / other.direction.z) {
        return true;
    }
    return false;
}

float Segment::getDistanceBetween(const Segment& line1, const Segment& line2) {

}

Segment Segment::getNormalOf(const Segment& line1, const Segment& line2) {
    
}

bool Segment::isParallel(const Segment& line1, const Segment& line2) {
    if(line1.direction.x / line2.direction.x == line1.direction.y / line2.direction.y && line1.direction.y / line2.direction.y == line1.direction.z / line2.direction.z) {
        return true;
    }
    return false;
}