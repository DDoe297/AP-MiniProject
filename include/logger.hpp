#ifndef LOGGER_H
#define LOGGER_H

#define DEBUG_MODE true

namespace Debug
{

    class Log
    {
    public:
        Log(const std::string &funcName);

        template <class T> 
        Log *operator<<(const T &v);

        ~Log();
    };

}
#define DEBUG Log(__FUNCTION__)
#endif