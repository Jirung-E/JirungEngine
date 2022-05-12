#ifndef __Canvas_hpp__
#define __Canvas_hpp__

#include <string>

#include "../Pixel/Pixel.hpp"
#include "../../Point/Point.hpp"


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
        void erase(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y);
        void erase(unsigned int pos_x, unsigned int pos_y);
    };
}

#endif