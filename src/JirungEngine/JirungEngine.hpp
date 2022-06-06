#ifndef __JirungEngine_hpp__
#define __JirungEngine_hpp__

#include "GraphicModule/Canvas/Canvas.hpp"
#include "GraphicModule/Canvas/Canvas3D.hpp"
#include "GraphicModule/Pixel/Pixel.hpp"
#include "GraphicModule/Image/TextImage.hpp"
#include "GraphicModule/Viewer/Viewer.hpp"
#include "GraphicModule/Viewer/ConsoleViewer.hpp"
#include "ObjectModule/Collider/Collider.hpp"
#include "ObjectModule/Collider/BoxCollider.hpp"
#include "ObjectModule/EventListener/EventListener.hpp"
#include "ObjectModule/Physics/Physics.hpp"
#include "ObjectModule/Object.hpp"
#include "Logger/Logger.hpp"
#include "MathModule/Math.hpp"


namespace JirungEngine {
    class Game {
    public:
        Canvas canvas;
        // Object object;

    public:
        Game(const Canvas& canvas);
        Game();

    public:
        virtual void play() = 0;
    };
}

#endif