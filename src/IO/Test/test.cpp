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
    
    while(1) {
        int id = kl.getPressedKeyId();
        if(id == 27) {
            setxy(1, 1);
            print("Bye");
            break;
        }
        else {
            setxy(1, 1);
            print(to_string(id));
        }
    }
}