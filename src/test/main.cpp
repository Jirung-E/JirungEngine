#include "../JirungEngine/JirungEngine.hpp"
#include "../Util/Util.hpp"

using namespace std;
using namespace JirungEngine;
using namespace Util;


void test_Vector2D();
void test_Canvas();
void test_Canvas_DrawVectorAndCollider();
void test_Canvas_EraseAndClear();
void test_TextImageAndObject();
void test_Object_1();

int main() {
    println("\nTest Start!\n\n");
    
    test_Object_1();
}







void test_Vector2D() {
    Vector2D v1 { 10, 5 };
    Vector2D v2 { v1 + Vector2D { 5, 5 } };
    Vector2D v3 = v1;
    Vector2D v4 = v1*2;
    Vector2D v5 = Vector2D { -10, -20 };
    
    println("Hi");
    printf("v1: <%f, %f>\n", v1.x, v1.y);
    printf("v2: <%f, %f>\n", v2.x, v2.y);
    println(to_string(v1*v2));
    
    printf("v3: <%f, %f>\n", v3.x, v3.y);
    printf("v4: <%f, %f>\n", v4.x, v4.y);
    printf("v5: <%f, %f>\n", v5.x, v5.y);
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

void test_Canvas_DrawVectorAndCollider() {
    Canvas main_canvas;
    main_canvas.setDefaultBackground('+');
    main_canvas.title = "Vector And Collider";
    
    Canvas vector_canvas;
    vector_canvas.title = "vector";
    vector_canvas.width = 37;
    vector_canvas.height = 37;
    
    Canvas collider_canvas;
    collider_canvas.title = "collider";
    collider_canvas.width = 37;
    collider_canvas.height = 37;
    
    // vector_canvas.draw(Vector(5, 5, 0), Point(2, 2));
    // vector_canvas.draw(Vector(-5, -5, 0), Point(20, 10));
    // vector_canvas.draw(Vector(7, -10, 0), Point(1, 14));
    // vector_canvas.draw(Vector(0, 10, 0), Point(10, 4));
    // vector_canvas.draw(Vector(10, 0, 0), Point(0, 0));
    // vector_canvas.draw(Vector(30, -4, 0), Point(1, 35));
    // vector_canvas.draw(Vector(9, -25, 0), Point(18, 32));
    // vector_canvas.draw(Vector(-25, 4, 0), Point(35, 25));
    vector_canvas.draw(Vector(7, 0, 0), Point(18, 18));
    vector_canvas.draw(Vector(7, 7, 0), Point(18, 18));
    vector_canvas.draw(Vector(0, 7, 0), Point(18, 18));
    vector_canvas.draw(Vector(-7, 7, 0), Point(18, 18));
    vector_canvas.draw(Vector(-7, 0, 0), Point(18, 18));
    vector_canvas.draw(Vector(-7, -7, 0), Point(18, 18));
    vector_canvas.draw(Vector(0, -7, 0), Point(18, 18));
    vector_canvas.draw(Vector(7, -7, 0), Point(18, 18));
    vector_canvas.draw(Vector(7, 3, 0), Point(18, 18));
    vector_canvas.draw(Vector(3, 7, 0), Point(18, 18));
    vector_canvas.draw(Vector(-3, 7, 0), Point(18, 18));
    vector_canvas.draw(Vector(-7, 3, 0), Point(18, 18));
    vector_canvas.draw(Vector(-7, -3, 0), Point(18, 18));
    vector_canvas.draw(Vector(-3, -7, 0), Point(18, 18));
    vector_canvas.draw(Vector(3, -7, 0), Point(18, 18));
    vector_canvas.draw(Vector(7, -3, 0), Point(18, 18));

    collider_canvas.draw(Collider(Point(18, 9), Vector2D(7, 0)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(7, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(0, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(-7, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(-7, 0)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(-7, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(0, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(7, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(7, 3)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(3, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(-3, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(-7, 3)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(-7, -3)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(-3, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(3, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector2D(7, -3)), Point(0, 0));
    collider_canvas.draw(BoxCollider(Point(-5, -3), Point(6, 2)), Point(18, 21));
    BoxCollider b { Point(-1, -1), Point(1, 1) };
    collider_canvas.draw(BoxCollider(b), Point(18, 21));
    b.setTopLeftPoint(Point(-2, -2));
    b.setTopRightPoint(Point(3, -3));
    b.setButtomRightPoint(Point(4, 4));
    b.setButtomLeftPoint(Point(-5, 5));
    collider_canvas.draw(b, Point(18, 30));
    collider_canvas.draw("#", 18, 30);
    
    main_canvas.draw(vector_canvas, { 2, 1 });
    main_canvas.draw(collider_canvas, { 41, 1 });
    println(main_canvas.getByString());
}

void test_Canvas_EraseAndClear() {
    Canvas canvas;
    canvas.draw("Hello\nHello\nHello\nHi\nBye", 5, 5);
    println(canvas.getByString());
    canvas.erase(7, 7, 6, 6);
    canvas.erase(5, 5);
    println(canvas.getByString());
    canvas.clear();
    println(canvas.getByString());
    
    canvas.setDefaultBackground('.');
    println(canvas.getByString());
    
    canvas.draw("Hello\nHello\nHello\nHi\nBye", 5, 5);
    println(canvas.getByString());
    canvas.erase(7, 7, 6, 6);
    canvas.erase(5, 5);
    println(canvas.getByString());
    canvas.clear();
    println(canvas.getByString());
}

void test_TextImageAndObject() {
    Canvas canvas;
    canvas.title = "text images and objects";
    TextImage t { "src/test/test" };
    canvas.draw(t.getByString(), 0, 0);
    println(canvas.getByString());
    
    canvas.draw(t, Point(0, 0));
    
    Object o { "obj" };
    o.image = &t;
    canvas.draw(o.id, 9, 9);
    canvas.draw(o, Point(10, 10));
    
    println(canvas.getByString());
}

void test_Object_1() {
    Object player { "player", Point(5, 5) };
    TextImage player_front { "resource/player_front.txtimg" };
    player.image = &player_front;
    player.collider.push_back(new BoxCollider { player.position, Point(player.position + Point(4, 3)) });

    Canvas canvas;
    canvas.draw(player, Point(0, 0));
    
    TextImage player_back { "resource/player_back.txtimg" };
    player.image = &player_back;
    canvas.draw(player, Point(5, 0));
    
    TextImage player_left { "resource/player_left.txtimg" };
    player.image = &player_left;
    canvas.draw(player, Point(10, 0));
    
    TextImage player_right { "resource/player_right.txtimg" };
    player.image = &player_right;
    canvas.draw(player, Point(15, 0));
    
    canvas.draw(*player.collider.back(), Point(0, 0));
    
    println(canvas.getByString());
}