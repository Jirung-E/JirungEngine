#include "Pixel.hpp"

using namespace std;
using namespace JirungEngine;


vector<char> Pixel::pixel_set { ' ', '.', '+', '#' };

Pixel::Pixel(char c) : pixel { c }, brightness { 0 } {

}

Pixel::Pixel(const Pixel& pixel) : Pixel { pixel.pixel } {
    brightness = pixel.brightness;
}


Pixel Pixel::operator=(const Pixel& other) {
    pixel = other.pixel;
    brightness = other.brightness;
    return *this;
}


string Pixel::get() const {
    string result = "";
    result += pixel;
    return result;
}

unsigned short int Pixel::getBrightness() const {
    return brightness;
}

void Pixel::setBrightness(unsigned short int level) {
    if(level > getBrightnessMax()) {
        level = getBrightnessMax();
    }
    brightness = level;
    pixel = pixel_set[brightness];
}

unsigned short int Pixel::getBrightnessMax() {
    return pixel_set.size() - 1;
}