#include "../include/IO.hpp"
bool validate(char data);
void showGame(void)
{
    inputClient(receiveDataSTR);
    clear();
    if (!winner)
    {
        std::cout << "Remaining Time:" << remainingTime << std::endl;
        if (errorMessage.length())
        {
            std::cout << errorMessage << std::endl;
        }
        switch (gameType)
        {
        case 1:
            showBoardOne(gameBase);
            break;
        case 2:
            showBoardTwo(gameBase);
            break;
        case 3:
            showBoardThree(gameBase);
            break;
        default:
            break;
        }
        if (turn == player)
        {
            std::cout << ">";
        }
        else
        {
            std::cout << "Not Your Turn" << std::endl;
        }
    }
    else
    {
        std::cout << "Player " << winner << " has won the game!" << std::endl;
    }
}
void getInput(void)
{
    if (gameType == 0 && player == 1)
    {
        std::cout << "What Type of board do you want?" << std::endl
                  << "1. Small:" << std::endl
                  << "A-B-C\n| | |\nD-E-F\n| | |\nG-H-I\n\n"
                  << "2. Medium:" << std::endl
                  << "A---B---C\n|   |   |\n| D-E-F |\n| |   | |\nG-H   I-J\n| |   | |\n| K-L-M |\n|   |   |\nN---O---P\n\n"
                  << "3. Big:" << std::endl
                  << "A-----B-----C\n|     |     |\n| D---E---F |\n| |   |   | |\n| | G-H-I | |\n| | |   | | |\nJ-K-L   M-N-O\n| | |   | | |\n| | P---Q | |\n| |/     \\| |\n| R-------S |\n| /       \\ |\nT-----------U\n\n";
        palyerChoice = std::getchar();
        sendDataSTR = outputClient(1, palyerChoice);
    }
    if (turn == player)
    {
        palyerChoice = std::getchar();
        if (validate(palyerChoice))
        {
            sendDataSTR = outputClient(2, palyerChoice);
            errorMessage = "";
        }
        else
        {
            errorMessage = "Invalid Data";
        }
    }
}