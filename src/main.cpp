#include "Util/Util.hpp"

using namespace std;
using namespace Util;


int main() {
    cout << "Test Start" << endl;
    print("testing");
    
    for(int i=0; i<3; ++i) {
        sleep(1000);
        print(".");
    }
    println();
    
    sleep(5000);
    println("Test End");
}