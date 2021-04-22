#include "../include/GlobalVars.hpp"

int player = 0, gameType = 0, turn = 1, remainingTime = 0, winner = 0;
std::string errorMessage;
std::vector<int> gameBase;
std::mutex varLock;
