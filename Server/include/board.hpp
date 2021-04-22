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
        std::vector<int> tiles;
        int size;

    public:
        Board(boardType _type);
        void setTile(int tile, int player);
        char getTile(int tile);
        boardType getType(); 
        std::vector<int> getTiles();
        int char2player(char c);
        int checkWinner();
        ~Board();
    };

} // namespace XnO

#endif