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

            Line x_axis;
            Line y_axis;
            Line z_axis;

        private:
            unsigned short int view_distance;
            float field_of_view;                // radian

        public: 
            Camera();

        public:
            Vector getLeftLimit() const;
            Vector getRightLimit() const;
            Vector getTopLimit() const;
            Vector getBottomLimit() const;
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