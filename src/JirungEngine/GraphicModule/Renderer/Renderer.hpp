#ifndef __Renderer_hpp__
#define __Renderer_hpp__

#include "../../MathModule/Math.hpp"
#include "../Canvas/Canvas.hpp"


namespace JirungEngine {
    class Renderer {
    public:
        class Camera {
        public:
            Point position;
            Vector direction;

        public: 
            Camera();
        } camera;

        Canvas image;

    public:
        Renderer(unsigned short int width, unsigned short int height);
        Renderer();
        
    public:
        void renderGeneral(const Polygon& polygon);
        void renderClear(const Polygon& polygon);

    private:
        void clearImage();
    };
}

#endif