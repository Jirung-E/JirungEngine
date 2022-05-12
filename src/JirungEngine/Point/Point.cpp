#include "Point.hpp"

using namespace JirungEngine;


Point::Point() : x { 0 }, y { 0 }, z { 0 } {

}

Point::Point(int x, int y, int z) : x { x }, y { y }, z { z } {

}

Point::Point(const Point& point) : x { point.x }, y { point.y }, z { point.z } {

}


Point Point::operator=(const Point& point) {
    x = point.x;
    y = point.y;
    z = point.z;
    return *this;
}

Point Point::operator+(const Point& point) {
    return Point { x + point.x, y + point.y, z + point.z };
}

Point Point::operator-(const Point& point) {
    return Point { x - point.x, y - point.y, z - point.z };
}

Point Point::operator*(int n) {
    return Point { x*n, y*n, z*n };
}

Point Point::operator/(int n) {
    return Point { x/n, y/n, z/n };
}