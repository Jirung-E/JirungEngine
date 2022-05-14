#include "TextImage.hpp"

#include <fstream>
#include <iostream>

using namespace std;
using namespace JirungEngine;


TextImage::TextImage() : width { 1 }, height { 1 }, pixel { } {
    pixel = new Pixel*[height];
    for(int i=0; i<height; ++i) {
        pixel[i] = new Pixel[width];
    }
}

TextImage::TextImage(string file_name) : width { 0 }, height { 0 }, pixel { } {
    ifstream file { file_name };
    if(file.is_open()) {
        file >> width >> height;
        string buffer_erase;
        getline(file, buffer_erase);

        pixel = new Pixel*[height];
        for(int i=0; i<height; ++i) {
            pixel[i] = new Pixel[width];
        }

        for(int i=0; i<height; ++i) {
            string line;
            getline(file, line);
            for(int k=0; k<width; ++k) {
                pixel[i][k] = line.at(k);
            }
        }
    }
    file.close();
}

TextImage::~TextImage() {
    for(int i=0; i<height; ++i) {
        delete[] pixel[i];
    }
    delete[] pixel;
}

unsigned short TextImage::getWidth() const {
	return width;
}

unsigned short TextImage::getHeight() const {
	return height;
}

Pixel** TextImage::get() const {
    return pixel;
}

string TextImage::getByString() const {
    string result = "";
    for(int i=0; i<height; ++i) {
        for(int k=0; k<width; ++k) {
            result += pixel[i][k].getShape();
        }
        result += '\n';
    }
    result.pop_back();
    return result;
}