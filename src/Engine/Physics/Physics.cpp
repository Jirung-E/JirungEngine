#include "Physics.hpp"

using namespace Engine;


void Physics::update() {
    velocity += acceleration;
}