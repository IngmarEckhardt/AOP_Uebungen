#include "../connector.h"

namespace service {
    unsigned long long int reverseNumber(unsigned long long int num, unsigned short int base)
    {
        int reversed = 0;

        while (num != 0)
        {
            unsigned long long int digit = num % base;
            reversed = reversed * base + digit;
            num /= base;
        }
        return reversed;
    }
}