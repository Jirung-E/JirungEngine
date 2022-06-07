#include "Model.hpp"

using namespace std;
using namespace JirungEngine;


Model::Model() : position { 0, 0, 0 }, 
pivot { 0, 0, 0 }, x_axis { pivot, Vector::i() }, y_axis { pivot, Vector::j() }, z_axis { pivot, Vector::k() }, 
polygons { Polygon { } } {

}


Point Model::getPivot() const {
    return pivot;
}

void Model::setPivot(const Point& point) {
    pivot = point;
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
    rotate(x_axis, radian);
}

void Model::rotateZ(float radian) {
    rotate(x_axis, radian);
}

void Model::rotate(const Line& axis, float radian) {
    for(Polygon& e : polygons) {
        e.rotate(axis, radian);
    }
}


Polygon Model::operator*(float n) const {
    Polygon poly { *this };

    for(Polygon& e : poly.polygons) {
        e *= n;
    }
    
    return poly;
}

Polygon Model::operator/(float n) const {
    Polygon poly { *this };

    for(Polygon& e : poly.polygons) {
        e /= n;
    }
    
    return poly;
}

Polygon Model::operator*=(float n) {
    for(Polygon& e : polygons) {
        e *= n;
    }
    
    return *this;
}

Polygon Model::operator/=(float n) {
    for(Polygon& e : polygons) {
        e /= n;
    }
    
    return *this;
}