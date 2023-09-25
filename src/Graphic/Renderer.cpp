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
    //moveTo(Point { 0, 0, 64 });
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
    Vector normal { polygon.getNormal() };
    Vector at { polygon.getCenterOfGravity() - camera.getPosition() };
    if(normal * at > 0) {   // 면의 뒷면은 그리지 않음
        normal = -normal;
        //return *image;
    }

    float brightness = 100 * (-normal * at.unit());
    float full_area = normal.magnitude() / 2.0f;

    Plane poly_plane { polygon.p1, normal };

    for(int i=0; i<image->getHeight(); ++i) {
        for(int k=0; k<image->getWidth(); ++k) {
            at = { camera.direction() * max(image->getWidth(), image->getHeight())/2.0f / tanf(camera.field_of_view/2) };
            at += camera.getXAxis().vector * (k - image->getWidth()/2.0f);
            at += camera.getYAxis().vector * (i - image->getHeight()/2.0f);
            if(poly_plane.isParallelTo(Line { camera.getPosition(), at })) {
                continue;
            }
            Point ray_point = poly_plane.getPointOfContactWith(Line { camera.getPosition(), at });

            Vector v1 { polygon.p1 - ray_point };
            Vector v2 { polygon.p2 - ray_point };
            Vector v3 { polygon.p3 - ray_point };
            float area1 = v1.crossProduct(v2).magnitude() / 2.0f;
            float area2 = v2.crossProduct(v3).magnitude() / 2.0f;
            float area3 = v3.crossProduct(v1).magnitude() / 2.0f;

            if(area1 + area2 + area3 < full_area + 0.1f) {  // 0.1f는 오차범위
                renderPoint(ray_point, brightness);
            }
        }
    }

    return *image;
}

Image Graphic::Renderer::renderGeneral(const Math::Model& model) {
    for(auto& e : model.polygons) {
        renderGeneral(e);
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
    float t = (m/2) / tanf(camera.field_of_view/2);

    float theta = Vector::getAngleBetween(camera.direction(), point - camera.getPosition());
    float distance_to_apparent_point = t / cosf(theta);
    Vector to_apparent_point { Vector(point - camera.getPosition()).unit() * distance_to_apparent_point };
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
        Vector d { direction.unit() * (float)i };
        Point p { transformToPointOfDisplay(start_point) + Point { d.x, d.y, d.z } };
        if(p.x < 0.0f || p.y < 0.0f || p.x >= image->getWidth() || p.y >= image->getHeight()) {
            return;
        }

        showPointOnImage(p, 100.0f);
    }
}

bool Renderer::isOutOfAngle(const Point& point) const {
    Vector to_point { point - camera.getPosition() };
    Vector to_left_top { (camera.getLeftLimit() + camera.getTopLimit()) + camera.direction().unit() * -(camera.getLeftLimit()*camera.direction()) };
    if(Vector::getAngleBetween(to_point, camera.direction()) > Vector::getAngleBetween(to_left_top, camera.direction())) {
        return true;
    }
    return false;
}