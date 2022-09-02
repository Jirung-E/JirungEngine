#include "Object.hpp"

using namespace Engine;
using namespace Math;
using namespace std;


Object::Object() : geometry { } {
    
}

Object::~Object() {
    // playDestructionSound();
    
    for(auto e : polygons) {
        delete e;
    }
    // for(int i=0; i<polygons.size(); ++i) {
        
    // }
}


void Object::addPolygon(Polygon& polygon, Point& point) {
    polygon.moveTo(polygon.p1 + point);
    polygons.push_back(polygon);
}