#include "../ConsoleManager.hpp"
#include "../Input/Input.hpp"

using namespace std;
using namespace IO;


int main() {
    clear();
    setxy(5, 3);
    print("Hello");
    println("Hi");
    print("lol");
    
    KeyboardListener kl;
    
    while(true) {
        clear();
        KeyID id = kl.getPressedKeyId();
        setxy(1, 1);
        putchar((char)id);
        
        if(id == KeyID::ESC) {
            setxy(50, 5);
            println("Bye");
            break;
        }
    }
}