#ifndef CLEAR_SCREEN_HPP
#define CLEAR_SCREEN_HPP

#include <iostream>

void clear(void);

#endif

#ifdef __unix__
#define OS "unix"
#else
#define OS "windows"
#endif