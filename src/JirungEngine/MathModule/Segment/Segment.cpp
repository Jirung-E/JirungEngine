#include "Segment.hpp"

#include <cmath>

using namespace std;
using namespace JirungEngine;


Segment::Segment(Point point, Vector direction) : Line { point, direction } {

}

Segment::Segment(Vector direction) : Segment { Point(0, 0, 0), direction } {

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
    return getFootOfPerpendicular(*this, line);
}

float Segment::getDistanceTo(const Point& point) const {
    return getDistanceBetween(*this, point);
}

float Segment::getDistanceTo(const Segment& other) const {
    return getDistanceBetween(*this, other);
}

bool Segment::isParallelTo(const Segment& other) const {
    return this->direction.isParallelTo(other.direction);
}

float Segment::getDistanceBetween(const Point& point, const Segment& line) {
    return getDistanceBetween(line, point);
}

float Segment::getDistanceBetween(const Segment& line, const Point& point) {
    if(line.direction.magnitude() == 0.0f) {
        return Vector(line.point - point).magnitude();
    }
    Point H { getFootOfPerpendicular(line, point) };
    Vector AH { H - point };
    return AH.magnitude();
}

float Segment::getDistanceBetween(const Segment& line1, const Segment& line2) {
    if(line1.point == line2.point) {
        return 0.0f;
    }
    if(isParallel(line1, line2)) {
        return getDistanceBetween(line1, line2.point);
    }
    Vector start_point_to_start_point { line2.point - line1.point };
    return abs(start_point_to_start_point * Vector::crossProduct(line1.direction, line2.direction).getUnitVector());
}

Segment Segment::getNormalOf(const Segment& line1, const Segment& line2) {
    return Segment { getFootOfPerpendicular(line1, line2), Vector::crossProduct(line1.direction, line2.direction) };
}

bool Segment::isParallel(const Segment& line1, const Segment& line2) {
    return line1.isParallelTo(line2);
}

Point Segment::getFootOfPerpendicular(const Segment& line, const Point& point) {
    if(line.direction.magnitude() == 0.0f) {
        return line.point;
    }
    Point P { line.point };
    Vector V { line.direction };
    Point A { point };
    Vector PA { A.x - P.x, A.y - P.y, A.z - P.z};
    Vector add { V * ((PA * V) / (V*V)) };
    Point H { P.x + add.x, P.y + add.y, P.z + add.z };
    return H;
}

Point Segment::getFootOfPerpendicular(const Segment& to, const Segment& from) {
    if(from.direction.magnitude() == 0.0f) {
        return getFootOfPerpendicular(to, from.point);
    }
    if(to.direction.magnitude() == 0.0f) {
        return getFootOfPerpendicular(from, to.point);
    }
    Point H { getFootOfPerpendicular(to, from.point) };
    float HS = sqrt(pow(getDistanceBetween(to, from.point), 2) - pow(getDistanceBetween(to, from), 2));
    float theta = Vector::getAngleBetween(to.direction, from.direction);
    float AH = HS / tan(theta);
    Vector AtoH { to.direction.getUnitVector() * AH };
    Point A { H.x - AtoH.x, H.y - AtoH.y, H.z - AtoH.z };
    return A;
}