#include "AOPExercises.h"
#include "../connector.h"
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
        bool exitMenu, isYesOrNo;
        unsigned short int range;
        unsigned long long int fib1, fib2, fibResult,userInp;
        std::string input;

        do
        {
            fib1 = 0, fib2 = 1, range = 0, fibResult = 0;
            exitMenu = false, isYesOrNo = false;
            input.clear();
            cout << "Es werden die Fibonacci-Zahlen ausgegeben, wähle wieviele davon ausgegeben werden sollen:\n" << endl;
            do
            {
                cout << "Bitte geben sie nur positive Zahlen und keine Buchstaben ein\n" << endl;
                cin >> input;
            }
            while (!service::isStringANumber(input));
            userInp = std::stoi(input);

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
                cout << "\nMöchten Sie erneut Fibonacci-Zahlen ausgeben? (j/n)\n" << endl;
                cin >> input;
                range = input.size();
                for (int i = 0; i < range; i++)
                {
                    if (input[0] != 'j' && input[0] != 'n')
                    {
                        cout << "Bitte geben sie nur \"j\" oder \"n\" ein\n" << endl;
                        isYesOrNo = false;
                    }
                }
            }
            if (input[0] == 'n')
            {
                exitMenu = true;
            }
        } while (!exitMenu);

        return fibResult;
    }
}