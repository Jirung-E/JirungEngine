#include "Segment.hpp"

#include <cmath>

using namespace Math;


Segment::Segment(Point point, Vector vector) : Line { point, vector } {

}

Segment::Segment(Point from, Point to) : Segment { from, Vector { to - from } } {

}

Segment::Segment(Vector vector) : Segment { Point(0, 0, 0), vector } {

}


Line Segment::getLine() const {
    return Line { point, vector };
}


Point Segment::getStartPoint() const {
    return point;
}

Point Segment::getEndPoint() const {
    return point + Point { vector.x, vector.y, vector.z };
}


Point Segment::getNearestPointTo(const Point& point) const {
    Point H { this->Line::getFootOfPerpendicularFrom(point) };
    if(H.isInRange(getStartPoint(), getEndPoint())) {
        return H;
    }
    if(H.getDistanceTo(getStartPoint()) < H.getDistanceTo(getEndPoint())) {
        return getStartPoint();
    }
    return getEndPoint();
}

Point Segment::getNearestPointTo(const Segment& other) const {
    Point this_H { this->Line::getFootOfPerpendicularFrom(other.getLine()) };
    Point other_nearest { other.getNearestPointTo(this_H) };
    return getNearestPointTo(other_nearest);
}

bool Segment::isParallelTo(const Segment& other) const {
    return isParallel(this->vector, other.vector);
}


bool Segment::isParallel(const Segment& segment1, const Segment& segment2) {
    return segment1.isParallelTo(segment2);
}