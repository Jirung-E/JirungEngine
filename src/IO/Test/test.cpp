#include "../ConsoleManager.hpp"
#include "../Input/Input.hpp"

#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace IO;


void sleep(unsigned short time) {
    this_thread::sleep_for(milliseconds(time));
}


int main() {
    clear();
    setxy(5, 3);
    print("Hello");
    println("Hi");
    print("lol");
    
    KeyboardListener kl;
    
    int count = 0;
    while(true) {
        if(kl.detectKeyPress()) {
            //KeyID id = kl.getInput();
            setxy(1, 1);
            println("      ");
            setxy(1, 2);
            println("      ");
            setxy(1, 2);
            println(to_string(kl.getPressedKeyID()));
            if(kl.getPressedKeyID() == (int)KeyID::ESC) {
                break;
            }
            if(kl.getPressedKeyID() == (int)KeyID::BACKSPACE) {
                setxy(40, 1);
                println("<-");
            }
        }
        setxy(1, 1);
        println(to_string(count++));
        sleep(1000/30);
    }
    
    kl.inputModeOff();
}