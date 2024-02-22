#include "Player.h"
#include <raylib.h>
#include <iostream>

Player::Player(){}

Player::Player(int posX, int posY, float width, float height, int speed){
    x = posX;
    y = posY;
    this->width = width;
    this->height = height;
    this->speed = speed;
}

void Player::Draw(){
    DrawRectangle(x ,y, width, height, WHITE);
}

void Player::Move(){
    if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)){
        x = x - speed;
    }
    if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)){
        x = x + speed;
    }
    if (x <= 0){
        x = 0;
    }
    if(x + width >= GetScreenWidth()){
        x = GetScreenWidth() - width;
    }
    
    
}

void Player::setX(float xx){
    x = xx;
}

void Player::setY(float yy){
    y = yy;
}

void Player::setHeight(float a){
    height = a;
}

void Player::setWidth(float a){
    width = a;
}

void Player::setSpeed(float a){
    speed = a;
}

void Player::setScore(int a){
    score = a;
}

void Player::setLives(int a){
    lives = a;
}

float Player::getX(){
    return x;
}

float Player::getY(){
    return y;
}

float Player::getHeight(){
    return height;
}

float Player::getWidth(){
    return width;
}

int Player::getSpeed(){
    return speed;
}

int Player::getScore(){
    return score;
}

int Player::getLives(){
    return lives;
}
