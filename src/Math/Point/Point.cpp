#include "Point.hpp"

using namespace Math;


Point::Point(float x, float y, float z) : x { x }, y { y }, z { z } {
    
}

Point::Point() : Point { 0, 0, 0 } {
    
}

Point::Point(const Point& point) : Point { point.x, point.y, point.z } {
    
}
