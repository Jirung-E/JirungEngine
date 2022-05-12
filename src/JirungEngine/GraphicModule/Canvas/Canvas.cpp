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

    int cursur_x = pos_x;
    int cursur_y = pos_y;

    for(int i=0; i<content.length(); ++i) {
        if(cursur_y < 0) {
            continue;
        }
        if(cursur_x < 0) {
            cursur_x++;
            continue;
        }
        if(cursur_y >= height_max || cursur_x >= width_max) {
            continue;
        }

        char c = content.at(i);
        if(c == '\n') {
            cursur_y++;
            cursur_x -= i;
            continue;
        }
        
        if(draw_empty_char == false) {
            if(c == ' ') {
                cursur_x++;
                continue;
            }
        }

        pixel[cursur_y][cursur_x] = Pixel(c);
        cursur_x++;
    }
}

void Canvas::erase(unsigned int start_x, unsigned int start_y, unsigned int end_x, unsigned int end_y) {

}

void Canvas::erase(unsigned int pos_x, unsigned int pos_y) {
    pixel[pos_y][pos_x] = default_background;
}