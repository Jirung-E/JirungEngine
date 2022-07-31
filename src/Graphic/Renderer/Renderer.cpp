#include "Renderer.hpp"

#include <cmath>

using namespace std;
using namespace Math;
using namespace Graphic;


// <Camera> ---------------------------------------------------------------------------------------------------------------------------
Renderer::Camera::Camera() : view_distance { 128 }, field_of_view { M_PI/1.8f } {
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


Renderer::Renderer(unsigned short int width, unsigned short int height) : camera { }, image { new Image { width, height } } {
    
}

Renderer::Renderer() : Renderer { 160, 45 } {

}


Image Renderer::renderGeneral(const Polygon& polygon) {
    renderSegment(Segment { polygon.p1, Vector { polygon.p2 - polygon.p1 } });
    // to
    renderSegment(Segment { polygon.p1, Vector { polygon.p3 - polygon.p1 } });

    return *image;
}

Image Renderer::renderClear(const Polygon& polygon) {
    renderSegment(Segment { polygon.p1, Vector { polygon.p2 - polygon.p1 } });
    renderSegment(Segment { polygon.p2, Vector { polygon.p3 - polygon.p2 } });
    renderSegment(Segment { polygon.p3, Vector { polygon.p1 - polygon.p3 } });

    return *image;
}


void Renderer::clearImage() {
    image->clear();
}


Point Renderer::getApparentPoint(const Point& point) const {
    float m = image->getWidth() > image->getHeight() ? image->getWidth() : image->getHeight();
    float t = (m/2) / tan(camera.field_of_view/2);

    float theta = Vector::getAngleBetween(camera.direction(), point - camera.getPosition());
    float distance_to_apparent_point = t / cos(theta);
    Vector to_apparent_point { Vector(point - camera.getPosition()).getUnitVector() * distance_to_apparent_point };
    return Point { camera.getPosition() + Point { to_apparent_point.x, to_apparent_point.y, to_apparent_point.z } };
}

Point Renderer::transformToPointOfDisplay(const Point& point) const {
    if(isOutOfAngle(point)) {
        return { -1, -1, -1 };
    }

    Vector to_apparent_point { getApparentPoint(point) - camera.getPosition() };
    
    Vector to_apparent_point_proj_to_xz { to_apparent_point - camera.getYAxis().vector*(to_apparent_point*camera.getYAxis().vector) };
    Vector to_apparent_point_proj_to_yz { to_apparent_point - camera.getXAxis().vector*(to_apparent_point*camera.getXAxis().vector) };
    float image_x = image->getWidth()/2.0f + camera.getXAxis().vector * to_apparent_point_proj_to_xz;
    float image_y = image->getHeight()/2.0f + camera.getYAxis().vector * to_apparent_point_proj_to_yz;

    return Point { image_x, image_y };
}

void Renderer::showPointOnImage(const Point& point) {
    if(point.x < 0.0f || point.y < 0.0f || point.x >= image->getWidth() || point.y >= image->getHeight()) {
        return;
    }

    unsigned short int x = static_cast<unsigned short int>(round(point.x));
    unsigned short int y = static_cast<unsigned short int>(round(point.y));
    image->setPixelBrightness(100, x, y);
}

void Renderer::renderPoint(const Point& point) {
    Point p { transformToPointOfDisplay(point) };
    if(p.x < 0.0f || p.y < 0.0f || p.x >= image->getWidth() || p.y >= image->getHeight()) {
        return;
    }

    showPointOnImage(p);
}

void Renderer::renderSegment(const Segment& segment) {
    Point start_point { segment.getStartPoint() };
    Point end_point { segment.getEndPoint() };
    if(isOutOfAngle(start_point) || isOutOfAngle(end_point)) {
        return;
    }
    Vector direction { transformToPointOfDisplay(end_point) - transformToPointOfDisplay(start_point) };
    float distance = Point::getDistanceBetween(transformToPointOfDisplay(start_point), transformToPointOfDisplay(end_point));
    
    for(int i=0; i<distance; ++i) {
        Vector d { direction.getUnitVector() * i };
        Point p { transformToPointOfDisplay(start_point) + Point { d.x, d.y, d.z } };
        if(p.x < 0.0f || p.y < 0.0f || p.x >= image->getWidth() || p.y >= image->getHeight()) {
            return;
        }

        showPointOnImage(p);
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