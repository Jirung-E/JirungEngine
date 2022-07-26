#ifndef __Display_hpp__
#define __Display_hpp__

#include "../Pixel/Pixel.hpp"
#include "../Image/Image.hpp"


namespace Graphic {
    class Display {
    private:
        Pixel** pixels;

        unsigned short int width;
        unsigned short int height;

        unsigned short int backlight_brightness;
    
    public:
        Display(unsigned short int width, unsigned short int height);
        Display();
        Display(const Display& display);
        ~Display();
        
        Display operator=(const Display& other);

    public:
        void showImage(const Image* image);
        
        void clear();
        std::string getByString() const;
        unsigned short int getWidth() const;
        unsigned short int getHeight() const;

    private:
        unsigned short int getPixelBrightness(unsigned short int x, unsigned short int y) const;
        void setPixelBrightness(unsigned short int level, unsigned short int x, unsigned short int y);
        
    private:
        void terminate();
    };
}

#endif