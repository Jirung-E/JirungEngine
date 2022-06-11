#include "Canvas.hpp"

using namespace std;
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

Canvas::Canvas(const Canvas& canvas) : Canvas { canvas.width, canvas.height } {
    default_background = canvas.default_background;
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k] = canvas.pixels[i][k];
        }
    }
}

Canvas::~Canvas() {
    terminate();
}


Canvas Canvas::operator=(const Canvas& other) {
    terminate();
    
    width = other.width;
    height = other.height;
    
    default_background = other.default_background;
    
    pixels = new Pixel*[height];
    for(int i=0; i<height; ++i) {
        pixels[i] = new Pixel[width];
    }
    
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k] = other.pixels[i][k];
        }
    }
    
    return *this;
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
        result += "\n";
    }
    return result;
}


void Canvas::terminate() {
    for(int i=0; i<height; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}