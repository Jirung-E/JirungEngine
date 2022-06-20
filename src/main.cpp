#include "Util/Util.hpp"

using namespace std;
using namespace Util;


int main() {
    cout << "Test Start" << endl;
    
    for(int i=0; i<100; ++i) {
        float f = getRandomFloat(-10.0f, 14.4f);
        println(to_string(f));
    }
    for(int i=0; i<100; ++i) {
        int in = getRandomInt(-5, 20);
        println(to_string(in));
    }
    println();
    
    sleep(5000);
    println("Test End");
}