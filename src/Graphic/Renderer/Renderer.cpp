#include "Renderer.hpp"

#ifdef _WIN32
#define _USE_MATH_DEFINES
#endif
#include <math.h>
#include <vector>

using namespace std;
using namespace Math;
using namespace Graphic;


// <Camera> ---------------------------------------------------------------------------------------------------------------------------
Renderer::Camera::Camera() : view_distance { 128 }, field_of_view { static_cast<float>(M_PI/1.8) } {
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
    // 점이 화면 밖에 있는 경우 적절한 처리를 해줘야함
    Vector normal { polygon.getNormal() };
    Vector at { polygon.getCenterOfGravity() - camera.getPosition() };
    if(normal * at > 0) {   // 면의 뒷면은 그리지 않음
        return *image;
    }

    float brightness = 100 * (-normal * at.getUnitVector());

    Point p1 { transformToPointOfDisplay(polygon.p1) };
    Point p2 { transformToPointOfDisplay(polygon.p2) };
    Point p3 { transformToPointOfDisplay(polygon.p3) };

    vector<Point> fragment;

    Vector direction { p3 - p2 };
    float distance = direction.magnitude();

    for(float i=0; i<=distance; i++) {          // -> 0.1로 하면 버버벅  
        Vector d { direction.getUnitVector() * i };
        Point p { p2 + d };
        p.x = roundf(p.x);
        p.y = roundf(p.y);

        Vector v { p - p1 };
        float dist = v.magnitude();

        for(float k=0; k<=dist; k++) {
            d = v.getUnitVector() * k;
            p = p1 + d;
            p.x = roundf(p.x);
            p.y = roundf(p.y);
            if(p.x < 0.0f || p.y < 0.0f || p.x >= image->getWidth() || p.y >= image->getHeight()) {
                continue;
            }
            if(find(fragment.begin(), fragment.end(), p) != fragment.end()) {
                continue;
            }
            fragment.push_back(p);
        }
    }

    for(const auto& e : fragment) {
        image->setPixelBrightness(image->getPixelBrightness(e.x, e.y) + brightness, e.x, e.y);
    }

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

void Renderer::showPointOnImage(const Point& point, float brightness) {
    if(point.x < 0.0f || point.y < 0.0f || point.x >= image->getWidth() || point.y >= image->getHeight()) {
        return;
    }

    unsigned short int x = static_cast<unsigned short int>(round(point.x));
    unsigned short int y = static_cast<unsigned short int>(round(point.y));
    image->setPixelBrightness(brightness, x, y);
}

void Renderer::renderPoint(const Point& point, float brightness) {
    Point p { transformToPointOfDisplay(point) };
    if(p.x < 0.0f || p.y < 0.0f || p.x >= image->getWidth() || p.y >= image->getHeight()) {
        return;
    }

    showPointOnImage(p, brightness);
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
        Vector d { direction.getUnitVector() * (float)i };
        Point p { transformToPointOfDisplay(start_point) + Point { d.x, d.y, d.z } };
        if(p.x < 0.0f || p.y < 0.0f || p.x >= image->getWidth() || p.y >= image->getHeight()) {
            return;
        }

        showPointOnImage(p, 100.0f);
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