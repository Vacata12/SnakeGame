#pragma once
#include <vector>

enum Direction {UP, DOWN, LEFT, RIGHT};

class Snake
{
private:
    struct Segment
    {
        int x;
        int y;
        Segment(int _x, int _y) : x(_x), y(_y) {}
    };

    std::vector<Segment> body;
    Direction direction;
    bool isAlive;
public:
    Snake(int startX, int startY);

    bool isSnakeSegment(int x, int y) const;
    void move();
    void changeDirection(Direction newDirection);
    void grow();
    bool checkCollision(int width, int height);
    bool isDead() const;
    int getHeadX() const;
    int getHeadY() const;
};

