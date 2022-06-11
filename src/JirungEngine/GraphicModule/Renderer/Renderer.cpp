#include "Renderer.hpp"

using namespace std;
using namespace JirungEngine;


Renderer::Camera::Camera() : position { 0, 0, 64 }, direction { 0, 0, -1 } {

}

Renderer::Renderer(unsigned short int width, unsigned short int height) : camera { }, image { width, height } {
    
}

Renderer::Renderer() : Renderer { 160, 45 } {

}


void Renderer::renderGeneral(const Polygon& polygon) {
    
}

void Renderer::renderClear(const Polygon& polygon) {

}


void Renderer::clearImage() {
    image.clear();
}