#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <math.h>

using namespace std;


void fakultaet() {

    int userInp;
    cout << "Gib die Zahl n ein deren Fakultät berechnet werden soll: " << endl;
    cin >> userInp;
    long long fak = 1;
    for (; userInp > 1; userInp--) fak *=userInp;
    cout << "Die Fakultät ist: " << fak << endl;
}

void multiplicationTable() {
    cout << "Multiplikationstabelle: " << endl;

    for (int i=1; i<11;i++) {
        for (int j=1; j < 11; j++) {
            cout << setw(5) << i*j;
        }
        cout << endl;
    }
}

void nullstellen() {
    double a, b, c, diskrimante, realNull1, realNull2, imagNull;

    cout << "Nullstellenberechnung der Funktion ax²+bx+c" << endl;
    cout << "(Dezimalbrüche mit '.' trennen)" << endl;
    cout << "Gib den Parameter a ein: " << endl;
    cin >> a;
    cout << "Gib den Parameter b ein: " << endl;
    cin >> b;
    cout << "Gib den Parameter c ein: " << endl;
    cin >> c;

    diskrimante = pow(b,2)-4*a*c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "Alle Werte von x sind eine Nullstelle, es gibt unendlich viele Nullstellen" << endl;
    }
    else if (a==0 && b==0) {
        cout << "Die Funktion hat keine Nullstellen" << endl;
    }
    else if (a==0) {
        realNull1 = -c/b;
        cout << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
    }
    else if (diskrimante == 0) {
        realNull1 = -b/(2*a);
        cout << "Die Nullstelle der Funktion liegt bei x = " << realNull1 << endl;
    }
    else if (diskrimante > 0) {
        realNull1 = (-b+sqrt(diskrimante))/(2*a);
        realNull2 = (-b-sqrt(diskrimante))/(2*a);
        cout << "Die Nullstellen der Funktion liegen bei x1 = " << realNull1 << "und x2 = " << realNull2 << endl;
    }
    else {
        realNull1 = -b/(2*a);
        imagNull = sqrt(abs(diskrimante))/(2*a);
        cout << "Die Nullstellen der Funktion liegen im Bereich der komplexen Zahlen." << endl;
        cout << "x1 = " << realNull1 << " + " << imagNull << "i" << endl;
        cout << "x2 = " << realNull1 << " - " << imagNull << "i" << endl;
    }
}

void menue () {
    int menu;
    cout << "Wähle das Program welches du ausführen möchtest" << endl;
    cout << setw(51) << "Fakultät (1)" << endl;
    cout << setw(50) << "Multiplikationstabelle (2)" << endl;
    cout << setw(50) << "Nullstellenberechnung quadrat Funktion (3)" << endl;
    cout << setw(50) << "Fibonacci-Zahlen" << endl;
    cout << setw(50) << "Programm beenden (0)" << endl;
    cin >> menu;

    switch (menu) {
        case 1:
            fakultaet();
            break;
        case 2:
            multiplicationTable();
            break;
        case 3:
            nullstellen();
            break;
        case 0:
            exit(0);
    }
    menue();
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    menue();
}
