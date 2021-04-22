#include "../include/board.hpp"
#include "../include/game.hpp"

XnO::Game::Game(boardType type)
{
    turn = Player1;
    board = new Board(type);
    player1 = new Player(1);
    player2 = new Player(2);
}

XnO::gameTurn XnO::Game::getTurn()
{
    return turn;
}

void XnO::Game::setTurn(XnO::gameTurn turn)
{
    turn = turn;
}
void XnO::Game::play(int point)
{
    board->setTile(point, (turn == Player1) ? player1->getName() : player2->getName());
    turn = (turn == Player1) ? Player2 : Player1;
}

XnO::Game::~Game()
{
}
