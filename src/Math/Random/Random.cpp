#include "Random.hpp"

#include <random>

using namespace std;
using namespace Math;

int Math::getRandomInt(int from, int to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(from, to);
    
    return dis(gen);
}

float Math::getRandomFloat(float from, float to) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(from, to);
    
    return dis(gen);
}