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
    if(getDistanceTo(other) == 0.0f) {
        return true;
    }
    return false;
}

Point* Segment::getPointOfContactWith(const Segment& other) const {
    return nullptr;
}

Point Segment::getFootOfPerpendicularFrom(const Point& point) const {
    return getFootOfPerpendicular(*this, point);
}

Point Segment::getFootOfPerpendicularFrom(const Segment& line) const {

}


float Segment::getDistanceTo(const Segment& other) const {
    Vector start_point_to_start_point { other.point.x - this->point.x, other.point.y - this->point.y, other.point.z - this->point.z };
    return start_point_to_start_point * this->direction.crossProduct(other.direction).getUnitVector();
}

bool Segment::isParallelTo(const Segment& other) const {
    if(this->direction.getUnitVector() == other.direction.getUnitVector()) {
        return true;
    }
    if(this->direction.getUnitVector() == other.direction.getUnitVector() * -1) {
        return true;
    }
    return false;
}

float Segment::getDistanceBetween(const Segment& line1, const Segment& line2) {
    Vector start_point_to_start_point { line2.point.x - line1.point.x, line2.point.y - line1.point.y, line2.point.z - line1.point.z };
    return start_point_to_start_point * Vector::crossProduct(line1.direction, line2.direction).getUnitVector();
}

// Segment Segment::getNormalOf(const Segment& line1, const Segment& line2) {
    
// }

bool Segment::isParallel(const Segment& line1, const Segment& line2) {
    if(line1.direction.getUnitVector() == line2.direction.getUnitVector()) {
        return true;
    }
    if(line1.direction.getUnitVector() == line2.direction.getUnitVector() * -1) {
        return true;
    }
    return false;
}

Point Segment::getFootOfPerpendicular(const Segment& line, const Point& point) {
    Point P { line.point };
    Vector V { line.direction };
    Point A { point };

    return P + V * (((A - P) * V) / (V*V));
}