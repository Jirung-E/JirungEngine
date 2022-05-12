#include "Canvas.hpp"

using namespace std;
using namespace JirungEngine;


Canvas::Canvas() : width_max { 80 }, height_max { 40 }, width { 0 }, height { 0 }, pixel { new Pixel*[height_max] }, default_background { ' ' } {
    for(int i=0; i<height_max; ++i) {
        pixel[i] = new Pixel[width_max];
    }
}

Canvas::~Canvas() {
    for(int i=0; i<height_max; ++i) {
        delete[] pixel[i];
    }
    delete[] pixel;
}


string Canvas::getByString() const {
    string str_canvas = "";
    for(int i=0; i<height_max; ++i) {
        for(int k=0; k<width_max; ++k) {
            str_canvas += pixel[i][k].getShape();
        }
        str_canvas += '\n';
    }

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
            cursor_x -= i;
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

void Canvas::draw(Canvas canvas, Point point, bool draw_empty_char = true) {

}

void Canvas::draw(Vector2D vector2d, Point point) {

}

void Canvas::draw(Collider collider, Point point) {

}

void Canvas::draw(BoxCollider collider, Point point) {

}


void Canvas::erase(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y) {

}

void Canvas::erase(unsigned int pos_x, unsigned int pos_y) {
    pixel[pos_y][pos_x] = default_background;
}