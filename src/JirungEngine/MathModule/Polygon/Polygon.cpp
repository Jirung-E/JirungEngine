#include "Polygon.hpp"

#include <cmath>

#include "../Line/Line.hpp"

using namespace std;
using namespace JirungEngine;


Polygon::Polygon() : p1 { 0, 1, 0 }, p2 { -1.0f*cos(M_PI/6), -1.0f/2, 0 }, p3 { 1.0f*cos(M_PI/6), -1.0f/2, 0 } {

}


Vector Polygon::getNormal() const {
    return Vector::crossProduct(Vector(p2-p1), Vector(p3-p1)).getUnitVector();
}

Point Polygon::getCenterOfGravity() const {
    Point center_of_p2_p3 { (p2 + p3) / 2 };
    Vector p1_to_h { center_of_p2_p3 - p1 };
    p1_to_h *= 2.0f/3.0f;
    return p1 + Point { p1_to_h.x, p1_to_h.y, p1_to_h.z };
}


void Polygon::moveTo(const Point& point) {
    p1 = point;
    p2 += -p1 + point;
    p3 += -p1 + point;
}

void Polygon::transformNormalVectorTo(const Vector& vector) {
    Vector v1 { normal_vector };
    Vector v2 { vector };
    Line n { Vector::crossProduct(v1, v2) };
    float theta = Vector::getAngleBetween(v1, v2);

    p1 = Line::rotate(p1, n, theta);
    p2 = Line::rotate(p2, n, theta);
    p3 = Line::rotate(p3, n, theta);
}

void Polygon::rotate(float radian) {
    Line n { normal_vector };
    p1 = Line::rotate(p1, n, radian);
    p2 = Line::rotate(p2, n, radian);
    p3 = Line::rotate(p3, n, radian);
}