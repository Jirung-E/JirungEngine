#include "Pixel.hpp"

using namespace std;
using namespace JirungEngine;


Pixel::Pixel(char shape) : shape { shape } {
    
}

Pixel::~Pixel() {
    
}


char Pixel::getShape() const {
    return shape;
}