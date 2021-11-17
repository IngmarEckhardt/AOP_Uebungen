#ifndef AOP_UEBUNGEN_CONNECTOR_H
#define AOP_UEBUNGEN_CONNECTOR_H

#include <vector>
#include <string>
#include <cmath>



namespace global
{
    void Menu();

    enum MenuChoice
    {
        AOP, EULER, BOTH
    };

}

namespace service
{
    std::vector<unsigned long long int> yieldPrimes(unsigned long long int maxValue);

    unsigned long long int reverseNumber(unsigned long long int num, unsigned short int base = 10);

    bool isStringAInt(const std::string &input);

    bool isStringADouble(const std::string &input);

    unsigned long long int parseIntFromString(const std::string &input);

    bool isPrime(unsigned long long int numberToCheck);

    unsigned long long int getFactorial(unsigned short int number);

    double getUserInputDouble(std::string &message);

    unsigned long long int getUserInputInteger(std::string &message);

    double ModuloPi(double input);
}

namespace repository
{
    void writeVectorToFile(std::vector<unsigned long long int> vectorToSafe, std::string fileName);

    std::vector<unsigned long long int> readPrimesFromFile();
}

#endif //AOP_UEBUNGEN_CONNECTOR_H