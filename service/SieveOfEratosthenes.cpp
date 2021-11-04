#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "../connector.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;


namespace global {
    std::vector<unsigned long long int> yieldPrimes(unsigned long long int maxValue) {
        clock_t erasthonesClock = clock();

        size_t size{maxValue};

        std::vector<unsigned long long int> listOfPrimes;
        std::vector<bool> bitVector(size);
        std::fill(bitVector.begin(), bitVector.end(), true);
        bitVector[0] = false;
        bitVector[1] = false;
        const unsigned long long int rangeOne = sqrt(size) + 1;
        for (unsigned long int i = 2; i < rangeOne; i++) {
            if (!bitVector[i]) continue;
            int rangeTwo = (size - 1) / i + 1;
            for (unsigned long int j = 2; j < rangeTwo; j++) {
                bitVector[i * j] = false;
            }
        }
        for (unsigned long long int k = 2; k < size; k++) {
            if (bitVector[k]) {
                listOfPrimes.push_back(k);
            }
        }
        erasthonesClock = clock() - erasthonesClock;
        cout << "\nEratosthenes brauchte " << erasthonesClock << " klicks" << endl;
        return listOfPrimes;
    }
}