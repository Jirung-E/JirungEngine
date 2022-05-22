#ifndef __Canvas_hpp__
#define __Canvas_hpp__

#include <string>

#include "../Pixel/Pixel.hpp"
#include "../Image/TextImage.hpp"
#include "../../MathModule/Point/Point.hpp"
#include "../../MathModule/Vector/Vector2D.hpp"
#include "../../MathModule/Vector/Vector.hpp"
#include "../../ObjectModule/Collider/Collider.hpp"
#include "../../ObjectModule/Collider/BoxCollider.hpp"
#include "../../ObjectModule/Object.hpp"


namespace JirungEngine {
    class Canvas {
        public: std::string title;
        private: size_t width_max;
        private: size_t height_max;
        public: size_t width;
        public: size_t height;
        private: Pixel** pixel;
        private: Pixel default_background;

    public:
        Canvas(size_t width, size_t height);
        Canvas();
        ~Canvas();

    public:
        void setDefaultBackground(char c = ' ');
        std::string getByString() const;
        std::string getByString(size_t width, size_t height) const;
        void draw(std::string content, int pos_x, int pos_y, bool draw_empty_char = true);
        void draw(std::string content, const Point& point, bool draw_empty_char = true);
        void draw(const TextImage& text_image, const Point& point, bool draw_empty_char = true);
        void draw(const Object& object, const Point& point, bool draw_empty_char = true);
        void draw(const Object& object, bool draw_empty_char = true);
        void draw(const Canvas& canvas, const Point& point = Point { 0, 0, 0 }, bool draw_empty_char = true);
        void draw(const Vector2D& vector2d, const Point& point);
        void draw(const Vector& vector, const Point& point);
        void draw(const Segment& segment, const Point& origin = Point { 0, 0, 0 });
        void draw(const Collider& collider, const Point& point);
        void draw(const BoxCollider& collider, const Point& point);
        void erase(int start_x, int start_y, int end_x, int end_y);
        void erase(int pos_x, int pos_y);
        void clear();
    };
}

#endif