#ifndef __MathematicalObject_hpp__
#define __MathematicalObject_hpp__

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"


namespace JirungEngine {
    class MathematicalObject {
    public:
        Point position;
        Point pivot;
        Line x_axis;
        Line y_axis;
        Line z_axis;
    };
}

#endif