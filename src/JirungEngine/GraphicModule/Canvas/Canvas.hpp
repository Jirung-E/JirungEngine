#ifndef __Canvas_hpp__
#define __Canvas_hpp__

#include "../Pixel/Pixel.hpp"


namespace JirungEngine {
    class Canvas {
    public:
        Pixel** pixels;

        unsigned short int width;
        unsigned short int height;

        char default_background;
    
    public:
        Canvas(unsigned short int width, unsigned short int height);
        Canvas();
        ~Canvas();

    public:
        void clear();
    };
}

#endif