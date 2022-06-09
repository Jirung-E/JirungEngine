#ifndef __Pixel_hpp__
#define __Pixel_hpp__

#include <string>


namespace JirungEngine {
    class Pixel {
    public:
        char shape;
        std::string color;

    public:
        Pixel(char shape = ' ', std::string color = "WHITE");
    };
}

#endif