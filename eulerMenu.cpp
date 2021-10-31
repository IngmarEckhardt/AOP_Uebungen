#include "connector.h"
#include "Eulerproblem.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


namespace euler {
    void eulerMenu() {
        int countSolutions = 10;
        int menu;
        bool exit = false;

        std::vector<euler::Eulerproblem> eulerProbleme;
        for (int i = 1; i < countSolutions; i++)
        {
            eulerProbleme.push_back(new euler::Eulerproblem(i));
        }

        while (!exit) {

            cout << "\nWähle die Nummer des Euler-Problem" << endl;
            for (auto &e: eulerProbleme)
            {
                cout << "\nProblem Nr." << e.getNumber() << ": " << e.getDescription();
            }
            cout << "\n0: Zurück zum Hauptmenu" << endl;

            cin >> menu;
            if (menu == 0) exit = true;
            else cout << eulerProbleme[menu - 1].getResult() << endl;
        }
    }
}
