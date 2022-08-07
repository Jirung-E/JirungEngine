#ifndef __ImageEditor_hpp__
#define __ImageEditor_hpp__

#include "../Image/Image.hpp"


namespace Graphic {
    class ImageEditor {
    public:
        static void draw(Image* base, Image* other);
    };
}

#endif