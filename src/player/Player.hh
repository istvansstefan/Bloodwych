#pragma once

enum class Direction
{
    North,
    East,
    South,
    West
};

class Player
{
public:
    Player(int x, int y, Direction direction);

    int x() const;
    int y() const;

    Direction direction() const;

private:
    int x_;
    int y_;
    Direction direction_;
};
