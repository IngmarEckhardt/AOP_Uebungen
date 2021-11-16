#include "AOPExercises.h"
#include "../connector.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace aop
{
    std::string factorial()
    {
        std::stringstream stringstream;
        std::string message = "Gib die Zahl n ein deren Fakultät berechnet werden soll: ";
        unsigned short int userInp = service::getUserInputInteger(message);

        stringstream << "Die Fakultät ist: " << service::getFactorial(userInp) << endl;

        return stringstream.str();
    }

    std::string multiplicationTable()
    {
        std::stringstream stringstream;
        stringstream << "Multiplikationstabelle: \n";

        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                stringstream << setw(5) << i * j;
            }
            stringstream << "\n";
        }
        return stringstream.str();
    }
}