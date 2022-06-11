#ifndef __Canvas_hpp__
#define __Canvas_hpp__

#include "../Pixel/Pixel.hpp"


namespace JirungEngine {
    class Canvas {
    public:
        Pixel** pixels;

        unsigned short int width;
        unsigned short int height;

        unsigned short int backlight_brightness;
    
    public:
        Canvas(unsigned short int width, unsigned short int height);
        Canvas();
        Canvas(const Canvas& canvas);
        ~Canvas();
        
        Canvas operator=(const Canvas& other);

    public:
        void clear();
        std::string getByString() const;
        
    private:
        void terminate();
    };
}

#endif