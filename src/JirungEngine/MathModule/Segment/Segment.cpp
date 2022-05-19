#include "Segment.hpp"

using namespace std;
using namespace JirungEngine;


Segment::Segment(Point point, Vector direction) : point { point }, direction { direction } {

}

Segment::Segment(Vector direction) : Segment { Point(0, 0, 0), direction } {

}


float Segment::x(float parameter) const {
    return point.x + vector.x*parameter;
}

float Segment::y(float parameter) const {
    return point.y + vector.y*parameter;
}

float Segment::z(float parameter) const {
    return point.z + vector.z*parameter;
}