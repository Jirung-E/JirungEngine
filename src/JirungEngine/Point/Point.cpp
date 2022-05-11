#include "Point.hpp"

using namespace JirungEngine;


Point::Point() : x { 0 }, y { 0 } {

}

Point::Point(int x, int y) : x { x }, y { y } {

}

Point::Point(const Point& point) : x { point.x }, y { point.y } {

}


Point Point::operator=(const Point& point) {
    x = point.x;
    y = point.y;
    return *this;
}

Point Point::operator+(const Point& point) {
    return Point { x + point.x, y + point.y };
}

Point Point::operator-(const Point& point) {
    return Point { x - point.x, y - point.y };
}

Point Point::operator*(int n) {
    return Point { x*n, y*n };
}

Point Point::operator/(int n) {
    return Point { x/n, y/n };
}