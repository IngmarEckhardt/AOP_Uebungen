#include <fstream>
#include <iterator>
#include "connector.h"

namespace repository {
    void writeVectorToFile (std::vector<unsigned long long int> &primes, std::string file = ".\\primes.txt"){
        std::ofstream outFile(file);
        for (const auto &e: primes) outFile << e << "\n";
    }

    std::vector<unsigned long long int> readPrimesFromFile (unsigned long long int amount) {

        std::ifstream is(".\\primes.txt");
        std::istream_iterator<unsigned long long int> start(is), end;
        std::vector<unsigned long long int> primesFromFile(start, end);
        return primesFromFile;
    }

}