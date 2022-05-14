#include "Canvas.hpp"

#include "../../../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


Canvas::Canvas() : title { }, width_max { 80 }, height_max { 40 }, width { 0 }, height { 0 }, pixel { new Pixel*[height_max] }, default_background { ' ' } {
    for(int i=0; i<height_max; ++i) {
        pixel[i] = new Pixel[width_max];
    }
    setDefaultBackground(' ');
}

Canvas::~Canvas() {
    for(int i=0; i<height_max; ++i) {
        delete[] pixel[i];
    }
    delete[] pixel;
}


void Canvas::setDefaultBackground(char c) {
    default_background = c;
    for(int i=0; i<height_max; ++i) {
        for(int k=0; k<width_max; ++k) {
            pixel[i][k] = default_background;
        }
    }
}

string Canvas::getByString() const {
    return getByString(width_max, height_max);
}

string Canvas::getByString(size_t width, size_t height) const {
    if(width > width_max) {
        width = width_max;
    }
    if(height > height_max) {
        height = height_max;
    }

    string str_canvas = "";
    if(title != "") {
        for(int i=0; i<title.length() && i<width; ++i) {
            str_canvas += title[i];
        }
        while(str_canvas.length() < width) {
            str_canvas += ' ';
        }
        str_canvas += '\n';
    }
    
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            str_canvas += pixel[i][k].getShape();
        }
        str_canvas += '\n';
    }
    
    // for(int k=0; k<width; ++k) {
    //     str_canvas += '-';
    // }
    // str_canvas += '\n';

    return str_canvas;
}

void Canvas::draw(string content, int pos_x, int pos_y, bool draw_empty_char) {
    if(pos_x >= static_cast<int>(width_max) || pos_y >= static_cast<int>(height_max)) {
        return;
    }

    int cursor_x = pos_x;
    int cursor_y = pos_y;

    for(int i=0; i<content.length(); ++i) {
        if(cursor_y < 0) {
            continue;
        }
        if(cursor_x < 0) {
            cursor_x++;
            continue;
        }
        if(cursor_y >= height_max || cursor_x >= width_max) {
            continue;
        }

        char c = content.at(i);
        if(c == '\n') {
            cursor_y++;
            cursor_x = pos_x;
            continue;
        }
        
        if(draw_empty_char == false) {
            if(c == ' ') {
                cursor_x++;
                continue;
            }
        }

        pixel[cursor_y][cursor_x] = Pixel(c);
        cursor_x++;
    }
}

void Canvas::draw(const Canvas& canvas, const Point& point, bool draw_empty_char) {
    draw(canvas.getByString(canvas.width, canvas.height), point.x, point.y, draw_empty_char);
}

void Canvas::draw(const Vector2D& vector2d, const Point& point) {
    Point start_point { point };
    Point end_point { point.x + vector2d.x, point.y + vector2d.y };
    
    int abs_x = vector2d.x >= 0 ? vector2d.x : -vector2d.x;
    int abs_y = vector2d.y >= 0 ? vector2d.y : -vector2d.y;
    int num_of_pixels = abs_x >= abs_y ? abs_x : abs_y;
    
    auto round = [](float num) -> int { return static_cast<int>(num) + 0.5 <= num ? static_cast<int>(num+1) : static_cast<int>(num); };
    
    if(num_of_pixels > 0) {
        Point* points = new Point[num_of_pixels];
        for(int i=0; i<num_of_pixels; ++i) {
            points[i] = Point { start_point.x + i*(vector2d.x/num_of_pixels), start_point.y + i*(vector2d.y/num_of_pixels) };
            draw("*", round(points[i].x), round(points[i].y));
        }

        draw("@", round(start_point.x), round(start_point.y));
        draw("+", round(end_point.x), round(end_point.y));
        
        delete[] points;
    }
}

void Canvas::draw(const Vector& vector, const Point& point) {
    draw(Vector2D(vector.x, vector.y), point);
}

void Canvas::draw(const Collider& collider, const Point& point) {
    draw(collider.vector, collider.start_point + point);
}

void Canvas::draw(const BoxCollider& collider, const Point& point) {
    draw(collider.getTopSide(), point);
    draw(collider.getRightSide(), point);
    draw(collider.getButtomSide(), point);
    draw(collider.getLeftSide(), point);
}


void Canvas::erase(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y) {
    Point top_left;
    unsigned int width;
    unsigned int height;
    if(end_x >= start_x) {
        top_left.x = start_x;
        width = end_x - start_x + 1;
    }
    else {
        top_left.x = end_x;
        width = start_x - end_x + 1;
    }
    if(end_y >= start_y) {
        top_left.y = start_y;
        height = end_y - start_y + 1;
    }
    else {
        top_left.y = end_y;
        height = start_y - end_y + 1;
    }
    
    string str = "";
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            str += default_background.getShape();
        }
        str += "\n";
    }
    draw(str, top_left.x, top_left.y, true);
}

void Canvas::erase(unsigned int pos_x, unsigned int pos_y) {
    erase(pos_x, pos_y, pos_x, pos_y);
}

void Canvas::clear() {
    setDefaultBackground(default_background.getShape());
}