#include "Pixel.hpp"

using namespace std;
using namespace JirungEngine;


const Pixel::vector<char> pixel_set { ' ', '.', '+', '#' };

Pixel::Pixel(char c) : pixel { c }, brightness { 0 } {

}

Pixel::Pixel(const Pixel& pixel) : Pixel { pixel.pixel } {
    bightness = pixel.brightness;
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

void Pixel::setBrightness(unsigned short int brightness) {
    unsigned short int brightness_max = pixel_set.length() - 1;
    brightness = brightness_max;
    pixel = pixel_set[brightness];
}