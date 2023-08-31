#pragma once
#include "../headers/Snake.h"
#include "../headers/Food.h"

class GameBoard
{
private:
    int width;
    int height;
public:
    GameBoard(int _width, int _height);
    ~GameBoard() = default;

    int getWidth() const;
    int getHeight() const;

    void draw(const Snake& snake, const Food& food) const;
};