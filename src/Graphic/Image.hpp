#ifndef __Image_hpp__
#define __Image_hpp__

#include "Pixel.hpp"


namespace Graphic {
    class Image {
    protected:
        Pixel*** pixels;
        
        unsigned short int width;
        unsigned short int height;
        
    public:
        Image(unsigned short int width, unsigned short int height);
        Image(const Image& image);
        ~Image();

    public:
        void clear();
        unsigned short int getWidth() const;
        unsigned short int getHeight() const;

        float getPixelBrightness(unsigned short int x, unsigned short int y) const;
        void setPixelBrightness(float level, unsigned short int x, unsigned short int y);
        unsigned short int getBrightnessMax() const;
        
    protected:
        void terminate();
    };
}

#endif