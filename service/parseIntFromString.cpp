#include "../connector.h"
#include <string>

namespace service
{
    unsigned long long int parseIntFromString(const std::string &input)
    {
        unsigned long long int intUnderConstruction;
        intUnderConstruction = input[0] - 48;
        for (int i = 1; i < input.size(); i++)
        {
            intUnderConstruction = intUnderConstruction * 10 + (input[i] - 48);
        }
        return intUnderConstruction;
    }
}