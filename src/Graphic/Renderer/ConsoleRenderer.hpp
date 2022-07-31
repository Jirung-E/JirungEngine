#ifndef __ConsoleRenderer_hpp__
#define __ConsoleRenderer_hpp__

#include "Renderer.hpp"


namespace Graphic {
    class ConsoleRenderer : public Renderer {
    public:
        ConsoleRenderer(unsigned short int width, unsigned short int height);
        ConsoleRenderer();
    };
}

#endif