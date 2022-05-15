#include "Util.hpp"

#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
using namespace Util;


void Util::print(str_t str) {
    printf("%s", str.c_str());
}

void Util::println(str_t str) {
    printf("%s\n", str.c_str());
}


void Util::sleep(unsigned short time) {
    this_thread::sleep_for(milliseconds(time));
}