#include "Segment.hpp"

using namespace std;
using namespace JirungEngine;


Segment::Segment(Point point, Vector direction) : point { point }, direction { direction } {

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
    float tx = (-this->point.x + other.x) / (this->direction.x - other.direction.x);                    // -> 분모가 0인경우 예외처리 해야함
    float ty = (-this->point.y + other.y) / (this->direction.y - other.direction.y);
    float tz = (-this->point.z + other.z) / (this->direction.z - other.direction.z);

    if(tx == ty && ty == tz) {
        return true;
    }
    return false;
}

Point* Segment::getPointOfContactWith(const Segment& other) const {
    float tx = (-this->point.x + other.x) / (this->direction.x - other.direction.x);
    float ty = (-this->point.y + other.y) / (this->direction.y - other.direction.y);
    float tz = (-this->point.z + other.z) / (this->direction.z - other.direction.z);

    if(tx == ty && ty == tz) {
        return new Point { x(tx), y(ty), z(tz) };
    }
    return nullptr;
}