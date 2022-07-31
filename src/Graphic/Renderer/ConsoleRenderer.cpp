#include "ConsoleRenderer.hpp"

#include "../Image/ConsoleImage.hpp"

#include <cmath>

using namespace Graphic;


ConsoleRenderer::ConsoleRenderer(unsigned short int width, unsigned short int height) : Renderer { } {
    image = new ConsoleImage { width, height };
}

ConsoleRenderer::ConsoleRenderer() : ConsoleRenderer { 160, 45 } {

}