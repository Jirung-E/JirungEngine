#ifndef __ConsolePixel_hpp__
#define __ConsolePixel_hpp__

#include "Pixel.hpp"

#include <string>
#include <vector>


namespace Graphic {
    class ConsolePixel : public Pixel {
    private:
        char pixel;
        static std::vector<char> pixel_set;

    public:
        ConsolePixel();
        ConsolePixel(const Pixel* pixel);
        ConsolePixel(const ConsolePixel& pixel);
        
        ConsolePixel operator=(const ConsolePixel& other);

    public:
        std::string get() const;
        
        float getBrightness() const;
        void setBrightness(float level);

    private:
        unsigned short int getBrightnessMax() const;
    };
}

#endif