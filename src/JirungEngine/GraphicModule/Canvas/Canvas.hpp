#ifndef __Canvas_hpp__
#define __Canvas_hpp__

#include <string>

#include "../Pixel/Pixel.hpp"
#include "../../Point/Point.hpp"
#include "../../Vector/Vector2D.hpp"
#include "../../Collider/Collider.hpp"
#include "../../Collider/BoxCollider.hpp"


namespace JirungEngine {
    class Canvas {
        private: size_t width_max;
        private: size_t height_max;
        private: size_t width;
        private: size_t height;
        private: Pixel** pixel;
        private: Pixel default_background;

    public:
        Canvas();
        ~Canvas();

    public:
        std::string getByString() const;
        void draw(std::string content, int pos_x, int pos_y, bool draw_empty_char = true);
        void draw(Canvas canvas, Point point, bool draw_empty_char = true);
        void draw(Vector2D vector2d, Point point);
        void draw(Collider collider, Point point);
        void draw(BoxCollider collider, Point point);
        void erase(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y);
        void erase(unsigned int pos_x, unsigned int pos_y);
    };
}

#endif