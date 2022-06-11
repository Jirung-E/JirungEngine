#include "Canvas.hpp"

using namespace JirungEngine;


Canvas::Canvas(unsigned short int width, unsigned short int height) : width { width }, height { height }, 
pixels { new Pixel*[height] }, default_background { ' ' } {
    for(int i=0; i<height; ++i) {
        pixels[i] = new Pixel[width] { default_background };
    }
    clear();
}

Canvas::Canvas() : Canvas { 80, 40 } {

}

Canvas::Canvas(const Canvas& canvas) : Canvas { canvas.width, canvas.height }, default_background { canvas.default_background } {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k].set(canvas.pixels[i][k]);
        }
    }
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

std::string Canvas::getByString() const {
    string result = "";
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            result += pixels[i][k].get();
        }
    }
    return result;
}