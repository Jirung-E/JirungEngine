#include "Polygon.hpp"

#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif
#include <cmath>

using namespace Math;


Polygon::Polygon() : p1 { 0, 1, 0 }, 
p2 { static_cast<float>(-1.0f*cos(M_PI/6)), -1.0f/2, 0 }, 
p3 { static_cast<float>(1.0f*cos(M_PI/6)), -1.0f/2, 0 } {

}

Polygon::Polygon(const Point& p1, const Point& p2, const Point& p3) : p1 { p1 }, p2 { p2 }, p3 { p3 } {

}


Vector Polygon::normal() const {
    return Vector(p2-p1).cross(Vector(p3-p1));
}

Point Polygon::centerOfGravity() const {
    Point center_of_p2_p3 { (p2 + p3) / 2 };
    Vector p1_to_h { center_of_p2_p3 - p1 };
    p1_to_h *= 2.0f/3.0f;
    return p1 + Point { p1_to_h.x, p1_to_h.y, p1_to_h.z };
}


void Polygon::moveTo(const Point& point) {
    p2 -= p1;
    p2 += point;
    p3 -= p1;
    p3 += point;
    p1 = point;
}

void Polygon::transformNormalVectorTo(const Vector& vector) {
    Vector v1 { normal() };
    Vector v2 { vector };
    Line n { v1.cross(v2) };
    float theta = angleBetween(v1, v2);

    p1 = Line::rotate(p1, n, theta);
    p2 = Line::rotate(p2, n, theta);
    p3 = Line::rotate(p3, n, theta);
}

void Polygon::rotate(float radian) {
    Line n { p1, normal() };
    p1 = Line::rotate(p1, n, radian);
    p2 = Line::rotate(p2, n, radian);
    p3 = Line::rotate(p3, n, radian);
}

void Polygon::rotate(const Line& axis, float radian) {
    p1 = Line::rotate(p1, axis, radian);
    p2 = Line::rotate(p2, axis, radian);
    p3 = Line::rotate(p3, axis, radian);
}


Polygon Polygon::operator*(float n) const {
    Polygon poly { *this };

    Vector v1 { Vector(p2-p1) * n };
    Vector v2 { Vector(p3-p1) * n };

    poly.p2 = p1 + Point {v1.x, v1.y, v1.z };
    poly.p3 = p1 + Point {v2.x, v2.y, v2.z };
    
    return poly;
}

Polygon Polygon::operator/(float n) const {
    Polygon poly { *this };

    Vector v1 { Vector(p2-p1) / n };
    Vector v2 { Vector(p3-p1) / n };

    poly.p2 = p1 + Point {v1.x, v1.y, v1.z };
    poly.p3 = p1 + Point {v2.x, v2.y, v2.z };
    
    return poly;
}

Polygon& Polygon::operator*=(float n) {
    Vector v1 { Vector(p2-p1) * n };
    Vector v2 { Vector(p3-p1) * n };

    p2 = p1 + Point {v1.x, v1.y, v1.z };
    p3 = p1 + Point {v2.x, v2.y, v2.z };
    
    return *this;
}

Polygon& Polygon::operator/=(float n) {
    Vector v1 { Vector(p2-p1) / n };
    Vector v2 { Vector(p3-p1) / n };

    p2 = p1 + Point {v1.x, v1.y, v1.z };
    p3 = p1 + Point {v2.x, v2.y, v2.z };
    
    return *this;
}
