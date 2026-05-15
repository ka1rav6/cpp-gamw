#ifndef SPRITE_H
#define SPRITE_H
#pragma once

class Sprite{
public:
    Sprite();
    ~Sprite();

    void init(int x, int y, int width, int height);
    void draw();

private:
    int x;
    int y;
    int width;
    int height;

};



#endif