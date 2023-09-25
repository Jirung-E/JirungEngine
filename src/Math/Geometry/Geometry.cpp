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
    Point x_end { x_axis.point + x_axis.vector };
    Point y_end { y_axis.point + y_axis.vector };
    Point z_end { z_axis.point + z_axis.vector };

    position = Line::rotate(position, axis, radian);
    x_axis.vector = Vector { Line::rotate(x_end, axis, radian) - position };
    y_axis.vector = Vector { Line::rotate(y_end, axis, radian) - position };
    z_axis.vector = Vector { Line::rotate(z_end, axis, radian) - position };
}