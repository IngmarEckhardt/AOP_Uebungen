#include "AOPExercises.h"
#include "../connector.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

char heronMenu();

void calcRootWithHeronSteps(std::stringstream &stringstream);

void calcRootWithHeronDiff(std::stringstream &stringstream);

std::string askUserForInput = "Es wird die Wurzel der Zahl c mittels Heron-Verfahren bestimmt\n"
                              "Bitte gebe die Zahl c ein deren Wurzel bestimmt werden soll.\n";
std::string askUserPrecision = "Bitte die Präzision e = (Resultat^2 - c) eingeben der die Wurzel ermittelt werden soll.\n";
std::string askUserForSteps = "Bitte gib ein wieviele Schritte der Folge x(n+1) = ((c/x(n)) + x(n)) /2 berechnet werden sollen:\n";


namespace aop
{
    std::string SquareRootWithHeronAlgo()
    {
        bool exit = false;
        std::stringstream stringstream;
        char menu;
        do
        {
            menu = heronMenu();

            switch (menu)
            {
                case 's':
                    calcRootWithHeronSteps(stringstream);
                    break;
                case 'p':
                    calcRootWithHeronDiff(stringstream);
                    break;
                case 'e':
                    exit = true;
                    break;
            }
        } while (!exit);
        return stringstream.str();
    }
}


char heronMenu()
{
    std::string input;
    bool isValidInput = false;
    while (!isValidInput)
    {
        isValidInput = true;
        cout << "Starten des Heronverfahren mit Anzahl der Schritte(s), der Präzision(p) oder Programm be(e)nden?"
             << endl;
        cin >> input;
        if (input[0] != 's' && input[0] != 'p' && input[0] != 'e')
        {
            cout << "Bitte wählen sie die vorgegebenen Buchstaben" << endl;
            isValidInput = false;
        }
    }
    return input[0];
}

void calcRootWithHeronSteps(std::stringstream &stringstream)
{
    double userInpNumber, folge = 1;
    unsigned short int userInpSteps;
    std::string input;

    userInpNumber = service::getUserInputDouble(askUserForInput);
    userInpSteps = service::getUserInputInteger(askUserForSteps);

    for (int i = 1; i <= userInpSteps; i++)
    {
        folge = ((userInpNumber / folge) + folge) / 2;
        cout << "x(" << i << ") = " << folge << "\n";
    }
}

void calcRootWithHeronDiff(std::stringstream &stringstream)
{
    double folge = 1, calculatedPrecision = 0;
    bool flag = false;
    std::string input;

    double userInpNumber = service::getUserInputDouble(askUserForInput);
    double usrChoicePrecision = service::getUserInputDouble(askUserPrecision);

    for (int i = 1; !flag; i++)
    {
        folge = ((userInpNumber / folge) + folge) / 2;
        calculatedPrecision = std::abs((folge * folge) - userInpNumber);

        if (calculatedPrecision < usrChoicePrecision)
        {
            cout << "x(" << i << ") = " << folge << "; Präzision: ";
            cout << std::fixed << std::setprecision(10) << calculatedPrecision << std::defaultfloat
                 << "\n";
            flag = true;
        }
    }
}