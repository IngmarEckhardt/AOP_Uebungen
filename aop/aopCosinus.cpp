#include "AOPExercises.h"
#include "../connector.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
//Functions
unsigned short int getMaxN();
unsigned short int getMaxNSinus();
double getUserInputDouble(std::string &message);
double getSmallerInput(double input);

//constants
std::string messageCosinus {"Gib die Zahl (Bogenmaß) ein deren Cosinus mithilfe des Newton-Iterationsverfahrens bestimmt wird:"};
std::string messageSinus {"Gib die Zahl (Bogenmaß) ein deren Sinus mithilfe des Newton-Iterationsverfahrens bestimmt wird:"};
const unsigned long long int maxProduct {std::numeric_limits<unsigned long long int>::max()};
//maxProduct=18446744073709551615 (Win10/x86 64bit)


namespace aop
{
    std::string CosinusWithLoop()
    {
        double cosinus = 0;
        std::stringstream stringstream;

        unsigned short int maxN{getMaxN()};
        double userInput{getUserInputDouble(messageCosinus)};
        userInput = getSmallerInput(userInput);

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
        std::stringstream stringstream;

        unsigned short int maxN{getMaxNSinus()};
        double userInput{getUserInputDouble(messageSinus)};
        userInput = getSmallerInput(userInput);

        for (int i = 0; i <=maxN; i++)
        {
            sinus += (std::pow((-1),i) * std::pow(userInput, (2*i)+1) / service::getFactorial((2*i)+1));
        }

        stringstream << "cos(" << userInput << ") = " << sinus << endl;
        return stringstream.str();
    }
}

unsigned short int getMaxN()
{
    for (unsigned short int i = 1; i < 50; i++)
    {
        unsigned long long int factorial{service::getFactorial(i)};
        if ((maxProduct / (i+1)) < factorial) return i/2;
    }
    return 0;
}
unsigned short int getMaxNSinus()
{
    for (unsigned short int i = 1; i < 50; i++)
    {
        unsigned long long int factorial{service::getFactorial(i)};
        if ((maxProduct / (i+1)) < factorial) return (i-1)/2;
    }
    return 0;
}

double getUserInputDouble(std::string &message)
{
    std::string input;
    do
    {
        cout << message << "\n(nur Zahlen eingeben, Dezimaltrennung mit Punkt) "<< endl;
        cin >> input;
    }
    while (!service::isStringADouble(input));
    return std::stod(input);
}
double getSmallerInput(double input) {
    if (input > (2 * M_PI)) return getSmallerInput(input - (2 * M_PI));
    return input;
}