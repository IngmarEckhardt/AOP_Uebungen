#ifndef AOP_UEBUNGEN_CONNECTOR_H
#define AOP_UEBUNGEN_CONNECTOR_H
#include <vector>
#include <string>

namespace global {
    void Menu();
    std::vector<unsigned long long int> yieldPrimes(unsigned long long int maxValue);
    unsigned long long int reverseNumber(unsigned long long int num);
}

namespace repository {
    void writeVectorToFile(std::vector<unsigned long long int> vectorToSafe, std::string fileName);
    std::vector<unsigned long long int> readPrimesFromFile();
}

#endif //AOP_UEBUNGEN_CONNECTOR_H