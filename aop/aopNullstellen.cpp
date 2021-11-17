#include "AOPExercises.h"
#include "../connector.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace aop
{
    std::string nullstellen()
    {

        std::stringstream stringstream;
        double realNull1 = 0, realNull2 = 0, imagNull = 0;
        std::string input;

        cout << "Nullstellenberechnung der Funktion ax²+bx+c" << endl;

        std::string message = "Gib den Parameter a ein: ";
        double a = service::getUserInputDouble(message);
        message = "Gib den Parameter b ein: ";
        double b = service::getUserInputDouble(message);
        message = "Gib den Parameter b ein: ";
        double c = service::getUserInputDouble(message);


        double diskriminante = pow(b, 2) - 4 * a * c;

        if (a == 0 && b == 0 && c == 0)
        {
            stringstream << "Alle Werte von x sind eine Nullstelle, es gibt unendlich viele Nullstellen" << endl;
        }
        else if (a == 0 && b == 0)
        {
            stringstream << "Die Funktion hat keine Nullstellen" << endl;
        }
        else if (a == 0)
        {
            realNull1 = -c / b;
            stringstream << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
        }
        else if (diskriminante == 0)
        {
            realNull1 = -b / (2 * a);
            stringstream << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
        }
        else if (diskriminante > 0)
        {
            realNull1 = (-b + sqrt(diskriminante)) / (2 * a);
            realNull2 = (-b - sqrt(diskriminante)) / (2 * a);
            stringstream << "Die Nullstellen der Funktion liegen bei x1 = " << realNull1 << "und x2 = " << realNull2 << endl;
        }
        else
        {
            realNull1 = -b / (2 * a);
            imagNull = sqrt(std::abs(diskriminante)) / (2 * a);
            stringstream << "Die Nullstellen der Funktion liegen im Bereich der komplexen Zahlen.\n";
            stringstream << "x1 = " << realNull1 << " + " << imagNull << "i\n";
            stringstream << "x2 = " << realNull1 << " - " << imagNull << "i" << endl;
        }
        return stringstream.str();
    }
}