#include "Renderer.hpp"

using namespace std;
using namespace JirungEngine;


Renderer::Camera::Camera() : position { 0, 0, 64 }, direction { 0, 0, -1 }, view_distance { 128 } {

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
    // ###+++++++++........................... -> x^2 느낌으로.. 이런식으로, 멀어질수록 표현되는 밝기는 줄어드는데, 가까울떄 더 빠르게 바뀌는 느낌? 이걸 픽셀에 의존하기 않고 구현...
    unsigned short int level_max = Pixel::getBrightnessMax();
    for(int i=level_max; i>=1; --i) {
        if(Point::getDistanceBetween(camera.position, point) <= camera.view_distance / i) {
            //draw
        }
    }
}

void Renderer::renderSegment(const Segment& segment) {
    Point start_point { segment.getStartPoint() };
    Point end_point { segment.getEndPoint() };
    Vector direction { segment.vector };
}