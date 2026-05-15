#include "../include/game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>


Game::Game(){
    window = nullptr;


}
Game::~Game(){}
void Game::run(){
    this->initSystems();

    SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
}

void Game::initSystems(){
    SDL_Init(SDL_INIT_EVERYTHING);
}
