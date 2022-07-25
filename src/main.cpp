#include "Math/Math.hpp"
#include "IO/Input/Input.hpp"
#include "IO/ConsoleManager.hpp"
#include "Graphic/Graphic.hpp"

#include <thread>
#include <chrono>

using namespace std;
using namespace Math;
using namespace IO;
using namespace Graphic;


void sleep(unsigned short time) {
    this_thread::sleep_for(chrono::milliseconds(time));
}


void showLoadingAnimation() {
    setxy(10, 10);
    print("#");
    sleep(100);
    setxy(10, 10);
    print(" ");
    
    setxy(11, 10);
    print("#");
    sleep(100);
    setxy(11, 10);
    print(" ");
    
    setxy(12, 10);
    print("#");
    sleep(100);
    setxy(12, 10);
    print(" ");
    
    setxy(12, 11);
    print("#");
    sleep(100);
    setxy(12, 11);
    print(" ");
    
    setxy(12, 12);
    print("#");
    sleep(100);
    setxy(12, 12);
    print(" ");
    
    setxy(11, 12);
    print("#");
    sleep(100);
    setxy(11, 12);
    print(" ");
    
    setxy(10, 12);
    print("#");
    sleep(100);
    setxy(10, 12);
    print(" ");
    
    setxy(10, 11);
    print("#");
    sleep(100);
    setxy(10, 11);
    print(" ");
}

void testIOandMath() {
    clear(); 
    
    Point p[2];
    int n = 0;
    
    setxy(1, 1);
    println("Press Enter to show p[0] + p[1], Press Space to change values, Press ESC to exit program.");
    printf("p[%d] =        ( %f, %f, %f )   \n", 0, p[0].x, p[0].y, p[0].z);
    printf("p[%d] =        ( %f, %f, %f )   \n", 1, p[1].x, p[1].y, p[1].z);
    
    thread graphic_thread { [&]() { while(true)showLoadingAnimation(); } };
    
    Input* in = new KeyboardListener { };
    while(true) {
        if(in->detectKeyPress()) {
            in->getInput();
            if(in->getPressedKeyID() == KeyID::SPACE) {
                if(n >= 2) {
                    n = 0;
                }
                p[n].x = getRandomFloat(-10.0f, 10.0f);
                p[n].y = getRandomFloat(-10.0f, 10.0f);
                p[n].z = getRandomFloat(-10.0f, 10.0f);
                setxy(1, n+2);
                printf("p[%d] =        ( %f, %f, %f )   ", n, p[n].x, p[n].y, p[n].z);
                n++;
            }
            if(in->getPressedKeyID() == KeyID::ENTER) {
                setxy(1, 5);
                printf("p[0] + p[1] = ( %f, %f, %f )   \n", p[0].x + p[1].x, p[0].y + p[1].y, p[0].z + p[1].z);
            }
            if(in->getPressedKeyID() == KeyID::ESC) {
                break;
            }
        }
    }
    
    graphic_thread.detach();
}


void testRenderer() {
	println("\nTest Start!\n\n");

    Renderer renderer;
    Polygon pol[50];
    int cnt = 0;
    for(Polygon& e : pol) {
        e.moveTo(e.p1 - Point { 0, 0, -50.0f + cnt * 3.0f });
        e.rotate(Line(e.getCenterOfGravity(), e.getNormal()), cnt/10.0f);
        cnt++;
    }
    
    Input* in = new KeyboardListener { };
    
    while(true) {
        if(in->detectKeyPress()) {
            in->getInput();
            
            switch(in->getPressedKeyID()) {
                case KeyID::W:
                    renderer.camera.moveTo(renderer.camera.getPosition() + Point { renderer.camera.direction() * 0.3f });
                    break;
                case KeyID::S:
                    renderer.camera.moveTo(renderer.camera.getPosition() - Point { renderer.camera.direction() * 0.3f });
                    break;
                case KeyID::A:
                    renderer.camera.moveTo(renderer.camera.getPosition() - Point { renderer.camera.getXAxis().vector * 0.3f });
                    break;
                case KeyID::D:
                    renderer.camera.moveTo(renderer.camera.getPosition() + Point { renderer.camera.getXAxis().vector * 0.3f });
                    break;
                case KeyID::UPARROW:
                    renderer.camera.rotateX(0.02f);
                    break;
                case KeyID::DOWNARROW:
                    renderer.camera.rotateX(-0.02f);
                    break;
                case KeyID::LEFTARROW:
                    renderer.camera.rotateY(0.02f);
                    break;
                case KeyID::RIGHTARROW:
                    renderer.camera.rotateY(-0.02f);
                    break;
                case KeyID::SPACE:
                    renderer.camera.moveTo(renderer.camera.getPosition() + Point { 0, 0.2f, 0 });
                    break;
                case KeyID::C:
                    renderer.camera.moveTo(renderer.camera.getPosition() - Point { 0, 0.2f, 0 });
                    break;
            }
            
            renderer.clearImage();
            for(const Polygon& e : pol) {
                renderer.renderClear(e);
            }
            print(renderer.image->getByString());
        }
    }
}


int main() {
    testRenderer();
    
}