#include "Pixel.hpp"

using namespace std;
using namespace JirungEngine;


Pixel::Pixel(char c) : pixel { c } {

}

Pixel::Pixel(const Pixel& pixel) : Pixel { pixel.pixel } {

}


Pixel Pixel::operator=(const Pixel& other) {
    pixel = other.pixel;
    return *this;
}


string Pixel::get() const {
    string result = "";
    result += pixel;
    result += safe_null;
    return result;
}

void Pixel::set(char c) {
    pixel = c;
}