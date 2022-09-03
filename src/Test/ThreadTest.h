#include "../Engine/Object/Object.hpp"
#include "../Graphic/Graphic.hpp"
#include "../IO/ConsoleManager.hpp"
#include "../IO/Input/Input.hpp"

#include <thread>
#include <chrono>

using namespace std;
using namespace Engine;
using namespace Graphic;
using namespace Math;
using namespace IO;


bool flag = true;

Renderer* renderer;
Input* input;

Object obj1;
Object obj2;


void sleep(unsigned short time) {
    this_thread::sleep_for(chrono::milliseconds(time));
}


void io() {
    println("io");
    input = new KeyboardListener { };
    
    while(flag) {
        if(input->detectKeyPress()) {
            input->getInput();
            
            if(input->getPressedKeyID() == KeyID::ESC) {
                flag = false;
            }
            if(input->getPressedKeyID() == KeyID::M) {
                obj1.addPolygon(new Polygon { });
            }
        }
    }
}

void graphic() {
    println("graphic");
    renderer = new ConsoleRenderer { };
    
    while(flag) {
        for(auto e : obj1.polygons) {
            renderer->renderClear(*e);
        }
        
        ConsoleImage* ci = new ConsoleImage { renderer->image };
        print(ci->getByString());
        
        sleep(1000/30);
    }
}

void engine() {
    println("engine");
}


void testThread() {
    thread io_thread { io };
    thread graphic_thread { graphic };
    thread engine_thread { engine };
    
    io_thread.join();
    graphic_thread.join();
    engine_thread.join();
}