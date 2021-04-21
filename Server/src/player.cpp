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

void XnO::Player::play(XnO::Game &game, int point)
{
    game.board->setTile(point, name);
}