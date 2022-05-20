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
void test_Game_1();
void test_Game_2();
void test_Object_2();
void objectParty();
void test_Segment();


int main() {
    println("\nTest Start!\n\n");
    
    test_Segment();
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

    collider_canvas.draw(Collider(Point(18, 9), Vector(7, 0)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(7, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(0, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(-7, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(-7, 0)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(-7, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(0, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(7, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(7, 3)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(3, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(-3, 7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(-7, 3)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(-7, -3)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(-3, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(3, -7)), Point(0, 0));
    collider_canvas.draw(Collider(Point(18, 9), Vector(7, -3)), Point(0, 0));
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
    player.box_collider.push_back(BoxCollider { Point(0, 0), Point(3, 2) });

    Canvas canvas;
    canvas.draw(player, player.position + Point(0, 0));
    canvas.draw(player.box_collider.front(), player.position + Point(0, 0));
    
    TextImage player_back { "resource/player_back.txtimg" };
    player.image = &player_back;
    canvas.draw(player, player.position + Point(5, 0));
    
    TextImage player_left { "resource/player_left.txtimg" };
    player.image = &player_left;
    canvas.draw(player, player.position + Point(10, 0));
    
    TextImage player_right { "resource/player_right.txtimg" };
    player.image = &player_right;
    canvas.draw(player, player.position + Point(15, 0));
    
    Object ground { "ground" };
    ground.image = new TextImage { "resource/ground.txtimg" };
    for(int i=0; i<100; i+=ground.image->getWidth()) {
        canvas.draw(ground, Point(i, 30));
    }
    
    println(canvas.getByString());
}

void test_Game_1() {
    class TestGame : public Game {
    public:
        void play() {
            Object player { "player" };
            Object ground { "ground" };
            player.image = new TextImage { "resource/player_right.txtimg" };
            ground.image = new TextImage { "resource/ground.txtimg" };
            player.position.x = -4;
            player.position.y = 30 - 3;
            for(int i=0; i<100; i+=ground.image->getWidth()) {
                canvas.draw(ground, Point(i, 30));
            }

            while(true) {
                canvas.draw(player, player.position);
                println(canvas.getByString());
                player.position.x++;
                canvas.erase(player.position.x-1, player.position.y, player.position.x + 2, player.position.y + 2);
                sleep(500);
                if(player.position.x > 100) {
                    break;
                }
            }
        }
    } tg;

    tg.play();
}

void test_Game_2() {
    class TestGame : public Game {
    public:
        void play() {
            Object player { "player" };
            Object tile { "tile" };
            player.image = new TextImage { "resource/player_right.txtimg" };
            tile.image = new TextImage { "resource/tile.txtimg" };
            player.position.x = -4;
            player.position.y = 30 - 3;
            for(int i=0; i<100; i+=tile.image->getHeight()) {
                for(int k=0; k<100; k+=tile.image->getWidth()) {
                    canvas.draw(tile, Point(k, i));
                }
            }

            while(true) {
                Canvas temp;
                temp.draw(player, player.position);
                canvas.draw(temp, Point(0, 0), false);
                println(canvas.getByString());
                
                if(player.position.x > 50 && player.position.y < 10) {
                    break;
                }
                
                if(player.position.x > 40) {
                    player.position.x--;
                    player.position.y--;
                    temp.erase(player.position.x, player.position.y+1, player.position.x + 3, player.position.y + 3);
                }
                else if(player.position.y < 20) {
                    player.position.x--;
                    temp.erase(player.position.x+1, player.position.y, player.position.x + 4, player.position.y + 2);
                }
                else {
                    player.position.x++;
                    temp.erase(player.position.x-1, player.position.y, player.position.x + 2, player.position.y + 2);
                }
                
                sleep(500);
            }
        }
    } tg;

    tg.play();
}

void test_Object_2() {
    class TestGame : public Game {
    public:
        void play() {
            Object player { "player" };
            Object ground { "ground" };
            
            player.image = new TextImage { "resource/player_right.txtimg" };
            ground.image = new TextImage { "resource/ground.txtimg" };
            
            player.position.x = 10;
            player.position.y = 5;
            ground.position.y = 30;
            
            player.box_collider.push_back(BoxCollider { Point(0, 0), Point(player.image->getWidth()-1, player.image->getHeight()-1) });
            ground.collider.push_back(Collider { Point(0, 0), Vector(ground.image->getWidth(), 0) });
            
            player.physics.velocity = Vector { 3, 0, 0 };
            player.physics.gravity = Vector { 0, 1, 0 };
            player.physics.elasticity = 0.98;
            
            Canvas grounds;
            for(int i=0; i<100; i+=ground.image->getWidth()) {
                grounds.draw(ground, Point(i, ground.position.y));
            }
            
            while(true) {
                canvas.draw(grounds, Point(0, 0));
                canvas.draw(player, player.position);
                canvas.draw("px:                     ", 1, 2, true);
                canvas.draw("py:                     ", 1, 3, true);
                canvas.draw("vx:                     ", 1, 4, true);
                canvas.draw("vy:                     ", 1, 5, true);
                canvas.draw(to_string(player.position.x), 4, 2);
                canvas.draw(to_string(player.position.y), 4, 3);
                canvas.draw(to_string(player.physics.velocity.x), 4, 4);
                canvas.draw(to_string(player.physics.velocity.y), 4, 5);
                println(canvas.getByString());
                
                Point prev_frame_player_position = player.position;
                
                player.physics.velocity = player.physics.velocity + player.physics.acceleration + player.physics.gravity;
                player.position = player.position + Point { player.physics.velocity.x, player.physics.velocity.y, player.physics.velocity.z };
                
                if(player.position.y + player.image->getHeight() >= ground.position.y) {
                    player.position.y = ground.position.y - (player.image->getHeight());
                    player.physics.velocity.y *= -player.physics.elasticity;
                }
                if(player.position.x-1 < 0) {
                    player.position.x = 0;
                    player.physics.velocity.x *= -player.physics.elasticity;
                }
                if(player.position.x + player.image->getWidth() >= canvas.width) {
                    player.position.x = canvas.width - player.image->getWidth();
                    player.physics.velocity.x *= -player.physics.elasticity;
                }
                
                canvas.erase(prev_frame_player_position.x, prev_frame_player_position.y, prev_frame_player_position.x + player.image->getWidth()-1, prev_frame_player_position.y + player.image->getHeight()-1);
                
                sleep(100);
            }
        }
    } tg;

    tg.play();
}

void objectParty() {
    Canvas canvas;
    
    Object o[] {
        {"1"}, 
        {"2"},
        {"3"},
        {"4"},
        {"5"},
        {"6"},
        {"7"},
        {"8"},
        {"9"},
        {"10"},
        {"11"},
        {"12"},
        {"13"},
        {"14"},
        {"15"},
        {"16"},
    };

    for(Object& e : o) {
        e.image = new TextImage { "resource/o.txtimg" };
        
        e.position.x = getRandomInt(10, 20);
        e.position.y = getRandomInt(10, 20);
        
        e.physics.velocity = Vector { getRandomFloat(-5.0, 5.0), getRandomFloat(-5.0, 5.0), 0 };
        e.physics.gravity = Vector { 0, 1, 0 };
        e.physics.elasticity = 1;
    }
    
    Object ground { "ground" };
    ground.image = new TextImage { "resource/ground.txtimg" };
    ground.position.y = 30;

    Canvas grounds;
    for(int i=0; i<100; i+=ground.image->getWidth()) {
        grounds.draw(ground, Point(i, ground.position.y));
    }

    while(true) {
        canvas.draw(grounds);
        for(const Object& e : o) {
            canvas.draw(e);
        }
        println(canvas.getByString());

        for(Object& e : o) {
            Point prev_frame_position;
            
            e.update();

            if(e.position.y + e.image->getHeight() >= ground.position.y) {
                e.position.y = ground.position.y - (e.image->getHeight());
                e.physics.velocity.y *= -e.physics.elasticity;
            }
            if(e.position.x-1 < 0) {
                e.position.x = 0;
                e.physics.velocity.x *= -e.physics.elasticity;
            }
            if(e.position.x + e.image->getWidth() >= canvas.width) {
                e.position.x = canvas.width - e.image->getWidth();
                e.physics.velocity.x *= -e.physics.elasticity;
            }

            canvas.erase(prev_frame_position.x, prev_frame_position.y, prev_frame_position.x + e.image->getWidth()-1, prev_frame_position.y + e.image->getHeight()-1);
        }

        sleep(50);
    }
}

void test_Segment() {
    Canvas canvas;
    
    Segment s1 { Point(20, 20, 3), Vector(3, 2, 5) };
    Segment s2 { Point(20, 20, -2), Vector(1, -6, -10) };
    Segment s3 { Point(10, -20, -7), Vector(-6, -4, -10) };
    Segment s4 { Point(40, 30, 100), Vector(0, 0, 100) };
    Segment s5 { Point(40, 30, 100), Vector::crossProduct(s4.direction, s2.direction) };
    
    canvas.draw(s1);
    canvas.draw(s2);
    canvas.draw(s3);
    canvas.draw(s4);
    canvas.draw(s5);
    
    println(canvas.getByString());
    
    println("distance: " + to_string(s1.getDistanceTo(s2)));
    println("distance: " + to_string(Segment::getDistanceBetween(s1, s2)));
    println("is paraller: " + to_string(s1.isParallelTo(s3)));
    println("is paraller: " + to_string(Segment::isParallel(s1, s3)));
    println("scalar s2, s5: " + to_string(s2.direction * s5.direction));
}