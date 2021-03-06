#ifndef __Point_hpp__
#define __Point_hpp__

namespace JirungEngine {
    class Point {
        public: float x;
        public: float y;
        public: float z;

    public:
        Point();
        Point(float x, float y, float z = 0);
        Point(const Point& point);

        Point operator=(const Point& point);
        Point operator+(const Point& point) const;
        Point operator-(const Point& point) const;
        Point operator*(float n) const;
        Point operator/(float n) const;
        bool operator==(const Point& point) const;
        bool operator!=(const Point& point) const;
        Point operator+=(const Point& point);
        Point operator-=(const Point& point);
        Point operator*=(float n);
        Point operator/=(float n);

        bool isInRange(const Point& point1, const Point& point2) const;
        
        float getDistanceTo(const Point& other) const;
        static float getDistanceBetween(const Point& point1, const Point& point2);

        static Point origin();
    };
}

#endif