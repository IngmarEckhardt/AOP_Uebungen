#include "../connector.h"
#include <string>
#include <iostream>

namespace service
{
    double getUserInputDouble(std::string &message)
    {
        std::string input;
        do
        {
            std::cout << message << "\n(nur Zahlen eingeben, Dezimaltrennung mit Punkt) " << std::endl;
            std::cin >> input;
        } while (!service::isStringADouble(input));
        return std::stod(input);
    }
    unsigned long long int getUserInputInteger(std::string &message)
    {
        std::string input;
        do
        {
            std::cout << message << "\n(nur ganze Zahlen eingeben) " << std::endl;
            std::cin >> input;
        } while (!service::isStringAInt(input));
        return std::stoi(input);
    }
}