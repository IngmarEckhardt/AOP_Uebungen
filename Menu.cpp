#include "connector.h"
#include "euler/Eulerproblem.h"
#include  "aop/AOPExercises.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using global::MenuChoice;

unsigned short int countSolutions = 10, countAOPExamples = 7;

//Functions
template<typename T>
void fillWithProgramm(std::vector<T> &list, MenuChoice usrChoice);
template<typename T>
void printMenu(std::vector<T> &list);


namespace global
{

    void Menu()
    {

        unsigned short int menu;
        std::vector<Exercises> ExercisesMenu;
        std::string input;
        bool exit = false;
        MenuChoice menuChosen;

        while (!exit)
        {
            cout << "\n" << setw(27) << "Menü\n";
            cout << setw(51) << "AOP-Übungen (1)\n";
            cout << setw(50) << "Euler-Probleme (2)\n";
            cout << setw(50) << "Alle Unterprogramme (3)\n";
            cout << setw(50) << "Programm beenden (0)\n" << endl;
            std::string messageMenu = "Wähle mit Eingabe der Nummer\n";
            menu = service::getUserInputInteger(messageMenu);

            switch (menu)
            {
                case 1:
                    if (menuChosen != AOP || ExercisesMenu.empty()) fillWithProgramm(ExercisesMenu, AOP);
                    menuChosen = AOP;
                    break;
                case 2:
                    if (menuChosen != EULER || ExercisesMenu.empty()) fillWithProgramm(ExercisesMenu, EULER);
                    menuChosen = EULER;
                    break;
                case 3:
                    if (menuChosen != BOTH || ExercisesMenu.empty()) fillWithProgramm(ExercisesMenu, BOTH);
                    menuChosen = BOTH;
                    break;
                case 0:
                    std::exit(0);
                    break;
                default: ;

            }
            printMenu(ExercisesMenu);
            std::string message = "Wähle das Program welches du ausführen möchtest\n";
            menu = service::getUserInputInteger(message);
            if (menu != 0) {cout << ExercisesMenu[menu - 1].execute();}
        }
    }
}

template<typename T>
void fillWithProgramm(std::vector<T> &list, MenuChoice usrChoice)
{
    list.clear();
    switch (usrChoice)
    {
        case global::AOP:
            list.reserve(countAOPExamples);
            for (int i = 1; i <= countAOPExamples; i++)
            {
                list.push_back(AOPExercises(i));
            }
            break;
        case global::EULER:
            list.reserve(countSolutions);
            for (int i = 1; i <= countSolutions; i++)
            {
                list.push_back(Eulerproblem(i));
            }
            break;
        case global::BOTH:
            list.reserve(countAOPExamples+countSolutions);
            for (int i = 1; i <= countAOPExamples; i++)
            {
                list.push_back(AOPExercises(i));
            }
            for (int i = 1; i <= countSolutions; i++)
            {
                list.push_back(Eulerproblem(i));
            }
            break;
    }
}

template<typename T>
void printMenu(std::vector<T> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << "\nProgramm Nr." << list[i].getID() << " :  " << list[i].getDescription() << " (" << i+1 << ")";
    }
    cout << "\n0: Programm beenden (0)" << endl;
}