#include "Util.hpp"

#include <chrono>
#include <thread>
#include <random>

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


int Util::getRandomInt(int from, int to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(from, to);
    
    return dis(gen);
}

float Util::getRandomFloat(float from, float to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(from, to);
    
    return dis(gen);
}