#include "../include/IO.hpp"
#include "../include/logger.hpp"
void showGame(std::string receiveDataSTR)
{
    inputClient(receiveDataSTR);
    clear();
    if (!winner)
    {
        std::cout << "\e[1;33Remaining Time:" << remainingTime << "\e[1;37m" << std::endl;
        if (errorMessage.length())
        {
            std::cout << "\e[0;31m" << errorMessage << "\e[1;37m" << std::endl;
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
            std::cout << "\e[1;33m>\e[1;37m" << std::endl;
        }
        else
        {
            std::cout << "\e[1;33mNot Your Turn\e[1;37m" << std::endl;
        }
    }
    else
    {
        std::cout << "\e[0;35mPlayer " << winner << " has won the game!\e[1;37m" << std::endl;
    }
}
bool getInput(std::string &sendDataSTR)
{
    bool dataSend = false;
    char palyerChoice = 0;
    std::cin >> palyerChoice;
    if (turn == player)
    {
        palyerChoice = tolower(palyerChoice);
        palyerChoice -= 'a';
        if (validate(palyerChoice))
        {
            dataSend = true;
            sendDataSTR = outputClient(2, palyerChoice);
            varLock.lock();
            errorMessage = "";
            varLock.unlock();
        }
        else
        {
            varLock.lock();
            errorMessage = "Invalid Data";
            varLock.unlock();
        }
    }

    return dataSend;
}
bool validate(char data)
{
    if (turn == player)
    {
        if (gameType == 1)
        {
            return (data >= 0 && data <= 8 && !gameBase[data]);
        }
        else if (gameType == 2)
        {
            return (data >= 0 && data <= 15 && !gameBase[data]);
        }
        else if (gameType == 3)
        {
            return (data >= 0 && data <= 20 && !gameBase[data]);
        }
    }

    return false;
}