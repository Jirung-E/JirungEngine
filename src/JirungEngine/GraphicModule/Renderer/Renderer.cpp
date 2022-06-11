#include "Renderer.hpp"

using namespace std;
using namespace JirungEngine;


Renderer::Camera::Camera() : position { 0, 0, 64 }, direction { 0, 0, -1 } {

}

Renderer::Renderer(unsigned short int width, unsigned short int height) : camera { }, image { width, height } {
    
}

Renderer::Renderer() : Renderer { 160, 45 } {

}


Canvas Renderer::renderGeneral(const Polygon& polygon) {
    image.clear();

    return image;
}

Canvas Renderer::renderClear(const Polygon& polygon) {
    image.clear();

    return image;
}


void Renderer::clearImage() {
    image.clear();
}