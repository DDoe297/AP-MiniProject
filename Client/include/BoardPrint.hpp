#ifndef BOARD_PRINT_HPP
#define BOARD_PRINT_HPP

#include <vector>
#include <iostream>

char printBoardHelper(int player, char boardChar);
void showBoardOne(std::vector<int> gameBase);
void showBoardTwo(std::vector<int> gameBase);
void showBoardThree(std::vector<int> gameBase);

#endif