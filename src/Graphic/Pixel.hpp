#ifndef __Pixel_hpp__
#define __Pixel_hpp__


namespace Graphic {
    class Pixel {
    public:
        virtual float getBrightness() const = 0;
        virtual void setBrightness(float level) = 0;
        virtual unsigned short int getBrightnessMax() const = 0;
    };
}

#endif