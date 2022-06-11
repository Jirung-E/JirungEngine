#ifndef __Pixel_hpp__
#define __Pixel_hpp__

#include <string>
#include <vector>


namespace JirungEngine {
    class Pixel {
    private:
        char pixel;
        static vector<char> pixel_set;
        unsigned short int brightness;

    public:
        Pixel(char c = ' ');
        Pixel(const Pixel& pixel);
        
        Pixel operator=(const Pixel& other);

    public:
        std::string get() const;
        void setBrightness(unsigned short int level);

        unsigned short int getBrightnessMax() const;

    private:
    };
}

#endif