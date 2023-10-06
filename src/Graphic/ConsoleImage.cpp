#include "ConsoleImage.hpp"

#include "ConsolePixel.hpp"

using namespace std;
using namespace Graphic;


ConsoleImage::ConsoleImage(unsigned short int width, unsigned short int height) : Image { width, height } {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k] = new ConsolePixel { };
        }
    }
    clear();
}

ConsoleImage::ConsoleImage() : ConsoleImage { 80, 40 } {

}

ConsoleImage::ConsoleImage(const ConsoleImage& image) : ConsoleImage { image.width, image.height } {
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            pixels[i][k]->setBrightness(image.pixels[i][k]->getBrightness());
        }
    }
}

ConsoleImage::ConsoleImage(const Image* image) : ConsoleImage { image->getWidth(), image->getHeight() } {
    for(int i=0; i<image->getHeight(); ++i) {
        for(int k=0; k<image->getWidth(); ++k) {
            setPixelBrightness(image->getPixelBrightness(k, i), k, i);
        }
    }
}

ConsoleImage::~ConsoleImage() {
    terminate();
}


std::string ConsoleImage::getByString() const {
    string result = "";
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            ConsolePixel* cp = new ConsolePixel { pixels[i][k] };
            result += cp->get();
        }
        result += "\n";
    }
    return result;
}