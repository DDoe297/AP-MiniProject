#include "../include/data_parser.hpp"
int inputServer(std::string input)
{
    std::istringstream split(input);
    std::string token;
    std::getline(split, token, ':');
    int dType;
    dType = std::stoi(token);
    if (dType == 1)
    {
        int gameType;
        std::getline(split, token, ':');
        gameType = stoi(token);
        return gameType;
    }
    else if (dType == 2)
    {
        int place;
        std::getline(split, token, ':');
        place = stoi(token);
        return place;
    }
}
std::string outputServer(int gameType, std::vector<int> gameBase, int turn, int remainingTime)
{
    std::stringstream stringStream;
    stringStream << "2:" << gameType << "-";
    for (int i = 0; i < gameBase.size() - 1; i++)
    {
        stringStream << gameBase[i] << ",";
    }
    stringStream << gameBase[gameBase.size() - 1] << "-";
    stringStream << turn << "-" << remainingTime << "\n";
    return stringStream.str();
}
std::string outputServer(int messageType, int message)
{
    if (messageType == 1)
    {
        std::stringstream stringStream;
        stringStream << "1:" << message;
        return stringStream.str();
    }
    else if (messageType == 3)
    {
        std::stringstream stringStream;
        stringStream << "3:" << message;
        return stringStream.str();
    }
    else
    {
        return NULL;
    }
}