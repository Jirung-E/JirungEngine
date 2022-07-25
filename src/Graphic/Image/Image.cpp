#include "Image.hpp"

using namespace Graphic;


Image::Image(unsigned short int width, unsigned short int height) : width { width }, height { height }, 
pixels { new Pixel*[height] } {
    for(int i=0; i<height; ++i) {
        pixels[i] = new Pixel[width];
    }
    clear();
}

Image::Image() : Image { 80, 40 } {

}

Image::Image(const Image& image) : Image { image.width, image.height } {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k] = image.pixels[i][k];
        }
    }
}

Image::~Image() {
    terminate();
}


Image Image::operator=(const Image& other) {
    terminate();
    
    width = other.width;
    height = other.height;
    
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


void Image::clear() {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k].setBrightness(0);
        }
    }
}


void Image::terminate() {
    for(int i=0; i<height; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}