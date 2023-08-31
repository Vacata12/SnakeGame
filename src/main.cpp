#include <iostream>
#include <conio.h>
#include<windows.h>
#include "../headers/GameBoard.h"

int main()
{
    Snake snake(2, 2);
    Food food(4, 2);
    GameBoard gameBoard(20, 20); 

    while(!snake.isDead())
    {
        if(_kbhit())
        {
            char key = _getch();
            switch (key)
            {
                case 'w':
                    snake.changeDirection(UP);
                    break;
                case 's':
                    snake.changeDirection(DOWN);
                    break;
                case 'a':
                    snake.changeDirection(LEFT);
                    break;
                case 'd':
                    snake.changeDirection(RIGHT);
                    break;
            }
            
        }
        snake.move();

        if(snake.checkCollision(gameBoard.getWidth(), gameBoard.getHeight()))
            break;
        
        if(food.isEaten(snake.getHeadX(), snake.getHeadY()))
        {
            snake.grow();
            food.respawn(gameBoard.getWidth(), gameBoard.getHeight());
        }

        gameBoard.draw(snake, food);
        Sleep(100);
    }
    return 0;
}