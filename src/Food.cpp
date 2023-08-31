#include "../headers/Food.h"
#include <cstdlib>

Food::Food(int _x, int _y) : x(_x), y(_y) {}

int Food::getX() const
{
    return x;
}
int Food::getY() const
{
    return y;
}

void Food::respawn(int maxX, int maxY)
{
    x = rand() % (maxX - 2) + 1;
    y = rand() % (maxY - 2) + 1;
}
bool Food::isEaten(int snakeX, int snakeY) const
{
    return snakeX == x && snakeY == y;
}