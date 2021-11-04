#include "AOPExercises.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace aop
{
    unsigned long long int fakultaet()
    {
        unsigned short int userInp;
        unsigned long long int fak = 1;

        cout << "Gib die Zahl n ein deren Fakultät berechnet werden soll: " << endl;
        cin >> userInp;
        for (; userInp > 1; userInp--) fak *= userInp;
        cout << "Die Fakultät ist: " << fak << endl;

        return fak;
    }

    int multiplicationTable()
    {
        cout << "Multiplikationstabelle: " << endl;

        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 11; j++)
            {
                cout << setw(5) << i * j;
            }
            cout << endl;
        }
        return 0;
    }
}