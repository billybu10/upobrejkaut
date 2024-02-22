#pragma once
#include <raylib.h>

class Block
{
    private:
        float x, y;
        int width, height;
        Color colorek;
    public:
        Block(float posX, float posY, int iheight, int iwidth, int color);

        //rysuj
        void Draw();

        //gettery i settery
        void setX(float xx);
        void setY(float yy);
        void setHeight(int a);
        void setWidth(int a);

        float getX();
        float getY();
        int getHeight();
        int getWidth();

};
