#include "../ConsoleManager.hpp"
#include "../Input/Input.hpp"

using namespace std;
using namespace IO;


int main() {
    setxy(5, 3);
    print("Hello");
    println("Hi");
    print("lol");
    
    while(1) {
        int id = getPressedKeyId();
        if(id == 27) {
            break;
        }
        else {
            setxy(1, 1);
            print(to_string(id));
        }
    }
}