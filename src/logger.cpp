
#include <iostream>
#include "../include/logger.hpp"

namespace Debug
{
    Log::Log(const std::string &funcName)
    {
        if (DEBUG_MODE)
        {
            std::cout << funcName << ": ";
        }
    }

    template <class T>
    Log *Log::operator<<(const T &v)
    {
        if (DEBUG_MODE)
        {
            std::cout << v;
        }
        return this;
    }

    Log::~Log()
    {
        if (DEBUG_MODE)
        {
            std::cout << "" << std::endl;
        }
    }
}
