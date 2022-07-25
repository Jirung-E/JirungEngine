#ifndef __Image_hpp__
#define __Image_hpp__

#include "../Pixel/Pixel.hpp"


namespace Graphic {
    class Image {
    private:
        Pixel** pixels;
        
        unsigned short int width;
        unsigned short int height;
        
    public:
        Image(unsigned short int width, unsigned short int height);
        Image();
        Image(const Image& image);
        ~Image();
        
        Image operator=(const Image& other);

    public:
        void clear();
        
    private:
        void terminate();
    };
}

#endif