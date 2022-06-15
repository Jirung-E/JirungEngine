#include "Model.hpp"

using namespace std;
using namespace JirungEngine;


Model::Model() : polygons { Polygon { } } {
    polygons[0].moveTo({ 0, 1, 0 });
}


void Model::moveTo(const Point& point) {
    Point p { point - getPosition() };
    for(Polygon& e : polygons) {
        e.moveTo(e.p1 + p);
    }
    Geometry::moveTo(point);
}


// void Model::addPolygon(const Polygon& polygon) { }


void Model::rotateX(float radian) {
    rotate(getXAxis(), radian);
}

void Model::rotateY(float radian) {
    rotate(getYAxis(), radian);
}

void Model::rotateZ(float radian) {
    rotate(getZAxis(), radian);
}

void Model::rotate(const Line& axis, float radian) {
    Geometry::rotate(axis, radian);
    for(Polygon& e : polygons) {
        e.rotate(axis, radian);
    }
}


Model Model::operator*(float n) const {
    Model m { *this };

    for(Polygon& e : m.polygons) {
        Point position_to_polygon { e.p1 - getPosition() };
        e.moveTo(getPosition() + position_to_polygon * n);
        e *= n;
    }
    
    return m;
}

Model Model::operator/(float n) const {
    Model m { *this };

    for(Polygon& e : m.polygons) {
        Point position_to_polygon { e.p1 - getPosition() };
        e.moveTo(getPosition() + position_to_polygon / n);
        e /= n;
    }
    
    return m;
}

Model Model::operator*=(float n) {
    for(Polygon& e : polygons) {
        Point position_to_polygon { e.p1 - getPosition() };
        e.moveTo(getPosition() + position_to_polygon * n);
        e *= n;
    }
    
    return *this;
}

Model Model::operator/=(float n) {
    for(Polygon& e : polygons) {
        Point position_to_polygon { e.p1 - getPosition() };
        e.moveTo(getPosition() + position_to_polygon / n);
        e /= n;
    }
    
    return *this;
}