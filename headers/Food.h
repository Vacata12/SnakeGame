#pragma once

class Food
{
private:
    int x;
    int y;
public:
    Food(int _x, int _y);

    int getX() const;
    int getY() const;

    void respawn(int maxX, int maxY);
    bool isEaten(int snakeX, int snakeY) const;
};

