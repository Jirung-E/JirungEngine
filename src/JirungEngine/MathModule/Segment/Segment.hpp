#ifndef __Segment_hpp__
#define __Segment_hpp__

#include "../Line/Line.hpp"


namespace JirungEngine {
    class Segment : public Line {
    public:
        Segment(Point point, Vector vector);
        Segment(Point from, Point to);
        Segment(Vector vector);

        Segment operator=(const Segment& segment) = default;

    public:
        Point getStartPoint() const;
        Point getEndPoint() const;

        // Point getNearestPointFrom(const Point& point) const;
        // Point getNearestPointFrom(const Segment& segment) const;
        bool isParallelTo(const Segment& other) const;

        static bool isParallel(const Segment& segment1, const Segment& segment2);
        // static Point getNearestPoint(const Segment& segment, const Point& point);
        // static Point getNearestPoint(const Segment& to, const Segment& from);
    };
}

#endif