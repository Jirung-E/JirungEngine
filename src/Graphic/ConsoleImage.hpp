#ifndef __ConsoleImage_hpp__
#define __ConsoleImage_hpp__

#include "Image.hpp"

#include <string>


namespace Graphic {
    class ConsoleImage : public Image {
    public:
        ConsoleImage(unsigned short int width, unsigned short int height);
        ConsoleImage();
        ConsoleImage(const ConsoleImage& image);
        ConsoleImage(const Image* image);
        ~ConsoleImage();

    public:
        std::string getByString() const;
    };
}

#endif