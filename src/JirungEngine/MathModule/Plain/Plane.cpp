#include "Plane.hpp"

using namespace JirungEngine;


Plane(Point point, Vector normal_vector) : point { point }, normal_vector { normal_vector } {
    
}

Plane(Vector normal_vector) : Plane { Point { 0, 0, 0 }, normal_vector } {
    
}


