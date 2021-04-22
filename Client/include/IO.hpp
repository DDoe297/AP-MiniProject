#ifndef IO_HPP
#define IO_HPP

#include "iostream"
#include "istream"
#include "GlobalVars.hpp"
#include "BoardPrint.hpp"
#include "ClearScreen.hpp"
#include "DataParser.hpp"

bool validate(char data);
bool getInput(std::string &sendDataSTR);
void showGame(std::string receiveDataSTR);
#endif