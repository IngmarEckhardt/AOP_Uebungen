#include "connector.h"
#include "euler/Eulerproblem.h"
#include  "aop/AOPExercises.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


template <typename T>
void fillWithProgramm(std::vector <T> &list, int amount) {
    for (int i = 1; i <= amount; i++)
    {
        list.emplace_back(i);
    }
}
template <typename T>
void printMenu(std::vector <T> &list)
{
    for (auto &e: list)
    {
        cout << "\nProgramm Nr." << e.getID() << " :  " << e.getDescription();
    }
    cout << "\n0: Programm beenden (0)" << endl;
}


namespace global
{
    void Menu()
    {
        int countSolutions = 10;
        int countAOPExamples = 5;
        std::vector<Eulerproblem> EulerMenu;
        std::vector<AOPExercises> AOPMenu;
        std::string input;
        unsigned short int menu;
        bool exit = false;


        while (!exit)
        {
            cout << "\n" << setw(27) <<"Menü\n";
            cout << setw(51) << "AOP-Übungen (1)\n";
            cout << setw(50) << "Euler-Probleme (2)\n";
            cout << setw(50) << "Programm beenden (0)\n" << endl;

            cin >> input;
            if (!service::isStringANumber(input)) continue;
            else menu= service::parseIntFromString(input);

            cout << "Wähle das Program welches du ausführen möchtest\n";
            switch (menu)
            {
                case 1:
                    if(AOPMenu.empty())
                    {
                        AOPMenu.reserve(countAOPExamples);
                        fillWithProgramm(AOPMenu, countAOPExamples);
                    }
                    printMenu(AOPMenu);
                    cin >> input;

                    if (!service::isStringANumber(input)) continue;
                    else menu= service::parseIntFromString(input);

                    cout << AOPMenu[menu - 1].execute();
                    break;

                case 2:
                    if(EulerMenu.empty())
                    {
                        EulerMenu.reserve(countSolutions);
                        fillWithProgramm(EulerMenu, countSolutions);
                    }
                    printMenu(EulerMenu);
                    cin >> input;

                    if (!service::isStringANumber(input)) continue;
                    else menu= service::parseIntFromString(input);

                    cout << EulerMenu[menu - 1].execute();
                    break;

                case 0:
                    exit = true;
                    break;

                default:
                    ;
            }
        }
    }
}