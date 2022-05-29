#ifndef __Canvas3D_hpp__
#define __Canvas3D_hpp__

#include "Canvas.hpp"


namespace JirungEngine {
    class Canvas3D : public Canvas {
    private:
        Point camera_position;
        const Point origin;
        const float focal_length;
        
    public:
        Canvas3D(size_t width, size_t height);
        Canvas3D();
        ~Canvas3D();
        
    public:
        void draw(const Vector& vector, const Point& point);
        
        void moveCameraTo(const Point& point);
        
        Point getCameraPosition() const;
    };
};

#endif