#include <raylib.h>
#include <vector>
#include <iostream>
#include <math.h>
#include "ball.h"
#include "Player.h"
#include "cpu.h"
#include "Block.h"


int main()
{
    const int screen_w = 1000;
    const int screen_h = 600;
    bool isGameOver = false;
    
    int blockWidth = 50;
    int blockHeight = 30;
    int blockRowsNum = 5;
    int blockCountWidth = floor((screen_w-20)/(blockWidth+10));
    
start:
    std::vector<Block*> klocki;
    
    Ball ball = Ball(screen_w/2, screen_h/2, 8, -8, 10);
    
    for (int i = 0; i < blockRowsNum; i++) {
        int rowoffset = i*blockHeight + 10*(i+1) + 50;
        int margin = (screen_w - blockCountWidth*blockWidth - (blockCountWidth-1)*10)/2;
        for(int j = 0; j < blockCountWidth; j++){
           klocki.push_back(new Block(margin+(blockWidth+10)*j, rowoffset, blockHeight, blockWidth, i)); 
        }
    }

    Player player1;

    player1.setWidth(120);
    player1.setHeight(12.5);
    player1.setX(screen_w/2 - 60);
    player1.setY(screen_h - 40);
    player1.setSpeed(12);

    InitWindow(screen_w, screen_h, "Upobrejkalt");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        if (!isGameOver)
        {

            for(int i = 0; i < klocki.size();i++){
                Block* bl = klocki[i];
                if(CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{bl->getX(), bl->getY(), bl->getWidth(), bl->getHeight()})){
                    klocki.erase(klocki.begin()+i);
                    if(ball.getY() < bl->getY()+bl->getHeight() && ball.getY() > bl->getY() && !(ball.getX() < bl->getX()+bl->getWidth() && ball.getX() > bl->getX())){
                        ball.setSpeedX(ball.getSpeedX() *-1); 
                    }else if(ball.getX() < bl->getX()+bl->getWidth() && ball.getX() > bl->getX() && !(ball.getY() < bl->getY()+bl->getHeight() && ball.getY() > bl->getY())){
                        ball.setSpeedY(ball.getSpeedY() *-1); 
                    }else{
                        ball.setSpeedY(ball.getSpeedY() *-1);
                        ball.setSpeedX(ball.getSpeedX() *-1);  
                    }
                    player1.setScore(player1.getScore() +1);
                }
            }
            
            if (ball.getY() + ball.getRadius() >= GetScreenHeight())
            {
                if(player1.getLives() > 1)player1.setLives(player1.getLives() - 1);
                else {player1.setLives(0); isGameOver = true;}
                ball.Reset();
            }
            else if (CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), Rectangle{player1.getX(), player1.getY(), player1.getWidth(), player1.getHeight()})){
                if(ball.getY() < player1.getY()+player1.getHeight() && ball.getY() > player1.getY() && !(ball.getX() < player1.getX()+player1.getWidth() && ball.getX() > player1.getX())){ 
                    ball.setSpeedX((ball.getSpeedX() *-1));
                }else if(ball.getX() < player1.getX()+player1.getWidth() && ball.getX() > player1.getX() && !(ball.getY() < player1.getY()+player1.getHeight() && ball.getY() > player1.getY())){
                    ball.setSpeedY(ball.getSpeedY() *-1); 
                    if((ball.getY()-player1.getY())/player1.getWidth() < 0.33){
                        ball.setSpeedX(ball.getSpeedX() +2);
                    }else if((ball.getY()-player1.getY())/player1.getWidth() < 0.77){
                        ball.setSpeedX(ball.getSpeedX() -2);
                    }
                }else{
                    ball.setSpeedY(ball.getSpeedY() *-1);
                    ball.setSpeedX(ball.getSpeedX() *-1);  
                }
            }

            if(klocki.empty()){
                BeginDrawing();
                ClearBackground(BLACK);
                Player arr[1] = {player1};
                isGameOver = true;
                EndDrawing();
            }

            BeginDrawing();

            ClearBackground(BLACK);
            //przemieszczanie się kółka
            ball.Move();
            player1.Move();
            //rysuj kółko
            ball.Draw();
            //rysuj panele
            player1.Draw();
            
            for(Block* bl : klocki){
                bl->Draw();
            }
            
            if (IsKeyDown(KEY_SPACE))
            {                              
                ball.setStart(true);
            }

            DrawText(TextFormat("%i", player1.getScore()), 10, 10, 40, WHITE);
            DrawText(std::string(player1.getLives(), '*').c_str(), screen_w - 10 - MeasureText(std::string(player1.getLives(), '*').c_str(), 40), 10, 40, WHITE);
            DrawLine(0, 50, screen_w, 50, WHITE);

            EndDrawing();
        }   
        if (isGameOver || klocki.empty())
        {
            
            BeginDrawing();
            ClearBackground(BLACK);

            DrawText("Game Over", (screen_w - MeasureText("Game Over", 100))/2, ((screen_h - 100)/2)-200, 100, WHITE);
            DrawText(TextFormat("%i", player1.getScore()), (screen_w - MeasureText(TextFormat("%i", player1.getScore()), 70))/2, (screen_h - 70)/2, 70, WHITE);

            if (IsKeyDown(KEY_SPACE))
            {                              
                isGameOver = false;
                goto start;
            }

            EndDrawing();
        }
    }
    
    CloseWindow();
    return 0;
}
