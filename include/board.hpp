#ifndef BOARD_H
#define BOARD_H
#include <vector>

namespace XnO
{
    enum boardType
    {
        small,
        medium,
        big
    };
    class Board
    {
    private:
        boardType type;
        std::vector<char> tiles;
        int size;

    public:
        Board(boardType type);
        void setTile(int tile, int player);
        void getTile(int tile);

        int checkWinner();
        ~Board();
    };

    Board::Board(boardType type)
    {
    }

    Board::~Board()
    {
    }

} // namespace XnO

#endif