#include "Geometry.hpp"

using namespace JirungEngine;


Geometry::Geometry() : position { 0, 0, 0 }, pivot { 0, 0, 0 }, x_axis { pivot, Vector::i() }, y_axis { pivot, Vector::j() }, z_axis { pivot, Vector::k() } {

}