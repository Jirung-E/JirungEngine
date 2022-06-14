#include "Renderer.hpp"

#include <cmath>

using namespace std;
using namespace JirungEngine;


// <Camera> ---------------------------------------------------------------------------------------------------------------------------
Renderer::Camera::Camera() : view_distance { 128 }, field_of_view { 100.0f } {
    moveTo(Point { 0, 0, 64 });
}


Vector Renderer::Camera::direction() const {
    return getZAxis().vector * -1;
}

Vector Renderer::Camera::getLeftLimit() const {
    return Vector { Line::rotate(Point { direction().x, direction().y, direction().z }, getYAxis(), field_of_view/2.0f) };
}

Vector Renderer::Camera::getRightLimit() const {
    return Vector { Line::rotate(Point { direction().x, direction().y, direction().z }, getYAxis(), -field_of_view/2.0f) };
}

Vector Renderer::Camera::getTopLimit() const {
    return Vector { Line::rotate(Point { direction().x, direction().y, direction().z }, getXAxis(), field_of_view/2.0f) };
}

Vector Renderer::Camera::getBottomLimit() const {
    return Vector { Line::rotate(Point { direction().x, direction().y, direction().z }, getYAxis(), -field_of_view/2.0f) };
}
// </Camera> --------------------------------------------------------------------------------------------------------------------------


Renderer::Renderer(unsigned short int width, unsigned short int height) : camera { }, image { new Display { width, height } } {
    
}

Renderer::Renderer() : Renderer { 160, 45 } {

}


Display Renderer::renderGeneral(const Polygon& polygon) {
    image->clear();



    return *image;
}

Display Renderer::renderClear(const Polygon& polygon) {
    image->clear();



    return *image;
}


void Renderer::clearImage() {
    image->clear();
}


void Renderer::renderPoint(const Point& point) {
    if(isOutOfAngle(point)) {
        return;
    }

    float m = image->getWidth() > image->getHeight() ? image->getWidth() : image->getHeight();
    float t = (m/2) / tan(camera.field_of_view/2);

    float theta = Vector::getAngleBetween(camera.direction(), point - camera.getPosition());
    float distance_to_apparent_point = t / cos(theta);
    Vector to_apparent_point { Vector(point - camera.getPosition()).getUnitVector() * distance_to_apparent_point };
    Point apparent_point { camera.getPosition() + Point { to_apparent_point.x, to_apparent_point.y, to_apparent_point.z } };
    // 이건 전체적인 공간에서의 겉보기 위치고 카메라가 볼때의 왼쪽 위에서부터의 좌표는 따로 또 구해야함...
    image->setPixelBrightness(image->getPixelBrightness()+1, Point { });
}

bool Renderer::isOutOfAngle(const Point& point) const {
    Vector to_point { point - camera.getPosition() };
    Vector to_left_top { (camera.getLeftLimit() + camera.getTopLimit()) + camera.direction().getUnitVector() * -(camera.getLeftLimit()*camera.direction()) };
    if(Vector::getAngleBetween(to_point, camera.direction()) > Vector::getAngleBetween(to_left_top, camera.direction())) {
        return true;
    }
    return false;
}

void Renderer::renderSegment(const Segment& segment) {
    Point start_point { segment.getStartPoint() };
    Point end_point { segment.getEndPoint() };
    Vector direction { segment.vector };
}