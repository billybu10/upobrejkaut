#include <raylib.h>
#include "cpu.h"

void Cpu::Update(int ball_x){
    if (getX() + getWidth()/2 > ball_x)
    {
        setX(getX() - getSpeed());
    }
    if (getX() + getWidth()/2 <= ball_x)
    {
        setX(getX() + getSpeed());
    }
    
}
