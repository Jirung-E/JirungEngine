#ifndef __Segment_hpp__
#define __Segment_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"


namespace JirungEngine {
    class Segment {
        public: Point point;
        public: Vector direction;

        public: Point* start_point;
        public: Point* end_point;

    public:
        Segment(Point point, Vector direction);
        Segment(Vector direction);

    public:
        float x(float parameter) const;
        float y(float parameter) const;
        float z(float parameter) const;
        Point getPointWhenXIs(float value) const;
        Point getPointWhenYIs(float value) const;
        Point getPointWhenZIs(float value) const;

        bool isExistPointOfContactWith(const Segment& other) const;
    };
}

#endif