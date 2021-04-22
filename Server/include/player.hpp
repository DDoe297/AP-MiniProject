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
        void setRemainTime(int _time);
        int getRemainTime();
        int getName();
        ~Player();
    };
} // namespace XnO

#endif
