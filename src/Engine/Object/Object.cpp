#include "Object.hpp"

using namespace Engine;
using namespace Math;
using namespace std;


Object::Object() : Geometry { } {
    
}

Object::~Object() {
    // playDestructionSound();
    
    for(auto e : polygons) {
        delete e;
    }
    // for(int i=0; i<polygons.size(); ++i) {
        
    // }
}


void Object::addPolygon(Polygon* polygon, Point point) {
    polygon->moveTo(polygon->p1 + point);
    polygons.push_back(polygon);
}


void Object::rotateX(float radian) {
    Line x_axis { Vector::i() };
    for(auto e : polygons) {
        e->rotate(x_axis, radian);
    }
}

void Object::rotateY(float radian) {
    Line y_axis { Vector::j() };
    for(auto e : polygons) {
        e->rotate(y_axis, radian);
    }
}

void Object::rotateZ(float radian) {
    Line z_axis { Vector::k() };
    for(auto e : polygons) {
        e->rotate(z_axis, radian);
    }
}

void Object::rotate(const Line& axis, float radian) {
    for(auto e : polygons) {
        e->rotate(axis, radian);
    }
}

void Object::moveTo(const Point& point) {
    for(auto e : polygons) {
        e->moveTo(point);
    }
    Geometry::moveTo(point);
}

void Object::update() {
    physics.update();
    moveTo(position + physics.velocity);
}