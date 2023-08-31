#include "../headers/GameBoard.h"
#include <iostream>

GameBoard::GameBoard(int _width, int _height) : width(_width), height(_height) {}

int GameBoard::getWidth() const
{
    return width;
}
int GameBoard::getHeight() const
{
    return height;
}

void GameBoard::draw(const Snake& snake, const Food& food) const
{
    system("cls"); //We clear the console screen with that command.
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
             if(x == 0 || x == width - 1 || y == 0 || y == height - 1)
                std::cout << "#"; // We are drawing the walls of our game that way.
             else if(x == snake.getHeadX() && y == snake.getHeadY())
                std::cout << "O"; //Snake' head
             else if(snake.isSnakeSegment(x, y))
                std::cout << "o"; //Snake's body
             else if(food.getX() == x && food.getY() == y)
                std::cout << "F"; // Draw food
             else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}