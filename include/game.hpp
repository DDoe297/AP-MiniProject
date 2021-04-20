#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "./board.hpp"
#include "./player.hpp"

namespace XnO
{
    enum gameTurn
    {
        Player1,
        Player2
    };

    class Game
    {
    private:
        Player *player1;
        Player *player2;
        gameTurn turn;

    public:
        Board *board;
        Game(boardType type);
        gameTurn getTurn();
        void setTurn(gameTurn turn);
        void play(int point);
        ~Game();
    };

} // namespace XnO

#endif