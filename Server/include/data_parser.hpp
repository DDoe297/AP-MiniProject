#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
std::string outputServer(int gameType, std::vector<int> gameBase, int turn, int remainingTime);
std::string outputServer(int messageType, int message);
void inputServer(std::string input);
#endif