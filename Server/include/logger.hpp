#ifndef LOGGER_H
#define LOGGER_H

#define DEBUG_MODE false
class Log
{
public:
    Log(const std::string &funcName)
    {
        if (DEBUG_MODE)
        {
            std::cout << funcName << ": ";
        }
    }

    template <class T>
    Log &operator<<(const T &v)
    {
        if (DEBUG_MODE)
        {
            std::cout << v;
        }
        return *this;
    }

    ~Log()
    {
        if (DEBUG_MODE)
        {
            std::cout << "" << std::endl;
        }
    }
};

#define DEBUG Log(__FUNCTION__)

#endif