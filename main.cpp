#include <iostream>
#include <iomanip>
#include "connector.h"

#ifdef _WIN32

#include <Windows.h>

#define mSetConsoleOutputCP(x) SetConsoleOutputCP(x)
#else
#define mSetConsoleOutputCP(x) 
#endif // _WIN32


int main()
{
    mSetConsoleOutputCP(CP_UTF8);
    global::Menu();
}
