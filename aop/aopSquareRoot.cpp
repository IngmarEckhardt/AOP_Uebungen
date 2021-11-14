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
    std::string squareRoot()
    {
        std::stringstream stringstream;
        std::string input;
        double userInpNumber, folge = 1;
        unsigned short int userInpSteps;


        input.clear();
        cout << "Es wird die Wurzel der Zahl c mittels Heron-Verfahren bestimmt\n";
        do
        {
            cout << "Bitte gebe die Zahl c ein deren Wurzel bestimmt werden soll.(Dezimalschreibweise 0.00)" << endl;
            cin >> input;
        } while (!service::isStringADouble(input));
        userInpNumber = std::stod(input);
        do
        {
            cout
                    << "Bitte gib ein wieviele Schritte der Folge x(n+1) = ((c/x(n)) + x(n)) /2 berechnet werden sollen:"
                    << endl;
            cin >> input;
        } while (!service::isStringANumber(input));
        userInpSteps = std::stoi(input);


        for (int i = 1; i <= userInpSteps; i++)
        {
            folge = ((userInpNumber / folge) + folge) / 2;
            stringstream << "x(" << i << ") = " << folge << "\n";
        }
        return stringstream.str();
    }
}