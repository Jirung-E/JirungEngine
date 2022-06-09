#include "Segment.hpp"

#include <cmath>

using namespace std;
using namespace JirungEngine;


Segment::Segment(Point point, Vector vector) : Line { point, vector } {

}

Segment::Segment(Vector vector) : Segment { Point(0, 0, 0), vector } {

}


bool Segment::isParallelTo(const Segment& other) const {
    return this->vector.isParallelTo(other.vector);
}

bool Segment::isParallel(const Segment& segment1, const Segment& segment2) {
    return segment1.isParallelTo(segment2);
}