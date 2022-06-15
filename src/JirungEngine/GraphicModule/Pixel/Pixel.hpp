#ifndef __Pixel_hpp__
#define __Pixel_hpp__

#include <string>
#include <vector>


namespace JirungEngine {
    class Pixel {
    private:
        char pixel;
        unsigned short int brightness;

        static std::vector<char> pixel_set;

    public:
        Pixel(char c = ' ');
        Pixel(const Pixel& pixel);
        
        Pixel operator=(const Pixel& other);

    public:
        std::string get() const;
        unsigned short int getBrightness() const;
        void setBrightness(unsigned short int level);

        static unsigned short int getBrightnessMax();

    private:
    };
}

#endif