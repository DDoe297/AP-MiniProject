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
    tiles[tile] = (player == 1) ? '*' : 'O';
}

int XnO::Board::char2player(char c)
{
    return (c == '*') ? 1 : 2;
}

int XnO::Board::checkWinner()
{
    int winner;
    if (type == small)
    {
        if (tiles[1] == tiles[2] && tiles[2] == tiles[3])
        {
            return char2player(tiles[1]);
        }
        if (tiles[4] == tiles[5] && tiles[5] == tiles[6])
        {
            return char2player(tiles[4]);
        }
        if (tiles[7] == tiles[8] && tiles[8] == tiles[9])
        {
            return char2player(tiles[7]);
        }
        //------
        if (tiles[1] == tiles[4] && tiles[4] == tiles[7])
        {
            return char2player(tiles[1]);
        }
        if (tiles[2] == tiles[5] && tiles[5] == tiles[8])
        {
            return char2player(tiles[2]);
        }
        if (tiles[3] == tiles[6] && tiles[6] == tiles[9])
        {
            return char2player(tiles[3]);
        }
        return -1;
    }
    if (type == medium)
    {
        if (tiles[1] == tiles[2] && tiles[2] == tiles[3])
        {
            return char2player(tiles[1]);
        }
        if (tiles[4] == tiles[5] && tiles[5] == tiles[6])
        {
            return char2player(tiles[4]);
        }
        if (tiles[11] == tiles[12] && tiles[12] == tiles[13])
        {
            return char2player(tiles[11]);
        }
        //------
        if (tiles[14] == tiles[15] && tiles[15] == tiles[16])
        {
            return char2player(tiles[14]);
        }
        if (tiles[1] == tiles[7] && tiles[7] == tiles[14])
        {
            return char2player(tiles[1]);
        }
        if (tiles[3] == tiles[10] && tiles[10] == tiles[16])
        {
            return char2player(tiles[3]);
        }
        if (tiles[4] == tiles[8] && tiles[8] == tiles[11])
        {
            return char2player(tiles[4]);
        }
        if (tiles[6] == tiles[9] && tiles[9] == tiles[13])
        {
            return char2player(tiles[6]);
        }
        return -1;
    }
    if (type == big)
    {
        if (tiles[1] == tiles[2] && tiles[2] == tiles[3])
        {
            return char2player(tiles[1]);
        }
        if (tiles[4] == tiles[5] && tiles[5] == tiles[6])
        {
            return char2player(tiles[4]);
        }
        if (tiles[7] == tiles[8] && tiles[8] == tiles[9])
        {
            return char2player(tiles[7]);
        }
        //--------
        if (tiles[10] == tiles[11] && tiles[11] == tiles[12])
        {
            return char2player(tiles[10]);
        }
        if (tiles[13] == tiles[14] && tiles[14] == tiles[15])
        {
            return char2player(tiles[13]);
        }
        if (tiles[1] == tiles[10] && tiles[10] == tiles[20])
        {
            return char2player(tiles[1]);
        }
        // ----
        if (tiles[4] == tiles[11] && tiles[11] == tiles[18])
        {
            return char2player(tiles[4]);
        }
        if (tiles[7] == tiles[12] && tiles[12] == tiles[16])
        {
            return char2player(tiles[7]);
        }
        if (tiles[2] == tiles[5] && tiles[5] == tiles[8])
        {
            return char2player(tiles[2]);
        }
        //---
        if (tiles[9] == tiles[13] && tiles[13] == tiles[17])
        {
            return char2player(tiles[9]);
        }
        if (tiles[6] == tiles[14] && tiles[14] == tiles[19])
        {
            return char2player(tiles[6]);
        }
        if (tiles[3] == tiles[15] && tiles[15] == tiles[21])
        {
            return char2player(tiles[3]);
        }
        return -1;
    }
}