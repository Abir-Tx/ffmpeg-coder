#if !defined(UTILS_H)
#define UTILS_H

#include <iostream>

//A function for clearing screen (Cross Platform)
void clear_screen()
{
#ifdef _WIN32
    // do something for windows like include <windows.h>
    system("cls");
#elif defined __unix__
    // do something for unix like include <unistd.h>
    system("clear");
#endif
}

#endif // UTILS_H
