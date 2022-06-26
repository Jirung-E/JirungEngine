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
    
    kl.inputModeOn();
    int count = 0;
    while(true) {
        if(kl.detectKeyPress()) {
            clear();
            
            if(kl.getPressedKeyId() == KeyID::ESC) {
                break;;
            }
            
            // if(kl.getKeyDown(KeyID::BACKSPACE)) {
            //     setxy(40, 1);
            //     println("<-");
            // }
            // if(kl.getKeyDown(KeyID::ESC)) {
            //     setxy(50, 5);
            //     println("Bye");
            //     break;
            // }

            setxy(1, 1);
            println(to_string(count++));
            sleep(1000/30);
        }
    }
    kl.inputModeOff();
}