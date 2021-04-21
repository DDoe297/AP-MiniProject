#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "./game.hpp"
namespace XnO
{
    class Player
    {
    private:
        int name;
        int remainTime;

    public:
        Player(int c);
        void play(Game &game, int point);
        void setRemainTime(int _time);
        int getRemainTime();
        ~Player();
    };
} // namespace XnO

#endif
