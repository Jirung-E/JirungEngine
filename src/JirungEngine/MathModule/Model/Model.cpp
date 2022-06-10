#include "Model.hpp"

using namespace std;
using namespace JirungEngine;


Model::Model() : position { 0, 0, 0 }, 
pivot { 0, 0, 0 }, x_axis { pivot, Vector::i() }, y_axis { pivot, Vector::j() }, z_axis { pivot, Vector::k() }, 
polygons { Polygon { } } {
    polygons[0].moveTo({ 0, 1, 0 });
}


Point Model::getPivot() const {
    return pivot;
}

void Model::setPivot(const Point& point) {
    pivot = point;
    x_axis.point = point;
    y_axis.point = point;
    z_axis.point = point;
}


void Model::moveTo(const Point& point) {
    Point p { point - position };

    position = point;

    pivot += p;
    x_axis.point += p;
    y_axis.point += p;
    z_axis.point += p;

    for(Polygon& e : polygons) {
        e.moveTo(e.p1 + p);
    }

    position = point;
}


// void Model::addPolygon(const Polygon& polygon) { }


void Model::rotateX(float radian) {
    rotate(x_axis, radian);
}

void Model::rotateY(float radian) {
    rotate(y_axis, radian);
}

void Model::rotateZ(float radian) {
    rotate(z_axis, radian);
}

void Model::rotate(const Line& axis, float radian) {
    for(Polygon& e : polygons) {
        e.rotate(axis, radian);
    }
    x_axis.vector = Vector { Line::rotate(x_axis.point + Point(x_axis.vector.x, x_axis.vector.y, x_axis.vector.z), axis, radian) - x_axis.point };
    y_axis.vector = Vector { Line::rotate(y_axis.point + Point(y_axis.vector.x, y_axis.vector.y, y_axis.vector.z), axis, radian) - y_axis.point };
    z_axis.vector = Vector { Line::rotate(z_axis.point + Point(z_axis.vector.x, z_axis.vector.y, z_axis.vector.z), axis, radian) - z_axis.point };
}


Line Model::getXAxis() const {
    return x_axis;
}

Line Model::getYAxis() const {
    return y_axis;
}

Line Model::getZAxis() const {
    return z_axis;
}


Model Model::operator*(float n) const {
    Model m { *this };

    for(Polygon& e : m.polygons) {
        Point pivot_to_polygon { e.p1 - pivot };
        e.moveTo(pivot + pivot_to_polygon * n);
        e *= n;
    }
    
    return m;
}

Model Model::operator/(float n) const {
    Model m { *this };

    for(Polygon& e : m.polygons) {
        Point pivot_to_polygon { e.p1 - pivot };
        e.moveTo(pivot + pivot_to_polygon / n);
        e /= n;
    }
    
    return m;
}

Model Model::operator*=(float n) {
    for(Polygon& e : polygons) {
        Point pivot_to_polygon { e.p1 - pivot };
        e.moveTo(pivot + pivot_to_polygon * n);
        e *= n;
    }
    
    return *this;
}

Model Model::operator/=(float n) {
    for(Polygon& e : polygons) {
        Point pivot_to_polygon { e.p1 - pivot };
        e.moveTo(pivot + pivot_to_polygon / n);
        e /= n;
    }
    
    return *this;
}