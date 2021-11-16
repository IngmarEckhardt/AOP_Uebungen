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
unsigned short int getMaxFactorialCosinus();
unsigned short int getMaxFactorialSinus();
double ModuloPi(double input);

//constants
const unsigned long long int maxProduct {std::numeric_limits<unsigned long long int>::max()};
//maxProduct=18446744073709551615 (Win10/x86 64bit)


namespace aop
{
    std::string CosinusWithLoop()
    {
        double cosinus = 0;
        std::string messageCosinus = "Gib die Zahl (Bogenmaß) ein deren Cosinus mithilfe des Newton-Iterationsverfahrens bestimmt wird:";
        std::stringstream stringstream;

        unsigned short int maxN{getMaxFactorialCosinus()};
        double userInput = service::getUserInputDouble(messageCosinus);
        userInput = ModuloPi(userInput);

        for (int i = 0; i <=maxN; i++)
        {
            cosinus += (std::pow((-1),i) * std::pow(userInput, 2*i)) / service::getFactorial(2*i);
        }

        stringstream << "cos(" << userInput << ") = " << cosinus << endl;
        return stringstream.str();
    }


    std::string SinusWithLoop()
    {
        double sinus = 0;
        std::string messageSinus = "Gib die Zahl (Bogenmaß) ein deren Sinus mithilfe des Newton-Iterationsverfahrens bestimmt wird:";
        std::stringstream stringstream;

        unsigned short int maxN{getMaxFactorialSinus()};
        double userInput = service::getUserInputDouble(messageSinus);
        userInput = ModuloPi(userInput);

        for (int i = 0; i <=maxN; i++)
        {
            sinus += (std::pow((-1),i) * std::pow(userInput, (2*i)+1) / service::getFactorial((2*i)+1));
        }

        stringstream << "sin(" << userInput << ") = " << sinus << endl;
        return stringstream.str();
    }
}

unsigned short int getMaxFactorialCosinus()
{
    for (unsigned short int i = 1; i < 50; i++)
    {
        unsigned long long int factorial{service::getFactorial(i)};
        if ((maxProduct / (i+1)) < factorial)
        {
            return i/2;
        }
    }
    return 0;
}
unsigned short int getMaxFactorialSinus()
{
    for (unsigned short int i = 1; i < 50; i++)
    {
        unsigned long long int factorial{service::getFactorial(i)};
        if ((maxProduct / (i+1)) < factorial) return (i-1)/2;
    }
    return 0;
}

double ModuloPi(double input) {
    if (input > (2 * M_PI))
    {
        return ModuloPi(input - (2 * M_PI));
    }
    return input;
}