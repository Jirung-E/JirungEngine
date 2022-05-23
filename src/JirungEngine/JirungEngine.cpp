#include "JirungEngine.hpp"

using namespace std;
using namespace JirungEngine;


Game::Game(const Canvas& canvas) : canvas { canvas.width, canvas.height } {
    
}

Game::Game() : Game { Canvas() } {
    
}