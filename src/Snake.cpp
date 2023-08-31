#include "../headers/Snake.h"

Snake::Snake(int startX, int startY)
{
    body.push_back(Segment(startX, startY));
    direction = RIGHT;
    isAlive = true;
}

bool Snake::isSnakeSegment(int x, int y) const
{
    for(const Segment& segment : body)
    {
        if(segment.x == x && segment.y == y)
            return true;
    }
    return false;
}
void Snake::move()
{
    //Move the snake's body parts/segments
    for (unsigned i = body.size() - 1; i > 0; i--)
    {
        body[i] = body[i - 1];
    }

    //Move head direction
    Segment& head = body[0];
    switch (direction)
    {
    case UP:
        --head.y;
        break;
    case DOWN:
        ++head.y;
        break;
    case LEFT:
        --head.x;
        break;
    case RIGHT:
        ++head.x;
        break;
    }
}
void Snake::changeDirection(Direction newDirection)
{
    //This long if avoids player move in opposite direction
    if((newDirection == UP && direction != DOWN) ||
        (newDirection == DOWN && direction != UP) ||
        (newDirection == RIGHT && direction != LEFT) ||
        (newDirection == LEFT && direction != RIGHT))
        direction = newDirection;
}
void Snake::grow()
{
    const Segment& tail = body.back();
    body.push_back(Segment(tail.x, tail.y));
}
bool Snake::checkCollision(int width, int height)
{
    const Segment& head = body[0];

    //Check for collisions with walls
    if(head.x <= 0 || head.x >= width - 1 || head.y <= 0 || head.y >= height - 1)
    {
        isAlive - false;
        return true;
    }

    //Checks for collisions with itself
    for(int i = 1; i < body.size(); i++)
    {
        if(head.x == body[i].x && head.y == body[i].y)
        {
            isAlive = false;
            return true;
        }
    }
    return false;
}
bool Snake::isDead() const
{
    return !isAlive;
}
int Snake::getHeadX() const
{
    return body[0].x;
}
int Snake::getHeadY() const
{
    return body[0].y;
}