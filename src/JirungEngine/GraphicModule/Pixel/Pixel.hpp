#ifndef __Pixel_hpp__
#define __Pixel_hpp__

#include <string>


namespace JirungEngine {
    class Pixel {
        private: char shape;
        private: std::string color;

    public:
        Pixel(char shape = ' ');
        ~Pixel();
    };
}

#endif