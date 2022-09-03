#include "../Engine/Object/Object.hpp"
#include "../Graphic/Graphic.hpp"
#include "../IO/ConsoleManager.hpp"
#include "../IO/Input/Input.hpp"

#include <thread>

using namespace std;
using namespace Engine;
using namespace Graphic;
using namespace IO;


Renderer* renderer;
Input* input;


void io() {
    println("io");
    input = new KeyboardListener { };
    
    while(true) {
        if(input->detectKeyPress()) {
            input->getInput();
            
            if(input->getPressedKeyID() == KeyID::ESC) {
                break;
            }
        }
    }
}

void graphic() {
    println("graphic");
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