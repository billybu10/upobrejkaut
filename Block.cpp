#include "Block.h"
#include <raylib.h>

Block::Block(float posX, float posY, int iheight, int iwidth, int color){
    x = posX;
    y = posY;
    height = iheight;
    width = iwidth;
    switch(color){
    case 0:
        colorek = PINK;
        break;
    case 1:
        colorek = RED;
        break;
    case 2:
        colorek = ORANGE;
        break;
    case 3:
        colorek = YELLOW;
        break;
    case 4:
        colorek = GREEN;
        break;
    case 5:
        colorek = BLUE;
        break;
    case 6:
        colorek = PURPLE;
        break;
    default:
        colorek = WHITE;
    }
}

void Block::Draw(){
    DrawRectangle(x, y, width, height, colorek);
}

void Block::setX(float xx){
    x = xx;
}

void Block::setY(float yy){
    y = yy;
}

void Block::setHeight(int a){
    height = a;
}

void Block::setWidth(int a){
    width = a;
}


float Block::getX(){
    return x;
}

float Block::getY(){
    return y;
}

int Block::getHeight(){
    return height;
}

int Block::getWidth(){
    return width;
}
