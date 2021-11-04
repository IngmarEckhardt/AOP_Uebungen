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
    double nullstellen()
    {
        double a = 0, b = 0, c = 0, diskriminante = 0, realNull1 = 0, realNull2 = 0, imagNull = 0;
        std::string input;

        do
        {
            input.clear();
            cout << "Nullstellenberechnung der Funktion ax²+bx+c" << endl;
            cout << "(Dezimalbrüche mit '.' trennen)" << endl;
            cout << "Gib den Parameter a ein: " << endl;
            cin >> input;
        } while (!service::isStringADouble(input));
        a = std::stod(input);

        do
        {
            cout << "Gib den Parameter b ein: " << endl;
            cin >> input;
        } while (!service::isStringADouble(input));
        b = std::stod(input);

        do
        {
            cout << "Gib den Parameter c ein: " << endl;
            cin >> input;
        } while (!service::isStringADouble(input));
        c = std::stod(input);

        diskriminante = pow(b, 2) - 4 * a * c;

        if (a == 0 && b == 0 && c == 0)
        {
            cout << "Alle Werte von x sind eine Nullstelle, es gibt unendlich viele Nullstellen" << endl;
        }
        else if (a == 0 && b == 0)
        {
            cout << "Die Funktion hat keine Nullstellen" << endl;
        }
        else if (a == 0)
        {
            realNull1 = -c / b;
            cout << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
        }
        else if (diskriminante == 0)
        {
            realNull1 = -b / (2 * a);
            cout << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
        }
        else if (diskriminante > 0)
        {
            realNull1 = (-b + sqrt(diskriminante)) / (2 * a);
            realNull2 = (-b - sqrt(diskriminante)) / (2 * a);
            cout << "Die Nullstellen der Funktion liegen bei x1 = " << realNull1 << "und x2 = " << realNull2 << endl;
        }
        else
        {
            realNull1 = -b / (2 * a);
            imagNull = sqrt(std::abs(diskriminante)) / (2 * a);
            cout << "Die Nullstellen der Funktion liegen im Bereich der komplexen Zahlen." << endl;
            cout << "x1 = " << realNull1 << " + " << imagNull << "i" << endl;
            cout << "x2 = " << realNull1 << " - " << imagNull << "i" << endl;
        }
        return realNull1;
    }
}