#include "connector.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
#include <iterator>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

std::vector<unsigned long long int> listOfPrimes;

std::vector<unsigned long long int> yieldPrimes()
{
    clock_t erasthonesClock = clock();

    constexpr size_t size{0xFFFFFF};

    std::vector<bool> bitVector(size);
    std::fill(bitVector.begin(), bitVector.end(), true);
    bitVector[0] = false;
    bitVector[1] = false;
    const unsigned long long int rangeOne = sqrt(size) + 1;
    for (int i = 2; i < rangeOne; i++)
    {
        if (!bitVector[i]) continue;
        int rangeTwo = (size - 1) / i + 1;
        for (int j = 2; j < rangeTwo; j++)
        {
            bitVector[i * j] = false;
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

    std::ofstream outFile(".\\primes.txt");
    for (const auto &e: listOfPrimes) outFile << e << "\n";

    return listOfPrimes;
}

bool readPrimesFromFile()
{

    std::ifstream is(".\\primes.txt");
    if (!is.good()) return false;

    std::istream_iterator<unsigned long long int> start(is), end;
    std::vector<unsigned long long int> primes(start, end);
    cout <<"Datei wurde gelesen";
    listOfPrimes = primes;

    return true;
}



namespace euler
{

    std::vector<unsigned long long int> getPrimes () {
        if (listOfPrimes.empty())
        {
            if (readPrimesFromFile())
            {
                return listOfPrimes;
            }
            else
            {
                yieldPrimes();
                return listOfPrimes;
            }
        }
        else return listOfPrimes;
    }

    void mainMenu()
    {
        int menu;
        bool exit = false;
        while (!exit)
        {
            cout << "\nWähle das Euler-Problem" << endl;
            cout << setw(71) << "Probleme Eins bis Zehn (1)" << endl;
            cout << setw(71) << "Probleme Elf bis Zwanzig & Yielding Primes (2)" << endl;
            cout << setw(72) << "Zurück zum Hauptmenu (0)" << endl;
            cin >> menu;

            switch (menu)
            {
                case 1:
                    euler::menuOneToTen();
                    break;
                case 2:
                    euler::menuElevenToTwenty();
                    break;
                case 0:
                    exit = true;
                    break;
                default:;
            }
        }
    }
}
