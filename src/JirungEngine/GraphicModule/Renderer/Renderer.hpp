#ifndef __Renderer_hpp__
#define __Renderer_hpp__

#include "../../MathModule/Math.hpp"
#include "../Display/Display.hpp"


namespace JirungEngine {
    class Renderer {
    public:
        class Camera {
        public:
            Point position;
            Vector direction;

            unsigned short int view_distance;

        public: 
            Camera();
        } camera;

        Display* image;

    public:
        Renderer(unsigned short int width, unsigned short int height);
        Renderer();
        
    public:
        Display renderGeneral(const Polygon& polygon);
        Display renderClear(const Polygon& polygon);

    private:
        void clearImage();

        void renderPoint(const Point& point);
        void renderSegment(const Segment& segment);
    };
}

#endif