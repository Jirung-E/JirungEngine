#include "Util/Util.hpp"

using namespace std;
using namespace Util;


void testUtil() {
    cout << "Test Start" << endl;
    
    for(int i=0; i<100; ++i) {
        println(to_string(getRandomFloat(-10.0f, 14.4f)));
    }
    for(int i=0; i<100; ++i) {
        println(to_string(getRandomInt(-5, 20)));
    }
    println();
    
    println("sleep for 5000 milliseconds");
    sleep(5000);
    println("Test End");
}


int main() {
    testUtil();
}