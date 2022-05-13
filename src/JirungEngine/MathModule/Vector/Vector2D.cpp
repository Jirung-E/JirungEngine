#include "Vector2D.hpp"

using namespace JirungEngine;


Vector2D::Vector2D() : x { 0 }, y { 0 } {

}

Vector2D::Vector2D(const Vector2D& vector2d) : x { vector2d.x }, y { vector2d.y } {

}

Vector2D::Vector2D(float x, float y) : x { x }, y { y } {

}


Vector2D Vector2D::operator=(const Vector2D& vector2d) {
    x = vector2d.x;
    y = vector2d.y;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& vector2d) {
    return Vector2D { x + vector2d.x, y + vector2d.y };
}

Vector2D Vector2D::operator-(const Vector2D& vector2d) {
    return Vector2D { x - vector2d.x, y - vector2d.y };
}

float Vector2D::operator*(const Vector2D& vector2d) {
    return x*vector2d.x + y*vector2d.y;
}

Vector2D Vector2D::operator*(float n) {
    return Vector2D { x*n, y*n };
}

Vector2D Vector2D::operator/(float n) {
    return Vector2D { x/n, y/n };
}