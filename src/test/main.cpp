#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


void test_Vector2D();
void test_Canvas();

int main() {
    //test_Vector2D();
    test_Canvas();
}







void test_Vector2D() {
    Vector2D v1 { 10, 5 };
    Vector2D v2 { v1 + Vector2D { 5, 5 } };
    Vector2D v3 = v1;
    Vector2D v4 = v1*2;
    Vector2D v5 = Vector2D { -10, -20 };
    
    println("Hi");
    printf("v1: <%d, %d>\n", v1.x, v1.y);
    printf("v2: <%d, %d>\n", v2.x, v2.y);
    println(to_string(v1*v2));
    
    printf("v3: <%d, %d>\n", v3.x, v3.y);
    printf("v4: <%d, %d>\n", v4.x, v4.y);
    printf("v5: <%d, %d>\n", v5.x, v5.y);
    println(to_string(v1*v5));
}

void test_Canvas() {
    Canvas canvas;
    canvas.setDefaultBackground('.');
    canvas.title = "canvas";
    canvas.draw("Hello Canvas", 0, 0, false);
    canvas.draw("Hello Canvas", -2, 6);
    canvas.draw("Hello Canvas", 5, 5);
    canvas.draw("Hello Canvas", 78, 15);
    canvas.draw("Hello\nCanvas", 50, 30);
    println();
    println(canvas.getByString());
    
    Canvas c1;
    c1.title = "c1";
    c1.width = 5;
    c1.height = 5;
    c1.draw("@@\n@@", 1, 1);
    canvas.draw(c1, { 10, 10 });
    canvas.draw("1\n2  \n3  ", 40, 20);
    println();
    println(c1.getByString(5, 5));
    println();
    println(canvas.getByString());
}