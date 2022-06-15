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

    renderSegment(Segment { polygon.p1, Vector { polygon.p2 - polygon.p1 } });
    // to
    renderSegment(Segment { polygon.p1, Vector { polygon.p3 - polygon.p1 } });

    return *image;
}

Display Renderer::renderClear(const Polygon& polygon) {
    image->clear();

    renderSegment(Segment { polygon.p1, Vector { polygon.p2 - polygon.p1 } });
    renderSegment(Segment { polygon.p2, Vector { polygon.p3 - polygon.p2 } });
    renderSegment(Segment { polygon.p3, Vector { polygon.p1 - polygon.p3 } });

    return *image;
}


void Renderer::clearImage() {
    image->clear();
}


Point Renderer::renderPoint(const Point& point) {
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
    // to_apparent_point -> 이놈을 camera.vector.x, camera.vector.y와 평행한 성분으로 나눌수 있으면....
    float theta_y = Vector::getAngleBetween(camera.getYAxis().vector, to_apparent_point);
    float theta_x = Vector::getAngleBetween(camera.getXAxis().vector, to_apparent_point);
    Vector to_apparent_point_proj_to_xz { to_apparent_point - camera.getYAxis().vector*(to_apparent_point*cos(theta_y)) };
    Vector to_apparent_point_proj_to_yz { to_apparent_point - camera.getXAxis().vector*(to_apparent_point*cos(theta_x)) };
    float x = image.getWidth()/2.0f + camera.getXAxis().vector * to_apparent_point_proj_to_xz;
    float y = image.getHeight()/2.0f + camera.getYAxis().vector * to_apparent_point_proj_to_yz;

    image->setPixelBrightness(image->getPixelBrightness(Point { x, y })+1, Point { x, y });
    return Point { x, y };
}

void Renderer::renderSegment(const Segment& segment) {
    Point start_point { renderPoint(segment.getStartPoint()) };
    Point end_point { renderPoint(segment.getEndPoint()) };
    Vector direction { end_point - start_point };

    for(int i=1; i<direction.magnitude(); ++i) {
        renderPoint(start_point + Point(direction.x, direction.y, direction.z)/i);
    }
}

bool Renderer::isOutOfAngle(const Point& point) const {
    Vector to_point { point - camera.getPosition() };
    Vector to_left_top { (camera.getLeftLimit() + camera.getTopLimit()) + camera.direction().getUnitVector() * -(camera.getLeftLimit()*camera.direction()) };
    if(Vector::getAngleBetween(to_point, camera.direction()) > Vector::getAngleBetween(to_left_top, camera.direction())) {
        return true;
    }
    return false;
}