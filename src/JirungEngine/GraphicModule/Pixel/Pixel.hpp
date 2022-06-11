#ifndef __Pixel_hpp__
#define __Pixel_hpp__

#include <string>


namespace JirungEngine {
    class Pixel {
    private:
        char pixel;
        const char safe_null = '\0';

    public:
        Pixel(char c = ' ');
        Pixel(const Pixel& pixel);
        
        Pixel operator=(const Pixel& other);

    public:
        std::string get() const;
        void set(char c);
    };
}

#endif