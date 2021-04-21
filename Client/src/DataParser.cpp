#include "../include/DataParser.hpp"
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
std::string outputClient(int messageType, int message)
{
    if (messageType == 1)
    {
        std::stringstream stringStream;
        stringStream << "1:" << message;
        return stringStream.str();
    }
    else if (messageType == 2)
    {
        std::stringstream stringStream;
        stringStream << "2:" << message;
        return stringStream.str();
    }
    else
    {
        return NULL;
    }
}