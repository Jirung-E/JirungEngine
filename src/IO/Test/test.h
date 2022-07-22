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


void testGetInput() {
    Input* in = new KeyboardListener { };
    
    for(int i=0; i<50; ++i) {
        KeyID id = in->getInput();
        println(to_string((int)id));

        if(id == KeyID::BACKSPACE) {
            println("<-");
        }
    }
}

void testDetectKeyPress() {
    Input* in = new KeyboardListener { };
    
    while(true) {
        if(in->detectKeyPress()) {
            KeyID id = in->getInput();
            println(to_string((int)id));
            if(id == KeyID::ESC) {
                println("ESC");
                break;
            }
        }
    }
}

void showNums() {
    for(int i=0; i<100; ++i) {
        clear();
        setxy(1, 1);
        println(to_string(i));
        sleep(250);
    }
}

void testGetInputByAnotherThread() {
    thread input_thread { testDetectKeyPress };
    thread view_thread { showNums };
    view_thread.join();
    input_thread.join();
}

void test() {
    clear();
    println("Starting Tests!!");
    testGetInput();
    println("--------------------------");
    //testDetectKeyPress();
    println("--------------------------");
    sleep(1000);
    testGetInputByAnotherThread();
    println("--------------------------");
}