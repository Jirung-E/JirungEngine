#include "Display.hpp"

using namespace std;
using namespace JirungEngine;


Display::Display(unsigned short int width, unsigned short int height) : width { width }, height { height }, 
pixels { new Pixel*[height] }, backlight_brightness { 0 } {
    for(int i=0; i<height; ++i) {
        pixels[i] = new Pixel[width];
    }
    clear();
}

Display::Display() : Display { 80, 40 } {

}

Display::Display(const Display& display) : Display { display.width, display.height } {
    backlight_brightness = display.backlight_brightness;
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k] = display.pixels[i][k];
        }
    }
}

Display::~Display() {
    terminate();
}


Display Display::operator=(const Display& other) {
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


void Display::clear() {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k].setBrightness(backlight_brightness);
        }
    }
}

std::string Display::getByString() const {
    string result = "";
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            result += pixels[i][k].get();
        }
        result += "\n";
    }
    return result;
}


void Display::terminate() {
    for(int i=0; i<height; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}