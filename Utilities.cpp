#include "Utilities.h"
#include <cstdlib>

void Utilities::clearScreen()
{
    #if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined(__APPLE__)
    system("clear");
#endif
}