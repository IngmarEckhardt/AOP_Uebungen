#include "../connector.h"

namespace service {

    unsigned long long int getFactorial (unsigned short int number) {
        if (number >20) return 0;
        unsigned long long int fak = 1;
        for (; number > 1; number--) fak *= number;
        return fak;
    }
    double ModuloPi(double input)
    {
        if (input > (2 * M_PI))
        {
            return ModuloPi(input - (2 * M_PI));
        }
        return input;
    }
}