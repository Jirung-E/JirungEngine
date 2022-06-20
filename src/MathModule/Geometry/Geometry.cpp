#include "Geometry.hpp"

using namespace Math;


Geometry::Geometry() : position { 0, 0, 0 }, x_axis { position, Vector::i() }, y_axis { position, Vector::j() }, z_axis { position, Vector::k() } {

}


Point Geometry::getPosition() const {
    return position;
}

void Geometry::moveTo(const Point& point) {
    Point p { point - position };

    position += p;
    x_axis.point += p;
    y_axis.point += p;
    z_axis.point += p;
}

Line Geometry::getXAxis() const {
    return x_axis;
}

Line Geometry::getYAxis() const {
    return y_axis;
}

Line Geometry::getZAxis() const {
    return z_axis;
}

void Geometry::rotateX(float radian) {
    rotate(x_axis, radian);
}

void Geometry::rotateY(float radian) {
    rotate(y_axis, radian);
}

void Geometry::rotateZ(float radian) {
    rotate(z_axis, radian);
}

void Geometry::rotate(const Line& axis, float radian) {
    Point x_end { x_axis.point + Point(x_axis.vector.x, x_axis.vector.y, x_axis.vector.z) };
    Point y_end { y_axis.point + Point(y_axis.vector.x, y_axis.vector.y, y_axis.vector.z) };
    Point z_end { z_axis.point + Point(z_axis.vector.x, z_axis.vector.y, z_axis.vector.z) };

    position = Line::rotate(position, axis, radian);
    x_axis.vector = Vector { Line::rotate(x_end, axis, radian) - position };
    y_axis.vector = Vector { Line::rotate(y_end, axis, radian) - position };
    z_axis.vector = Vector { Line::rotate(z_end, axis, radian) - position };
}