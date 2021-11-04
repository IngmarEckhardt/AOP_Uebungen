#include "AOPExercises.h"
#include <iostream>
#include <iomanip>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace aop
{
    double nullstellen()
    {
        double a, b, c, diskriminante, realNull1=0, realNull2, imagNull;

        cout << "Nullstellenberechnung der Funktion ax²+bx+c" << endl;
        cout << "(Dezimalbrüche mit '.' trennen)" << endl;
        cout << "Gib den Parameter a ein: " << endl;
        cin >> a;
        cout << "Gib den Parameter b ein: " << endl;
        cin >> b;
        cout << "Gib den Parameter c ein: " << endl;
        cin >> c;

        diskriminante = pow(b, 2) - 4 * a * c;

        if (a == 0 && b == 0 && c == 0)
        {
            cout << "Alle Werte von x sind eine Nullstelle, es gibt unendlich viele Nullstellen" << endl;
        } else if (a == 0 && b == 0)
        {
            cout << "Die Funktion hat keine Nullstellen" << endl;
        } else if (a == 0)
        {
            realNull1 = -c / b;
            cout << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
        } else if (diskriminante == 0)
        {
            realNull1 = -b / (2 * a);
            cout << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
        } else if (diskriminante > 0)
        {
            realNull1 = (-b + sqrt(diskriminante)) / (2 * a);
            realNull2 = (-b - sqrt(diskriminante)) / (2 * a);
            cout << "Die Nullstellen der Funktion liegen bei x1 = " << realNull1 << "und x2 = " << realNull2 << endl;
        } else
        {
            realNull1 = -b / (2 * a);
            imagNull = sqrt(abs(diskriminante)) / (2 * a);
            cout << "Die Nullstellen der Funktion liegen im Bereich der komplexen Zahlen." << endl;
            cout << "x1 = " << realNull1 << " + " << imagNull << "i" << endl;
            cout << "x2 = " << realNull1 << " - " << imagNull << "i" << endl;
        }
        return realNull1;
    }
}