#include "ConsolePixel.hpp"

#include <cmath>

using namespace std;
using namespace Graphic;


vector<char> ConsolePixel::pixel_set { ' ', '.', ':', '|', '$', '#', '&', '%', '@' };

ConsolePixel::ConsolePixel() : pixel { ' ' } {

}

ConsolePixel::ConsolePixel(const Pixel* pixel) : ConsolePixel { } {
    this->setBrightness(pixel->getBrightness());
}

ConsolePixel::ConsolePixel(const ConsolePixel& pixel) : ConsolePixel { } {
    this->setBrightness(pixel.getBrightness());
}


ConsolePixel ConsolePixel::operator=(const ConsolePixel& other) {
    this->setBrightness(other.getBrightness());
    return *this;
}


string ConsolePixel::get() const {
    string result = "";
    result += pixel;
    return result;
}

float ConsolePixel::getBrightness() const {
    for(int i=0; i<pixel_set.size(); ++i) {
        if(pixel == pixel_set[i]) {
            return (float(i) / getBrightnessMax()) * 100.0f;
        }
    }
    return 0.0f;
}

void ConsolePixel::setBrightness(float level) {
    if(level > 100.0f) {
        level = 100.0f;
    }
    else if(level < 0.0f) {
        level = 0.0f;
    }
    
    unsigned short int brightness = static_cast<unsigned short int>(round((level / 100.0f) * getBrightnessMax()));
    
    pixel = pixel_set[brightness];
}

unsigned short int ConsolePixel::getBrightnessMax() const {
    return pixel_set.size() - 1;
}