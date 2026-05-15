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

class Game{
public:
    Game();
    ~Game();
    
    void run();
    void initSystems();


private:
    SDL_Window *window;
    const int screenWidth = 1024;
    const int screenHeight = 768;
    
};









#endif  /* game.h*/