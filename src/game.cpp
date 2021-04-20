#include "../include/board.hpp"
#include "../include/game.hpp"

XnO::Game::Game(boardType type)
{
    turn = Player1;
    board = new Board(type);
}

XnO::gameTurn XnO::Game::getTurn()
{
    return turn;
}

void XnO::Game::setTurn(XnO::gameTurn turn)
{
    turn = turn;
}