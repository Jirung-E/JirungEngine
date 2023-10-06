#include "ImageEditor.hpp"

using namespace Graphic;


void ImageEditor::draw(Image* base, const Image* other, int point_x, int point_y) {
    for(int i=0; i<other->getHeight(); ++i) {
        for(int k=0; k<other->getWidth(); ++k) {
            base->setPixelBrightness(other->getPixelBrightness(k, i), k + point_x, i + point_y);
        }
    }
}