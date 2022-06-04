#ifndef __Panel_hpp__
#define __Panel_hpp__

#include "../Plane/Plane.hpp"


namespace JirungEngine {
    class Panel : public Plane {
    public:
        unsigned int width;
        unsigned int height;
        float rotate_angle;

    public:
        Panel(unsigned int width, unsigned int height);
        Panel();

    public:
    
    };
}

#endif