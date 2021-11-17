#include "AOPExercises.h"
#include "../connector.h"
#include <iostream>
#include <iomanip>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

//Functions
unsigned short int getMaxFactorial();

double getUserInput(std::string &message);

//constants
const unsigned long long int maxProduct{std::numeric_limits<unsigned long long int>::max()};
//maxProduct=18446744073709551615 (Win10/x86 64bit)


namespace aop
{
    std::string CosinusWithLoop()
    {
        double cosinus = 0;
        std::string messageCosinus = "Gib die Zahl (Bogenmaß) ein deren Cosinus mithilfe des Newton-Iterationsverfahrens bestimmt wird:\n";
        std::stringstream stringstream;

        unsigned short int maxN = getMaxFactorial();
        double userInput = getUserInput(messageCosinus);

        for (int i = 0; i <= maxN; i++)
        {
            cosinus += (std::pow((-1), i) * std::pow(userInput, 2 * i)) / service::getFactorial(2 * i);
        }

        stringstream << "cos(" << userInput << ") = " << cosinus << endl;
        return stringstream.str();
    }


    std::string SinusWithLoop()
    {
        double sinus = 0;
        std::string messageSinus = "Gib die Zahl (Bogenmaß) ein deren Sinus mithilfe des Newton-Iterationsverfahrens bestimmt wird:\n";
        std::stringstream stringstream;

        unsigned short int maxN = getMaxFactorial();
        double userInput = getUserInput(messageSinus);

        for (int i = 0; 2 * i <= (2 * maxN - 1); i++)
        {
            sinus += (std::pow((-1), i) * std::pow(userInput, (2 * i) + 1) / service::getFactorial((2 * i) + 1));
        }

        stringstream << "sin(" << userInput << ") = " << sinus << endl;
        return stringstream.str();
    }
}

double getUserInput(std::string &message)
{
    double userInput = service::getUserInputDouble(message);
    return service::ModuloPi(userInput);
}

unsigned short int getMaxFactorial()
{
    for (unsigned short int i = 1; i < 50; i++)
    {
        unsigned long long int factorial{service::getFactorial(i)};
        if ((maxProduct / (i + 1)) < factorial)
        {
            return i / 2;
        }
    }
    return 0;
}