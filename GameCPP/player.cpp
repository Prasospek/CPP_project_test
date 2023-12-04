#include "player.h"
Player::Player()
{
    m_x = 5;
    m_y = 6;
}

int Player::getX()
{
    return m_x;
}

int Player::getY()
{
    return m_y;
}

void Player::setPosition(int newX, int newY)
{
    m_x = newX;
    m_y = newY;
    emit playerMoved();
}
