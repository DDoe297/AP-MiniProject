#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>

void showGame(void)
{
    boost::asio::streambuf buff;
    boost::asio::read_until(sock, buff, "\n");
    reciveData = std::string(boost::asio::buffer_cast<const char *>(buff.data()));
    inputClient(reciveData);
    system("cls");
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
    std::cout << ">";
}

void getChoice(void)
{
    std::cin >> palyerChoice;
}
int main(void)
{
    std::thread getInput(getChoice);
    std::thread showOutput(showGame);
    return 0;
}