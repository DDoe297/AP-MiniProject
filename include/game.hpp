#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "./board.hpp"

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
        std::string player1;
        std::string player2;

        gameTurn turn;
        Board *board;

    public:
        Game(boardType type);
        gameTurn getTurn();
        void setTurn(gameTurn turn);
        ~Game();
    };

} // namespace XnO

#endif