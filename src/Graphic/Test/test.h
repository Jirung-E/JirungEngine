#include "../Graphic.hpp"
#include "../ConsoleImage.hpp"

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

void testImageEditor() {
    ImageEditor ed;
    Image* img1 = new ConsoleImage { 120, 60 };
    for(int i=0; i<img1->getHeight(); ++i) {
        for(int k=0; k<img1->getWidth(); ++k) {
            img1->setPixelBrightness(20 + i + k, k, i);
        }
    }
    Image* img2 = new ConsoleImage { 10, 10 };
    for(int i=0; i<img2->getHeight(); ++i) {
        for(int k=0; k<img2->getWidth(); ++k) {
            img2->setPixelBrightness(100 - 5*(i+k), k, i);
        }
    }
    Image* img3 = new ConsoleImage { 20, 20 };
    for(int i=0; i<img3->getHeight(); ++i) {
        for(int k=0; k<img3->getWidth(); ++k) {
            img3->setPixelBrightness(50 + 2*(i-k), k, i);
        }
    }
    
    ed.draw(img1, img2, 20, 20);
    ed.draw(img1, img3, -5, -5);
    
    ConsoleImage* ci = new ConsoleImage { img1 };
    puts(ci->getByString().c_str());
}


void test() {
    testImage();
    testImageEditor();
}