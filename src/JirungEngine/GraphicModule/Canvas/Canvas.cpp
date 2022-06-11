#include "Canvas.hpp"

using namespace std;
using namespace JirungEngine;


Canvas::Canvas(unsigned short int width, unsigned short int height) : width { width }, height { height }, 
pixels { new Pixel*[height] }, backlight_brightness { 0 } {
    for(int i=0; i<height; ++i) {
        pixels[i] = new Pixel[width];
    }
    clear();
}

Canvas::Canvas() : Canvas { 80, 40 } {

}

Canvas::Canvas(const Canvas& canvas) : Canvas { canvas.width, canvas.height } {
    backlight_brightness = canvas.backlight_brightness;
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
    
    backlight_brightness = other.backlight_brightness;
    
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
            pixels[i][k].setBrightness(backlight_brightness);
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