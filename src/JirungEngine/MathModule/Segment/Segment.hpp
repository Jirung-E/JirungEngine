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
        
        bool isExistPointOfContactWith(const Segment& other) const;

        float getDistanceTo(const Segment& other) const;
        bool isParallelTo(const Segment& other) const;

        static float getDistanceBetween(const Segment& line1, const Segment& line2);
        static Segment getNormalOf(const Segment& line1, const Segment& line2);
        static bool isParallel(const Segment& line1, const Segment& line2);
    };
}

#endif