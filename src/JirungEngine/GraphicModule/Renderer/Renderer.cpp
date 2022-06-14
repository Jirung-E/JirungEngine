#include "Renderer.hpp"

using namespace std;
using namespace JirungEngine;


Renderer::Camera::Camera() : direction { 0, 0, -1 }, view_distance { 128 }, field_of_view { 100.0f } {
    moveTo(Point { 0, 0, 64 });
}


Vector Renderer::Camera::getLeftLimit() const {
    Vector ll { Line::rotate(Point { direction.x, direction.y, direction.z }, Line { Point { getPosition(), Vector { } }, field_of_view/2.0f }) };
    return Vector { };
}

Vector Renderer::Camera::getRightLimit() const {

}

Vector Renderer::Camera::getTopLimit() const {

}

Vector Renderer::Camera::getBottomLimit() const {

}


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
    if(Point::getDistanceBetween(camera.position, point) > camera.view_distance) {
        return;
    }
    unsigned short int level_max = Pixel::getBrightnessMax();
    for(int i=level_max; i>=1; --i) {
        if(Point::getDistanceBetween(camera.position, point) <= camera.view_distance / i) {
            image->setPixelBrightness(i, point);
        }
    }
}

void Renderer::renderSegment(const Segment& segment) {
    Point start_point { segment.getStartPoint() };
    Point end_point { segment.getEndPoint() };
    Vector direction { segment.vector };
}