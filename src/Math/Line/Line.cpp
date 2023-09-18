#include "Line.hpp"

#include <cmath>

using namespace Math;


Line::Line(Point point, Vector vector) : point { point }, vector { vector } {
    
}

Line::Line(Vector vector) : Line { Point {0, 0, 0}, vector } {
    
}


bool Line::isExistPointOfContactWith(const Line& other) const {
    if(getDistanceTo(other) == 0.0f) {
        return true;
    }
    return false;
}

Point* Line::getPointOfContactWith(const Line& other) const {
    if(isExistPointOfContactWith(other)) {
        return new Point { getFootOfPerpendicularFrom(other) };
    }
    return nullptr;
}

Point Line::getFootOfPerpendicularFrom(const Point& point) const {
    return getFootOfPerpendicular(*this, point);
}

Point Line::getFootOfPerpendicularFrom(const Line& line) const {
    return getFootOfPerpendicular(*this, line);
}

float Line::getDistanceTo(const Point& point) const {
    return getDistanceBetween(*this, point);
}

float Line::getDistanceTo(const Line& other) const {
    return getDistanceBetween(*this, other);
}

bool Line::isParallelTo(const Line& other) const {
    return this->vector.isParallelTo(other.vector);
}


float Line::getDistanceBetween(const Point& point, const Line& line) {
    return getDistanceBetween(line, point);
}

float Line::getDistanceBetween(const Line& line, const Point& point) {
    if(line.vector.magnitude() == 0.0f) {
        return Vector(line.point - point).magnitude();
    }
    Point H { getFootOfPerpendicular(line, point) };
    Vector AH { H - point };
    return AH.magnitude();
}

float Line::getDistanceBetween(const Line& line1, const Line& line2) {
    if(line1.point == line2.point) {
        return 0.0f;
    }
    if(isParallel(line1, line2)) {
        return getDistanceBetween(line1, line2.point);
    }
    Vector start_point_to_start_point { line2.point - line1.point };
    return abs(start_point_to_start_point * Vector::crossProduct(line1.vector, line2.vector).unit());
}

Line Line::getNormalOf(const Line& line1, const Line& line2) {
    return Line { getFootOfPerpendicular(line1, line2), Vector::crossProduct(line1.vector, line2.vector) };
}

bool Line::isParallel(const Line& line1, const Line& line2) {
    return line1.isParallelTo(line2);
}

Point Line::getFootOfPerpendicular(const Line& line, const Point& point) {
    if(line.vector.magnitude() == 0.0f) {
        return line.point;
    }
    Point P { line.point };
    Vector V { line.vector };
    Point A { point };
    Vector PA { A - P};
    Vector add { V * ((PA * V) / (V*V)) };
    Point H { P + add };
    return H;
}

Point Line::getFootOfPerpendicular(const Line& to, const Line& from) {
    if(from.vector.magnitude() == 0.0f) {
        return getFootOfPerpendicular(to, from.point);
    }
    if(to.vector.magnitude() == 0.0f) {
        return getFootOfPerpendicular(from, to.point);
    }
    Point H { getFootOfPerpendicular(to, from.point) };
    float HS = sqrt(pow(getDistanceBetween(to, from.point), 2) - pow(getDistanceBetween(to, from), 2));
    float theta = Vector::getAngleBetween(to.vector, from.vector);
    float AH = HS / tan(theta);
    Vector AtoH { to.vector.unit() * AH };
    Point A { H - AtoH };
    return A;
}


Point Line::rotate(const Point& point, const Line& axis, float radian) {
    Point p { axis.getFootOfPerpendicularFrom(point) };
    Vector v { point - p };
    Vector n { axis.vector.unit() };
    Vector result { (v*cos(radian)) + n*(1-cos(radian))*(v*n) + (n.crossProduct(v) * sin(radian)) };
    return p + result;
}