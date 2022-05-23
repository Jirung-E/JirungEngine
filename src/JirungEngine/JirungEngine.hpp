#ifndef __JirungEngine_hpp__
#define __JirungEngine_hpp__

#include "GraphicModule/Canvas/Canvas.hpp"
#include "GraphicModule/Pixel/Pixel.hpp"
#include "GraphicModule/Image/TextImage.hpp"
#include "ObjectModule/Collider/Collider.hpp"
#include "ObjectModule/Collider/BoxCollider.hpp"
#include "ObjectModule/EventListener/EventListener.hpp"
#include "ObjectModule/Physics/Physics.hpp"
#include "ObjectModule/Object.hpp"
#include "Logger/Logger.hpp"
#include "MathModule/Point/Point.hpp"
#include "MathModule/Vector/Vector2D.hpp"
#include "MathModule/Vector/Vector.hpp"
#include "MathModule/Segment/Segment.hpp"


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