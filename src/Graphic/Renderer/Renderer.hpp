#ifndef __Renderer_hpp__
#define __Renderer_hpp__

#include "../../Math/Math.hpp"
#include "../Display/Display.hpp"


namespace Graphic {
    class Renderer {
    public:
        class Camera : public Math::Geometry {
        public:
            unsigned short int view_distance;
            float field_of_view;                // radian

        public: 
            Camera();

        public:
            Math::Vector direction() const;

            Math::Vector getLeftLimit() const;
            Math::Vector getRightLimit() const;
            Math::Vector getTopLimit() const;
            Math::Vector getBottomLimit() const;
        } camera;

        Display* image;

    public:
        Renderer(unsigned short int width, unsigned short int height);
        Renderer();
        
    public:
        Display renderGeneral(const Math::Polygon& polygon);
        Display renderClear(const Math::Polygon& polygon);

        void clearImage();
        
    private:
        Math::Point getApparentPoint(const Math::Point& point) const;
        Math::Point transformToPointOfDisplay(const Math::Point& point) const;
        void showPointOnImage(const Math::Point& point);
        void renderPoint(const Math::Point& point);
        void renderSegment(const Math::Segment& segment);

        bool isOutOfAngle(const Math::Point& point) const;
    };
}

#endif