#include "Model.hpp"

using namespace std;
using namespace JirungEngine;


Model::Model() : position { 0, 0, 0 }, 
pivot { 0, 0, 0 }, x_axis { pivot, Vector::i() }, y_axis { pivot, Vector::j() }, z_axis { pivot, Vector::k() }, 
num_of_polygons { 1 }, polygons { Polygon { } } {

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
        //?
    }

    position = point;
}


// void Model::addPolygon(const Polygon& polygon) { }

void Model::rotate(float radian) {

}

void Model::rotate(const Line& axis, float radian) {

}


Polygon Model::operator*(float n) const {
    Polygon poly { *this };


    
    return poly;
}

Polygon Model::operator/(float n) const {
    Polygon poly { *this };


    
    return poly;
}

Polygon Model::operator*=(float n) {
    Polygon poly { *this };


    
    return poly;
}

Polygon Model::operator/=(float n) {
    Polygon poly { *this };
    
    
    
    return poly;
}