#include "../include/board.hpp"
#include <vector>

XnO::Board::Board(XnO::boardType _type)
{
    type = _type;
    size = (type == small) ? 9 : (type == medium) ? 16
                                                  : 21;
    for (int i = 0; i < size; i++)
    {
        tiles.push_back(0);
    }
}

char XnO::Board::getTile(int tile)
{
    return tiles[tile];
}

void XnO::Board::setTile(int tile, int player)
{
    tiles[tile] = player;
}
XnO::boardType XnO::Board::getType()
{
    return type;
}

std::vector<int> XnO::Board::getTiles()
{
    return tiles;
}

int XnO::Board::checkWinner()
{
    if (type == small)
    {
        if (tiles[1] == tiles[2] && tiles[2] == tiles[3])
        {
            return tiles[1];
        }
        if (tiles[4] == tiles[5] && tiles[5] == tiles[6])
        {
            return tiles[4];
        }
        if (tiles[7] == tiles[8] && tiles[8] == tiles[9])
        {
            return tiles[7];
        }
        //------
        if (tiles[1] == tiles[4] && tiles[4] == tiles[7])
        {
            return tiles[1];
        }
        if (tiles[2] == tiles[5] && tiles[5] == tiles[8])
        {
            return tiles[2];
        }
        if (tiles[3] == tiles[6] && tiles[6] == tiles[9])
        {
            return tiles[3];
        }
        return -1;
    }
    if (type == medium)
    {
        if (tiles[1] == tiles[2] && tiles[2] == tiles[3])
        {
            return tiles[1];
        }
        if (tiles[4] == tiles[5] && tiles[5] == tiles[6])
        {
            return tiles[4];
        }
        if (tiles[11] == tiles[12] && tiles[12] == tiles[13])
        {
            return tiles[11];
        }
        //------
        if (tiles[14] == tiles[15] && tiles[15] == tiles[16])
        {
            return tiles[14];
        }
        if (tiles[1] == tiles[7] && tiles[7] == tiles[14])
        {
            return tiles[1];
        }
        if (tiles[3] == tiles[10] && tiles[10] == tiles[16])
        {
            return tiles[3];
        }
        if (tiles[4] == tiles[8] && tiles[8] == tiles[11])
        {
            return tiles[4];
        }
        if (tiles[6] == tiles[9] && tiles[9] == tiles[13])
        {
            return tiles[6];
        }
        return -1;
    }
    if (type == big)
    {
        if (tiles[1] == tiles[2] && tiles[2] == tiles[3])
        {
            return tiles[1];
        }
        if (tiles[4] == tiles[5] && tiles[5] == tiles[6])
        {
            return tiles[4];
        }
        if (tiles[7] == tiles[8] && tiles[8] == tiles[9])
        {
            return tiles[7];
        }
        //--------
        if (tiles[10] == tiles[11] && tiles[11] == tiles[12])
        {
            return tiles[10];
        }
        if (tiles[13] == tiles[14] && tiles[14] == tiles[15])
        {
            return tiles[13];
        }
        if (tiles[1] == tiles[10] && tiles[10] == tiles[20])
        {
            return tiles[1];
        }
        // ----
        if (tiles[4] == tiles[11] && tiles[11] == tiles[18])
        {
            return tiles[4];
        }
        if (tiles[7] == tiles[12] && tiles[12] == tiles[16])
        {
            return tiles[7];
        }
        if (tiles[2] == tiles[5] && tiles[5] == tiles[8])
        {
            return tiles[2];
        }
        //---
        if (tiles[9] == tiles[13] && tiles[13] == tiles[17])
        {
            return tiles[9];
        }
        if (tiles[6] == tiles[14] && tiles[14] == tiles[19])
        {
            return tiles[6];
        }
        if (tiles[3] == tiles[15] && tiles[15] == tiles[21])
        {
            return tiles[3];
        }
        return -1;
    }
}