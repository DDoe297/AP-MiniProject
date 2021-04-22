#ifndef GLOBAL_VARS_HPP
#define GLOBAL_VARS_HPP

#include <vector>
#include <iostream>
#include <mutex>

extern int player, gameType, turn, remainingTime, winner;
extern std::string errorMessage;
extern std::vector<int> gameBase;
extern std::mutex varLock;

#endif