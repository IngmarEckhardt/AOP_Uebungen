#include <iostream>
#include <iomanip>
#include <math.h>
#include "connector.h"
#include <thread>

#ifdef _WIN32

#include <Windows.h>

#define mSetConsoleOutputCP(x) SetConsoleOutputCP(x)
#else
#define mSetConsoleOutputCP(x) 
#endif // _WIN32

using std::cout;
using std::cin;
using std::endl;
using std::setw;
int userInp;

unsigned long long fakultaet()
{
    unsigned long long fak = 1;

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

double nullstellen()
{
    double a, b, c, diskriminante, realNull1, realNull2, imagNull;

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

unsigned long long fibonacci()
{
    unsigned long long fib1 = 0, fib2 = 1, fibResult;

    cout << "Es werden die Fibonacci-Zahlen ausgegeben, wähle wieviele davon ausgegeben werden sollen:" << endl;
    cin >> userInp;
    for (int i = 1; i <= userInp; i++)
    {
        if (i == 1)
        {
            cout << fib1 << ", ";
            continue;
        }
        if (i == 2)
        {
            cout << fib2 << ", ";
            continue;
        }
        fibResult = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibResult;
        cout << fibResult << ", ";
    }
    return fibResult;
}

void menue()
{
    int menu;
    bool flag = false;
    while (!flag)
    {
        cout << "Wähle das Program welches du ausführen möchtest" << endl;
        cout << setw(51) << "Fakultät (1)" << endl;
        cout << setw(50) << "Multiplikationstabelle (2)" << endl;
        cout << setw(50) << "Nullstellenberechnung quadrat Funktion (3)" << endl;
        cout << setw(50) << "Fibonacci-Zahlen (4)" << endl;
        cout << setw(51) << "Euler_Problems(keine AOP-Übungen)&Spielereien (9)" << endl;
        cout << setw(50) << "Programm beenden (0)" << endl;
        cin >> menu;

        switch (menu)
        {
            case 1:
                fakultaet();
                break;
            case 2:
                multiplicationTable();
                break;
            case 3:
                nullstellen();
                break;
            case 4:
                fibonacci();
                break;
            case 9:
                euler::mainMenu();
                break;
            case 0:
                flag = true;
                break;
            default:;
        }
        cout << endl;
    }
}

int main()
{
    mSetConsoleOutputCP(CP_UTF8);
    std::thread t(&euler::getPrimes);
    menue();
    t.join();
    return 0;
}
