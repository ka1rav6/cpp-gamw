#include "../include/game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>


void error(std::string msg){

    std::cout << msg <<std::endl;
    SDL_Quit();

}

Game::Game(){
    window = nullptr;
    this->state = State::PLAY;
}

Game::~Game(){}

void Game::run(){
    std::cout << "Game has started running" <<std::endl;
    this->initSystems();
    std::cout << "Systems Initialized" <<std::endl;
    
    SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
    std::cout << "Window Created" <<std::endl;

    gameLoop();
}

void Game::initSystems(){
    SDL_Init(SDL_INIT_EVERYTHING);
}
void Game::endrun(){
    SDL_Quit();
}

void Game::gameLoop(){
    while (this->state != State::EXIT){
        processInput();
    }
    endrun();
}
void Game::processInput(){
    SDL_Event event;
    while(SDL_PollEvent(&event) == true){
        switch (event.type){
            case SDL_QUIT:
                this->state = State::EXIT;
                break;
            case SDL_MOUSEMOTION:
                std::cout << event.motion.x << " ";
                std::cout << event.motion.y << std::endl;
                break;
            default: break;

        }

    }

}