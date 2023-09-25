#include "Point.hpp"

#include <cmath>

#include "../Vector/Vector.hpp"

using namespace Math;


Point::Point(float x, float y, float z) : x { x }, y { y }, z { z } {
    
}

Point::Point() : Point { 0, 0, 0 } {
    
}

Point::Point(const Point& point) : Point { point.x, point.y, point.z } {
    
}

Point::Point(const Vector& vector) : Point { vector.x, vector.y, vector.z } {

}


Point Point::operator=(const Point& point) {
    x = point.x;
    y = point.y;
    z = point.z;
    return *this;
}

Point Point::operator+(const Point& point) const {
    return Point { x + point.x, y + point.y, z + point.z };
}

Point Point::operator*(float n) const {
    return Point { x*n, y*n, z*n };
}

Point Point::operator/(float n) const {
    return Point { x/n, y/n, z/n };
}

bool Point::operator==(const Point& point) const {
    if(x == point.x && y == point.y && z == point.z) {
        return true;
    }
    return false;
}

bool Point::operator!=(const Point& point) const {
    return !(*this == point);
}

Point Point::operator+=(const Point& point) {
    x += point.x;
    y += point.y;
    z += point.z;
    return *this;
}

Point Point::operator*=(float n) {
    x *= n;
    y *= n;
    z *= n;
    return *this;
}

Point Point::operator/=(float n) {
    x /= n;
    y /= n;
    z /= n;
    return *this;
}

bool Point::isInRange(const Point& point1, const Point& point2) const {
    if(point1.x < point2.x) {
        if(x < point1.x || point2.x < x) {
            return false;
        }
    }
    else {
        if(x < point2.x || point1.x < x) {
            return false;
        }
    }

    if(point1.y < point2.y) {
        if(y < point1.y || point2.y < y) {
            return false;
        }
    }
    else {
        if(y < point2.y || point1.y < y) {
            return false;
        }
    }

    if(point1.z < point2.z) {
        if(z < point1.z || point2.z < z) {
            return false;
        }
    }
    else {
        if(z < point2.z || point1.z < z) {
            return false;
        }
    }

    return true;
}

float Point::getDistanceTo(const Point& other) const {
    return getDistanceBetween(*this, other);
}

float Point::getDistanceBetween(const Point& point1, const Point& point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2) + pow(point1.z - point2.z, 2));
}


Point Point::origin() {
    return Point { 0, 0, 0 };
}