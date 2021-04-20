#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
int player, gameType, turn, remainingTime, winner, lastMessageType;
char palyerChoice;
std::string reciveData, sendData, errorMessage;
std::vector<int> gameBase;
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
void inputClient(std::string input)
{
    std::istringstream split(input);
    std::string token;
    std::getline(split, token, ':');
    int dType;
    dType = std::stoi(token);
    if (dType == 1)
    {
        std::getline(split, token, ':');
        player = stoi(token);
    }
    else if (dType == 2)
    {
        std::vector<int> gameBase;
        std::getline(split, token, '-');
        gameType = std::stoi(token);
        std::getline(split, token, '-');
        std::istringstream base(token);
        std::string point;
        while (std::getline(base, point, ','))
        {
            gameBase.push_back(stoi(point));
        }
        std::getline(split, token, '-');
        turn = std::stoi(token);
        std::getline(split, token, '-');
        remainingTime = std::stoi(token);
    }
    else if (dType == 3)
    {
        std::getline(split, token, ':');
        winner = stoi(token);
    }
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