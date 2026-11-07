#include "Player.hh"

Player::Player(int x, int y, Direction direction)
    : x_(x),
      y_(y),
      direction_(direction)
{
}

int Player::x() const
{
    return x_;
}

int Player::y() const
{
    return y_;
}

Direction Player::direction() const
{
    return direction_;
}
