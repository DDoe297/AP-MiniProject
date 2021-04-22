#include "../include/DataParser.hpp"
#include "../include/GlobalVars.hpp"
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
        varLock.lock();
        player = stoi(token);
        varLock.unlock();
    }
    else if (dType == 2)
    {
        varLock.lock();
        gameBase.clear();
        varLock.unlock();
        std::getline(split, token, '-');
        varLock.lock();
        gameType = std::stoi(token);
        varLock.unlock();
        std::getline(split, token, '-');
        std::istringstream base(token);
        std::string point;
        while (std::getline(base, point, ','))
        {
            varLock.lock();
            gameBase.push_back(stoi(point));
            varLock.unlock();
        }
        std::getline(split, token, '-');
        varLock.lock();
        turn = std::stoi(token);
        varLock.unlock();
        std::getline(split, token, '-');
        varLock.lock();
        remainingTime = std::stoi(token);
        varLock.unlock();
    }
    else if (dType == 3)
    {
        std::getline(split, token, ':');
        varLock.lock();
        winner = stoi(token);
        varLock.unlock();
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