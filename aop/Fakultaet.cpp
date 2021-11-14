#include "AOPExercises.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace aop
{
    std::string fakultaet()
    {
        std::stringstream stringstream;
        unsigned short int userInp;
        unsigned long long int fak = 1;

        cout << "Gib die Zahl n ein deren Fakultät berechnet werden soll: " << endl;
        cin >> userInp;
        for (; userInp > 1; userInp--) fak *= userInp;
        stringstream << "Die Fakultät ist: " << fak << endl;

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