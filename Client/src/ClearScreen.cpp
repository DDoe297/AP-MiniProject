#include "../include/ClearScreen.hpp"
void clear(void)
{
    if (OS == "unix")
    {
        std::system("clear");
    }
    else
    {
        std::system("cls");
    }
}