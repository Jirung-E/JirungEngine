#include "Panel.hpp"

using namespace JirungEngine;


Panel::Panel(unsigned int width, unsigned int height) : Plane { }, width { width }, height { height }, rotate_angle { 0.0f } {

}

Panel::Panel() : Panel { 10, 10 } {

}