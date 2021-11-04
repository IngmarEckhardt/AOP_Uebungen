#include "AOPExercises.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

namespace aop
{
    unsigned long long fibonacci()
    {
        unsigned long long fib1, fib2, fibResult;
        bool isCorrectNumber, exitMenu, isYesOrNo;
        int range;
        std::string input;

        do
        {
            unsigned long long int userInp;
            fib1 = 0, fib2 = 1, range = 0, fibResult = 0, input.clear();
            isCorrectNumber = false, exitMenu = false, isYesOrNo = false;
            cout << "Es werden die Fibonacci-Zahlen ausgegeben, wähle wieviele davon ausgegeben werden sollen:" << endl;

            while (!isCorrectNumber)
            {
                isCorrectNumber = true;
                cin >> input;

                range = input.size();
                for (int i = 0; i < range; i++)
                {
                    if (input[i] < 48 || input[i] > 57)
                    {
                        cout << "Bitte geben sie nur positive Zahlen und keine Buchstaben ein" << endl;
                        isCorrectNumber = false;
                    }
                }
            }

            userInp = input[0] - 48;
            for (int i = 1; i < range; i++)
            {
                userInp = userInp * 10 + (input[i] - 48);
            }

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
            while (!isYesOrNo)
            {
                isYesOrNo = true;
                cout << "\nMöchten Sie erneut Fibonacci-Zahlen ausgeben? (j/n)" << endl;
                cin >> input;
                range = input.size();
                for (int i = 0; i < range; i++)
                {
                    if (input[0] != 106 && input[0] != 110)
                    {
                        cout << "\nBitte geben sie nur \"j oder n\" ein" << endl;
                        isYesOrNo = false;
                    }
                }
            }
            if (input[0] == 110)
            {
                exitMenu = true;
                input.clear();
            }
        } while (!exitMenu);

        return fibResult;
    }
}