#include "Panel.hpp"

#include <cmath>

using namespace std;
using namespace JirungEngine;


Panel::Panel(unsigned int width, unsigned int height) : Plane { }, width { width }, height { height }, rotate_angle { 0.0f } {

}

Panel::Panel() : Panel { 10, 10 } {

}


Point Panel::leftTop() const {
    Vector v { toLeft() + toTop() };
    return point + Point { v.x, v.y, v.z };
}

Point Panel::leftBottom() const {
    Vector v { toLeft() - toTop() };
    return point + Point { v.x, v.y, v.z };
}

Point Panel::rightTop() const {
    Vector v { (toLeft() * -1) + toTop() };
    return point + Point { v.x, v.y, v.z };
}

Point Panel::rightBottom() const {
    Vector v { (toLeft() * -1) - toTop() };
    return point + Point { v.x, v.y, v.z };
}


Point Panel::centerTop() const {
    Vector v { toTop() };
    return point + Point { v.x, v.y, v.z };
}

Point Panel::leftCenter() const {
    Vector v { toLeft() };
    return point + Point { v.x, v.y, v.z };
}

Vector Panel::toTop() const {
    Vector to_top { 0, 0, 0 };

    if(normal_vector.getUnitVector() == Vector { 0, 1, 0 } || normal_vector.magnitude() == 0.0f) {
        to_top.z -= height/2;
        to_top = Vector { Line::rotate(Point(to_top.x, to_top.y, to_top.z), Line(normal_vector), rotate_angle) };
        return to_top;
    }
    if(normal_vector.getUnitVector() == Vector { 0, -1, 0 }) {
        to_top.z += height/2;
        to_top = Vector { Line::rotate(Point(to_top.x, to_top.y, to_top.z), Line(normal_vector), rotate_angle) };
        return to_top;
    }

    float theta = Vector::getAngleBetween(Vector::j(), normal_vector);
    Vector N_xz { normal_vector.x, 0, normal_vector.z };
    N_xz = N_xz.getUnitVector();

    to_top = Vector { (N_xz * -1) * (height/2) * cos(theta) };
    to_top.y = (height/2)*sin(theta);
    
    to_top = Vector { Line::rotate(Point(to_top.x, to_top.y, to_top.z), Line(normal_vector), rotate_angle) };

    return to_top;
}

Vector Panel::toLeft() const {
    Vector to_left { 0, 0, 0 };

    if(normal_vector.isParallelTo(Vector::j()) || normal_vector.magnitude() == 0.0f) {
        to_left.x -= width/2;
        to_left = Vector { Line::rotate(Point(to_left.x, to_left.y, to_left.z), Line(normal_vector), rotate_angle) };
        return to_left;
    }

    Vector N_xz { normal_vector.x, 0, normal_vector.z };
    if((N_xz.x >= 0.0f && N_xz.z >= 0.0f) || (N_xz.x <= 0.0f && N_xz.z <= 0.0f)) {
        to_left = Vector(-normal_vector.z, 0, normal_vector.x).getUnitVector() * (width/2);
    }
    else {
        to_left = Vector(normal_vector.z, 0, -normal_vector.x).getUnitVector() * (width/2);
    }

    to_left = Vector { Line::rotate(Point(to_left.x, to_left.y, to_left.z), Line(normal_vector), rotate_angle) };

    return to_left;
}