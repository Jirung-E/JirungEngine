#include "Canvas.hpp"

using namespace JirungEngine;


Canvas::Canvas(unsigned short int width, unsigned short int height) : width { width }, height { height }, 
pixels { new Pixel*[height] }, default_background { ' ' } {
    for(int i=0; i<height; ++i) {
        pixels[i] = new Pixel[width];
    }
    clear();
}

Canvas::Canvas() : Canvas { 80, 40 } {

}

Canvas::~Canvas() {
    for(int i=0; i<height; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}


void Canvas::clear() {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k].set(default_background);
        }
    }
}