#include "../connector.h"

namespace service {

    unsigned long long int getFactorial (unsigned short int number) {
        unsigned long long int fak = 1;
        for (; number > 1; number--) fak *= number;
        return fak;
    }
}