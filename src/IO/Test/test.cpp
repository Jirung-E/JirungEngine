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


void test() {
    clear();
    setxy(5, 3);
    print("Hello");
    println("Hi");
    print("lol");

    Input* in = new KeyboardListener { };
    
    int count = 0;
    while(true) {
        if(in->detectKeyPress()) {
            setxy(1, 1);
            println("      ");
            
            setxy(1, 2);
            println("      ");
            setxy(1, 2);
            println(to_string(in->getPressedKeyID()));
            
            if(in->getPressedKeyID() == (int)KeyID::ESC) {
                setxy(5, 3);
                print("Exit? : ");
                if(in->getInput() == KeyID('Y')) {
                    break;
                }
                else {
                    setxy(5, 3);
                    print("         ");
                }
            }
            if(in->getPressedKeyID() == (int)KeyID::BACKSPACE) {
                setxy(40, 1);
                println("<-");
            }
        }
        
        setxy(1, 1);
        //println(to_string(count++));
        //sleep(1000/3);
    }
}


int main() {
    test();
}