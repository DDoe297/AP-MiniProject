#ifndef CLIENT_DATA_PARSER_HPP
#define CLIENT_DATA_PARSER_HPP

#include <vector>
#include <sstream>
#include <string>
#include "GlobalVars.hpp"

void inputClient(std::string input);
std::string outputClient(int messageType, int message);

#endif