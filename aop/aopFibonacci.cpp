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

    std::string fibonacci()
    {
        std::string askUserForInp = "Es werden die Fibonacci-Zahlen ausgegeben, wähle wieviele davon ausgegeben werden sollen:";
        std::stringstream stringstream;
        bool exitMenu = false, isYesOrNo = false;

        do
        {
            unsigned long long int fib1 = 0, fib2 = 1, range = 0, fibResult = 0, userInp;
            std::string input;

            userInp = service::getUserInputInteger(askUserForInp);

            for (int i = 2; i <= userInp+1; i++)
            {
                if (i == 2)
                {
                    cout << fib2;
                    continue;
                }
                fibResult = fib1 + fib2;
                fib1 = fib2;
                fib2 = fibResult;
                cout << ", " << fibResult;
            }
            cout << endl;

            while (!isYesOrNo)
            {
                isYesOrNo = true;
                cout << "\nMöchten Sie erneut Fibonacci-Zahlen ausgeben? (j/n)" << endl;
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

        return stringstream.str();
    }
}