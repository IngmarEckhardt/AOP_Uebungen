#include "connector.h"
#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


namespace euler
{
    std::vector<unsigned long long int> yieldPrimes()
    {
        clock_t erasthonesClock = clock();

        constexpr size_t size {0xFFFFFFFF};

        std::vector<unsigned long long int> listOfPrimes;
        std::vector<bool> bitVector(size);
        std::fill(bitVector.begin(),bitVector.end(),true);
        bitVector[0]= false;
        bitVector[1]= false;
        const unsigned long long int rangeOne = sqrt(size) + 1;
        for (int i = 2; i < rangeOne; i++)
        {
            if (!bitVector[i]) continue;
            int rangeTwo = (size-1) / i + 1;
            for (int j = 2; j < rangeTwo; j++)
            {
                bitVector[i * j]= false;
            }
        }
        for (int k = 2; k < size; k++)
        {
            if (bitVector[k])
            {
                listOfPrimes.push_back(k);
            }
        }
        erasthonesClock = clock() - erasthonesClock;
        cout << "\nEratosthenes brauchte " << erasthonesClock << " klicks" << endl;
        return listOfPrimes;
    }

    void mainMenu()
    {
        int menu;

        cout << "\nWähle das Euler-Problem" << endl;
        cout << setw(71) << "Probleme Eins bis Zehn (1)" << endl;
        cout << setw(71) << "Probleme Elf bis Zwanzig & Yielding Primes (2)" << endl;
        cout << setw(72) << "Zurück zum Hauptmenu (0)" << endl;
        cin >> menu;

        switch (menu)
        {
            case 1:
                euler::menuOneToTen();
                euler::mainMenu();
                break;
            case 2:
                euler::menuElevenToTwenty();
                euler::mainMenu();
                break;
            case 0:
                break;
            default:
                euler::mainMenu();
        }
    }
}
