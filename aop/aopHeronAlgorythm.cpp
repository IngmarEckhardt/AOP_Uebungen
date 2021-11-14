#include "AOPExercises.h"
#include "../connector.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void heronMenu(char &menu);

void askUserForNumber(std::string &input, double &userInpNumber);

void calcRootWithHeronSteps(std::stringstream &stringstream);

void calcRootWithHeronDiff(std::stringstream &stringstream);


namespace aop
{
    std::string HeronAlgorythm()
    {
        bool exit = false;
        std::stringstream stringstream;
        char menu = 'x';
        do
        {
            heronMenu(menu);

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


void heronMenu(char &menu)
{
    std::string input;
    bool isValidInput = false;
    unsigned short int range = 0;
    while (!isValidInput)
    {
        isValidInput = true;
        cout << "\nStarten des Heronverfahren mit Anzahl der Schritte(s) oder der Präzision(p) oder Programm be(e)nden?"
             << endl;
        cin >> input;
        range = input.size();
        for (int i = 0; i < range; i++)
        {
            if (input[0] != 's' && input[0] != 'p' && input[0] != 'e')
            {
                cout << "Bitte wählen sie die vorgegeben Buchstaben" << endl;
                isValidInput = false;
            }
        }
    }
    menu = input[0];
}

void askUserForNumber(std::string &input, double &userInpNumber)
{
    input.clear();
    cout << "Es wird die Wurzel der Zahl c mittels Heron-Verfahren bestimmt\n";
    do
    {
        cout << "Bitte gebe die Zahl c ein deren Wurzel bestimmt werden soll. (dezimal 0.00)" << endl;
        cin >> input;
    } while (!service::isStringADouble(input));
    userInpNumber = std::stod(input);
}

void calcRootWithHeronSteps(std::stringstream &stringstream)
{
    double userInpNumber, folge = 1;
    unsigned short int userInpSteps;
    std::string input;
    askUserForNumber(input, userInpNumber);
    do
    {
        cout << "Bitte gib ein wieviele Schritte der Folge x(n+1) = ((c/x(n)) + x(n)) /2 berechnet werden sollen:"
             << endl;
        cin >> input;
    } while (!service::isStringANumber(input));
    userInpSteps = std::stoi(input);


    for (int i = 1; i <= userInpSteps; i++)
    {
        folge = ((userInpNumber / folge) + folge) / 2;
        cout << "x(" << i << ") = " << folge << "\n";
    }
}

void calcRootWithHeronDiff(std::stringstream &stringstream)
{
    double userInpNumber, folge = 1, usrChoicePrecision = 0.001, calculatedPrecision = 0;
    bool flag = false;
    std::string input;

    askUserForNumber(input, userInpNumber);
    do
    {
        cout << "Bitte Präzision e = (Resultat^2 - c) der die Wurzel ermittel werden soll. (dezimal 0.00)"
             << endl;
        cin >> input;
    } while (!service::isStringADouble(input));
    usrChoicePrecision = std::stod(input);

    for (int i = 1; !flag; i++)
    {
        folge = ((userInpNumber / folge) + folge) / 2;
        cout << "x(" << i << ") = " << folge << "; Präzision: ";
        calculatedPrecision = (folge * folge) - userInpNumber;
        cout << std::fixed << std::setprecision(input.size() + 1) << calculatedPrecision << std::defaultfloat << "\n";

        if (calculatedPrecision < usrChoicePrecision) flag = true;
    }
}