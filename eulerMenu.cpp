#include "connector.h"
#include <iostream>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::setw;


namespace euler
{

    void mainMenu()
    {
        int menu;

        cout << "\nWähle das Euler-Problem" << endl;
        cout << setw(71) << "Probleme Eins bis 10 (1)" << endl;
        cout << setw(72) << "Zurück zum Hauptmenu (0)" << endl;
        cin >> menu;

        switch (menu)
        {
            case 1:
                euler::menuOneToTen();
                euler::mainMenu();
                break;
            case 0:
                break;
            default:
                euler::mainMenu();
        }
    }
}
