#ifndef __Display_hpp__
#define __Display_hpp__

#include "../Pixel/Pixel.hpp"


namespace JirungEngine {
    class Display {
    public:
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
        void clear();
        std::string getByString() const;
        
    private:
        void terminate();
    };
}

#endif