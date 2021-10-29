#include "connector.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

void yieldingPrimesForTestPurposes() {
    std::vector<unsigned long long int> primes = euler::yield100MioPrimes();
    std::cout << "Es sind " << primes.size() << " Primzahlen in der Liste\n"
                                                "Die größte Primzahl ist die " << primes.at((primes.size()-1));
//    std::vector<unsigned int> exponents;
//    unsigned int numberToCheck=1;
//    unsigned short countAllFactors, countPrimeFaktor;
//    for (int i = 2; i <100'000; i++) {
//        numberToCheck +=i;
//        int range = sqrt(numberToCheck);
//        for (int index = 0; index < primes.size()&& numberToCheck >1; index++) {
//            while (numberToCheck%primes.at(index) == 0) {
//                countPrimeFaktor++;
//                numberToCheck/primes.at(index);
//            }
//            exponents.at(index)=countPrimeFaktor;
//            countPrimeFaktor=0;
//        }
//
//    }
}


namespace euler
{
    void menuElevenToTwenty()
    {
        int menu;

        cout << "\nWähle das Euler-Problem" << endl;
        cout << setw(71) << "Yielding Primes  (1)" << endl;

        cout << setw(72) << "Zurück zum Eulermenu (0)" << endl;
        cin >> menu;

        switch (menu)
        {
            case 1:
                yieldingPrimesForTestPurposes();
                euler::menuElevenToTwenty();
                break;
            case 0:
                break;
        }
    }
}