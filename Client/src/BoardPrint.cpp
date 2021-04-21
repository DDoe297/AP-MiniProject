#include "../include/BoardPrint.hpp"
char printBoardHelper(int player, char boardChar)
{
    if (player == 1)
    {
        return '1';
    }
    else if (player == 2)
    {
        return '2';
    }
    else
    {
        return boardChar;
    }
}
void showBoardOne(std::vector<int> gameBase)
{
    std::cout
        << printBoardHelper(gameBase[0], 'A') << "-" << printBoardHelper(gameBase[1], 'B') << "-" << printBoardHelper(gameBase[2], 'C') << std::endl
        << "| | |" << std::endl
        << printBoardHelper(gameBase[3], 'D') << "-" << printBoardHelper(gameBase[4], 'E') << "-" << printBoardHelper(gameBase[5], 'F') << std::endl
        << "| | |" << std::endl
        << printBoardHelper(gameBase[6], 'G') << "-" << printBoardHelper(gameBase[7], 'H') << "-" << printBoardHelper(gameBase[8], 'I') << std::endl;
}
void showBoardTwo(std::vector<int> gameBase)
{
    std::cout
        << printBoardHelper(gameBase[0], 'A') << "---" << printBoardHelper(gameBase[1], 'B') << "---" << printBoardHelper(gameBase[2], 'C') << std::endl
        << "|   |   |" << std::endl
        << "| " << printBoardHelper(gameBase[3], 'D') << "-" << printBoardHelper(gameBase[4], 'E') << "-" << printBoardHelper(gameBase[5], 'F') << " |" << std::endl
        << "| |   | |" << std::endl
        << printBoardHelper(gameBase[6], 'G') << "-" << printBoardHelper(gameBase[7], 'H') << "   " << printBoardHelper(gameBase[8], 'I') << "-" << printBoardHelper(gameBase[9], 'J') << std::endl
        << "| |   | |" << std::endl
        << "| " << printBoardHelper(gameBase[10], 'K') << "-" << printBoardHelper(gameBase[11], 'L') << "-" << printBoardHelper(gameBase[12], 'M') << " |" << std::endl
        << "|   |   |" << std::endl
        << printBoardHelper(gameBase[13], 'N') << "---" << printBoardHelper(gameBase[14], 'O') << "---" << printBoardHelper(gameBase[15], 'P') << std::endl;
}
void showBoardThree(std::vector<int> gameBase)
{
    std::cout
        << printBoardHelper(gameBase[0], 'A') << "-----" << printBoardHelper(gameBase[1], 'B') << "-----" << printBoardHelper(gameBase[2], 'C') << std::endl
        << "|     |     |" << std::endl
        << "| " << printBoardHelper(gameBase[3], 'D') << "---" << printBoardHelper(gameBase[4], 'E') << "---" << printBoardHelper(gameBase[5], 'F') << " |" << std::endl
        << "| |   |   | |" << std::endl
        << "| | " << printBoardHelper(gameBase[6], 'G') << "-" << printBoardHelper(gameBase[7], 'H') << "-" << printBoardHelper(gameBase[8], 'I') << " | |" << std::endl
        << "| | |   | | |" << std::endl
        << printBoardHelper(gameBase[9], 'J') << "-" << printBoardHelper(gameBase[10], 'K') << "-" << printBoardHelper(gameBase[11], 'L') << "   " << printBoardHelper(gameBase[12], 'M') << "-" << printBoardHelper(gameBase[13], 'N') << "-" << printBoardHelper(gameBase[14], 'O') << std::endl
        << "| | |   | | |" << std::endl
        << "| | " << printBoardHelper(gameBase[15], 'P') << "---" << printBoardHelper(gameBase[16], 'Q') << " | |" << std::endl
        << "| |/     \\| |" << std::endl
        << "| " << printBoardHelper(gameBase[17], 'R') << "-------" << printBoardHelper(gameBase[18], 'S') << " |" << std::endl
        << "| /       \\ |" << std::endl
        << printBoardHelper(gameBase[19], 'T') << "-----------" << printBoardHelper(gameBase[20], 'U') << std::endl;
}