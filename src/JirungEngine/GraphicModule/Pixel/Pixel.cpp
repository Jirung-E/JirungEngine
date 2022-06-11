#include "Pixel.hpp"

using namespace std;
using namespace JirungEngine;


Pixel::Pixel(char c) : pixel { c } {

}

Pixel::Pixel(const Pixel& pixel) : Pixel { pixel.pixel } {

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