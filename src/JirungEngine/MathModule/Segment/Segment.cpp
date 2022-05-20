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
    Vector normal { Vector::crossProduct(this->direction, other.direction) };
}

float Segment::getDistanceTo(const Segment& other) const {
    Vector start_point_to_start_point { other.point.x - this->point.x, other.point.y - this->point.y, other.point.z - this->point.z };
    return start_point_to_start_point * this->direction.crossProduct(other.direction).getUnitVector();
}

bool Segment::isParallelTo(const Segment& other) const {
    if(this->direction.x / other.direction.x == this->direction.y / other.direction.y && this->direction.y / other.direction.y == this->direction.z / other.direction.z) {
        return true;
    }
    return false;
}

float Segment::getDistanceBetween(const Segment& line1, const Segment& line2) {
    Vector start_point_to_start_point { line2.point.x - line1.point.x, line2.point.y - line1.point.y, line2.point.z - line1.point.z };
    return start_point_to_start_point * Vector::crossProduct(line1.direction, line2.direction).getUnitVector();
}

Segment Segment::getNormalOf(const Segment& line1, const Segment& line2) {
    
}

bool Segment::isParallel(const Segment& line1, const Segment& line2) {
    if(line1.direction.x / line2.direction.x == line1.direction.y / line2.direction.y && line1.direction.y / line2.direction.y == line1.direction.z / line2.direction.z) {
        return true;
    }
    return false;
}