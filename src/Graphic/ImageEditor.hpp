#ifndef __ImageEditor_hpp__
#define __ImageEditor_hpp__

#include "Image.hpp"


namespace Graphic {
    class ImageEditor {
    public:
        static void draw(Image* base, const Image* other, int point_x, int point_y);
    };
}

#endif