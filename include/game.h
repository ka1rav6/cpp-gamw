#ifndef GAME_H
#define GAME_H
#pragma once


#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <cerrno>
#include <string>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

enum class State{
    PLAY, //0
    EXIT, //1
};

class Game{
public:
    Game();
    ~Game();
    
    void run();
    
    
private:
    void initSystems();
    void gameLoop();
    void processInput();
    SDL_Window *window;
    State state;
    void endrun();
    void drawGame();
    const int screenWidth = 1024;
    const int screenHeight = 768;
};









#endif  /* game.h*/