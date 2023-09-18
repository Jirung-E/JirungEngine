#include "Vector.hpp"

#include <cmath>

using namespace Math;


Vector::Vector() : x { 0 }, y { 0 }, z { 0 } {

}

Vector::Vector(const Vector& vector) : x { vector.x }, y { vector.y }, z { vector.z } {

}

Vector::Vector(const Point& point) : x { point.x }, y { point.y }, z { point.z } {

}

Vector::Vector(float x, float y, float z) : x { x }, y { y }, z { z } {

}


Vector Vector::operator=(const Vector& vector) {
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return *this;
}

Vector Vector::operator+(const Vector& vector) const {
    return Vector { x + vector.x, y + vector.y, z + vector.z };
}

Vector Vector::operator-(const Vector& vector) const {
    return Vector { x - vector.x, y - vector.y, z - vector.z };
}

float Vector::scalarProduct(const Vector& vector) const {
    return x*vector.x + y*vector.y + z*vector.z;
}

float Vector::scalarProduct(const Vector& vector1, const Vector& vector2) {
    return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z;
}

Vector Vector::crossProduct(const Vector& vector) const {
    return Vector { y*vector.z - z*vector.y, z*vector.x - x*vector.z, x*vector.y - y*vector.x };
}

Vector Vector::crossProduct(const Vector& vector1, const Vector& vector2) {
    return Vector { vector1.y*vector2.z - vector1.z*vector2.y, vector1.z*vector2.x - vector1.x*vector2.z, vector1.x*vector2.y - vector1.y*vector2.x };
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

bool Vector::operator==(const Vector& vector) const {
    if(x == vector.x && y == vector.y && z == vector.z) {
        return true;
    }
    return false;
}

bool Vector::operator!=(const Vector& vector) const {
    return !(*this == vector);
}

Vector Vector::operator+=(const Vector& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    return *this;
}

Vector Vector::operator-=(const Vector& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    return *this;
}

Vector Vector::operator*=(float n) {
    x *= n;
    y *= n;
    z *= n;
    return *this;
}

Vector Vector::operator/=(float n) {
    x /= n;
    y /= n;
    z /= n;
    return *this;
}


float Vector::magnitude() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::unit() const {
    if(magnitude() == 0.0f) {
        return *this;
    }
    return *this / magnitude();
}

Vector Vector::unitVectorOf(const Vector& vector) {
    return vector.unit();
}

float Vector::getAngleWith(const Vector& other) const {
    if(this->magnitude() == 0 || other.magnitude() == 0) {
        return 0.0f;
    }
    return acos(((*this) * other) / (this->magnitude() * other.magnitude()));
}

float Vector::getAngleBetween(const Vector& vector1, const Vector& vector2) {
    return vector1.getAngleWith(vector2);
}


bool Vector::isParallelTo(const Vector& other) const {
    if(this->unit() == other.unit()) {
        return true;
    }
    if(this->unit() == other.unit() * -1) {
        return true;
    }
    return false;
}

bool Vector::isParallel(const Vector& vector1, const Vector& vector2) {
    return vector1.isParallelTo(vector2);
}

bool Vector::isOrthogonal(const Vector& vector1, const Vector& vector2) {
    if(vector1 * vector2 == 0.0f) {
        return true;
    }
    return false;
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

Vector Math::operator-(const Vector& vector) {
    return vector * -1;
}