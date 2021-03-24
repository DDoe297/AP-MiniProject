#ifndef GAME_H
#define GAME_H
#include "./player.hpp"
#include "./board.hpp"

namespace XnO
{
    enum gameStatus
    {
        Waiting,
        Playing,
        Rejected
    };

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
        gameStatus status;
        gameTurn trun;
        Board board;

    public:
        Game(Player &_player1, Player &_player2, Board &_board);
        gameTurn getTurn();
        void setTurn(gameTurn);
        gameStatus getStatus();
        void setStatus(gameStatus);
        Player *getPlayer(int number);
        ~Game();
    };

    Game::Game(Player &_player1, Player &_player2, Board &_board)
    {
    }

    Game::~Game()
    {
    }

} // namespace XnO

#endif