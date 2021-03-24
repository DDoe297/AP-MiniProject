#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

namespace XnO
{
    class Player
    {
    private:
        std::string userName;

    public:
        Player(std::string username);
        void requestGame(Player &player, Board &board);
        void replayGame(Game &game);
        void play(Game &game, int point);
        std::string getUserName();
        ~Player();
    };

    Player::Player(std::string username)
    {
    }

    Player::~Player()
    {
    }

} // namespace XnO

#endif