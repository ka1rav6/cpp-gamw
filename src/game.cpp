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

    this->initSystems();
    std::cout << "Systems Initialized" <<std::endl;
    
    // game starts

    gameLoop();
}

void Game::initSystems(){
    SDL_Init(SDL_INIT_EVERYTHING);


    //window initialization
    window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
    if (window == nullptr) 
        error("Window could not be created!");

    //context initialization
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (glContext == nullptr)
        error("GL Context could not be created");

    //glew initialization
    GLenum err = glewInit();
    if (err != GLEW_OK)
        error("Could not initialize GLEW");

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


    // set bg color
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
void Game::endrun(){
    SDL_Quit();
}

void Game::drawGame(){
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableClientState(GL_COLOR_ARRAY);

    //make triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 500);
    glVertex2f(500, 500);
    glEnd();


    SDL_GL_SwapWindow(window);
}


void Game::gameLoop(){
    while (this->state != State::EXIT){
        processInput();
        drawGame();
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