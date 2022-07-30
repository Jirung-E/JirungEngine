#include "../Graphic.hpp"
#include "../Image/ConsoleImage.hpp"

using namespace std;
using namespace Graphic;


void testImage() {
    Image* image = new ConsoleImage { };
    
    image->setPixelBrightness(10, 5, 5);
    image->setPixelBrightness(20, 6, 5);
    image->setPixelBrightness(30, 7, 5);
    image->setPixelBrightness(40, 8, 5);
    image->setPixelBrightness(50, 9, 5);
    image->setPixelBrightness(60, 10, 5);
    image->setPixelBrightness(70, 11, 5);
    image->setPixelBrightness(80, 12, 5);
    image->setPixelBrightness(90, 13, 5);
    image->setPixelBrightness(100, 14, 5);
    image->setPixelBrightness(200, 15, 5);
    
    for(int brightness=0; brightness<=100; brightness+=5) {
        for(int i=0; i<24; ++i) {
            image->setPixelBrightness(brightness, i, brightness/5);
        }
    }
    
    ConsoleImage* ci = new ConsoleImage { image };
    puts(ci->getByString().c_str());
    
    puts("-----------------------------------------------------");
    
    ci->clear();
    puts(ci->getByString().c_str());
}


void test() {
    testImage();
}