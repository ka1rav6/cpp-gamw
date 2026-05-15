#include "../include/game.h"



int main(int argc, char** argv){
    Game game;
    game.run();    

    // just to make the window hold:
    int a = 0;
    std::cin >> a;
    return 0;
}