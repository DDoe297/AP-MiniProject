#include <iostream>
#include <sstream>
#include <string>
#include <vector>
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
void inputClient(std::string input)
{
    std::istringstream split(input);
    std::string token;
    std::getline(split, token, ':');
    int dType;
    dType = std::stoi(token);
    if (dType == 1)
    {
        int turn;
        std::getline(split, token, ':');
        turn = stoi(token);
    }
    else if (dType == 2)
    {
        int gameType, turn, remainingTime;
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
        int winner;
        std::getline(split, token, ':');
        winner = stoi(token);
    }
}
void inputServer(std::string input)
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
    }
    else if (dType == 2)
    {
        int place;
        std::getline(split, token, ':');
        place = stoi(token);
    }
}
int main(void)
{
    return 0;
}
