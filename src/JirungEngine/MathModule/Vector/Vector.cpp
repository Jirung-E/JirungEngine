#include "Vector.hpp"

using namespace JirungEngine;


Vector::Vector() : x { 0 }, y { 0 }, z { 0 } {

}

Vector::Vector(const Vector& vector) : x { vector.x }, y { vector.y }, z { vector.z } {

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

float Vector::operator*(const Vector& vector) const {
    return x*vector.x + y*vector.y, z*vector.z;
}

Vector Vector::operator*(float n) const {
    return Vector { x*n, y*n, z*n };
}

Vector Vector::operator/(float n) const {
    return Vector { x/n, y/n, z/n };
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

Point Vector::getPointOfContactWith(const Vector& vector) {
    return
}