#include "../include/player.hpp"
#include "../include/game.hpp"

XnO::Player::Player(int c)
{
    name = c;
    remainTime = 40;
}

void XnO::Player::setRemainTime(int _time)
{
    remainTime = _time;
}

int XnO::Player::getRemainTime()
{
    return remainTime;
}

int XnO::Player::getName()
{
    return name;
}