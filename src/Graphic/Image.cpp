#include "Image.hpp"

using namespace std;
using namespace Graphic;


Image::Image(unsigned short int width, unsigned short int height) : width { width }, height { height }, 
pixels { new Pixel**[height] } {
    for(int i=0; i<height; ++i) {
        pixels[i] = new Pixel*[width];
    }
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


void Image::clear() {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k]->setBrightness(0);
        }
    }
}


unsigned short int Image::getWidth() const {
    return width;
}

unsigned short int Image::getHeight() const {
    return height;
}

float Image::getPixelBrightness(unsigned short int x, unsigned short int y) const {
    if(x >= width || y >= height) {
        return 0.0f;
    }

    return pixels[height-1 - y][x]->getBrightness();
}

void Image::setPixelBrightness(float level, unsigned short int x, unsigned short int y) {
    if(x >= width || y >= height) {
        return;
    }

    pixels[height-1 - y][x]->setBrightness(level);
}

unsigned short int Graphic::Image::getBrightnessMax() const {
    return pixels[0][0]->getBrightnessMax();
}


void Image::terminate() {
    for(int i=0; i<height; ++i) {
        delete[] pixels[i];
    }
    delete[] pixels;
}