#ifndef GLOBAL_VARS_HPP
#define GLOBAL_VARS_HPP

#include <vector>
#include <iostream>
#include <mutex>

int player = 0, gameType = 0, turn = 0, remainingTime = 0, winner = 0;
std::string errorMessage;
std::vector<int> gameBase;
std::mutex varLock;

#endif