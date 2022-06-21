#ifndef __Panel_hpp__
#define __Panel_hpp__

#include "../Plane/Plane.hpp"


namespace Math {
    class Panel : public Plane {
    public:
        unsigned int width;
        unsigned int height;
        float rotate_angle;

    public:
        Panel(unsigned int width, unsigned int height);
        Panel();

    public:
        Point leftTop() const;
        Point leftBottom() const;
        Point rightTop() const;
        Point rightBottom() const;

    private:
        Point centerTop() const;
        Point leftCenter() const;

        Vector toTop() const;
        Vector toLeft() const;
    };
}

#endif