#ifndef __Geometry_hpp__
#define __Geometry_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"
#include "../Line/Line.hpp"


namespace JirungEngine {
    class Geometry {
    public:
        Point position;
        Point pivot;
        Line x_axis;
        Line y_axis;
        Line z_axis;

        
    };
}

#endif