#include "Math/Math.hpp"
#include "IO/Input/Input.hpp"
#include "IO/ConsoleManager.hpp"

#include <thread>
#include <chrono>

using namespace std;
using namespace Math;
using namespace IO;


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


int main() {
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