#ifndef __TextImage_hpp__
#define __TextImage_hpp__

#include <string>

#include "../Pixel/Pixel.hpp"


namespace JirungEngine {
    class TextImage {
        private: unsigned int width;
        private: unsigned int height;
        private: Pixel** pixel;

    public:
        TextImage(std::string file_name);
        TextImage();
        ~TextImage();
        
    public:
        unsigned short getWidth() const;
        unsigned short getHeight() const;
        Pixel** get() const;
        char** getByChars() const;
        std::string getByString() const;
    };
}

#endif