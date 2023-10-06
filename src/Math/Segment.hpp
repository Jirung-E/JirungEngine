#ifndef __Segment_hpp__
#define __Segment_hpp__

#include "Line.hpp"


namespace Math {
    class Segment : public Line {
    public:
        Segment(Point point, Vector vector);
        Segment(Point from, Point to);
        Segment(Vector vector);

        Segment& operator=(const Segment& segment) = default;

    public:
        Line getLine() const;

        Point getStartPoint() const;
        Point getEndPoint() const;

        Point getNearestPointTo(const Point& point) const;
        Point getNearestPointTo(const Segment& other) const;
        bool isParallelTo(const Segment& other) const;

        static bool isParallel(const Segment& segment1, const Segment& segment2);
    };
}

#endif