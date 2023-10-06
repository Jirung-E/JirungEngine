#include "Vector.hpp"

#include <cmath>

using namespace Math;


Vector::Vector(float x, float y, float z) : x { x }, y { y }, z { z } {

}

Vector::Vector(const Vector& vector) : Vector { vector.x, vector.y, vector.z } {

}

Vector::Vector(const Point& point) : Vector { point.x, point.y, point.z } {

}

Vector::Vector() : Vector { 0, 0, 0 } {

}


Math::Vector::operator Point() const {
    return Point { x, y, z };
}


Vector Vector::operator+(const Vector& vector) const {
    return Vector { x + vector.x, y + vector.y, z + vector.z };
}

Vector Vector::operator-(const Vector& vector) const {
    return Vector { x - vector.x, y - vector.y, z - vector.z };
}

float Vector::operator*(const Vector& vector) const {
    return x*vector.x + y*vector.y + z*vector.z;
}


Vector Vector::operator*(float n) const {
    return Vector { x*n, y*n, z*n };
}

Vector Vector::operator/(float n) const {
    return Vector { x/n, y/n, z/n };
}


Vector Vector::operator-() {
    return (*this) * -1;
}


Vector& Vector::operator+=(const Vector& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

Vector& Vector::operator-=(const Vector& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

Vector& Vector::operator*=(float n) {
    x *= n;
    y *= n;
    z *= n;
    return *this;
}

Vector& Vector::operator/=(float n) {
    x /= n;
    y /= n;
    z /= n;
    return *this;
}


bool Vector::operator==(const Vector& vector) const {
    if(x == vector.x && y == vector.y && z == vector.z) {
        return true;
    }
    return false;
}

bool Vector::operator!=(const Vector& vector) const {
    return !(*this == vector);
}


Vector Vector::unit() const {
    if(magnitude() == 0.0f) {
        return *this;
    }
    return *this / magnitude();
}

Vector Vector::cross(const Vector& vector) const {
    return Vector { y*vector.z - z*vector.y, z*vector.x - x*vector.z, x*vector.y - y*vector.x };
}

float Vector::magnitude() const {
    return (float)sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}


float Math::angleBetween(const Vector& vector1, const Vector& vector2) {
    if(vector1.magnitude() == 0 || vector2.magnitude() == 0) {
        return 0.0f;
    }
    return acos((vector1 * vector2) / (vector1.magnitude() * vector2.magnitude()));
}


bool Math::isParallel(const Vector& vector1, const Vector& vector2) {
    return vector1.x / vector2.x == vector1.y / vector2.y && vector1.y / vector2.y == vector1.z / vector2.z;
}

bool Math::isOrthogonal(const Vector& vector1, const Vector& vector2) {
    return vector1 * vector2 == 0.0f;
}


Vector Vector::i() {
    return Vector { 1, 0, 0 };
}
Vector Vector::j() {
    return Vector { 0, 1, 0 };
}
Vector Vector::k() {
    return Vector { 0, 0, 1 };
}


Vector Math::operator*(float n, const Vector& vector) {
    return vector * n;
}


Vector Math::operator-(const Point& point1, const Point& point2) {
    return Vector { point1.x - point2.x, point1.y - point2.y, point1.z - point2.z };
}

Point Math::operator+(const Point& point, const Vector& vector) {
    return Point { point.x + vector.x, point.y + vector.y, point.z + vector.z };
}

Point Math::operator-(const Point& point, const Vector& vector) {
    return Point { point.x - vector.x, point.y - vector.y, point.z - vector.z };
}

Point& Math::operator+=(Point& point, const Vector& vector) {
    return point = point + vector;
}

Point& Math::operator-=(Point& point, const Vector& vector) {
    return point = point - vector;
}
