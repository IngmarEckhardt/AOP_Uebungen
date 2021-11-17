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
 1   unsigned long long int reverseNumber(unsigned long long int num, unsigned short int base)
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
    bool isPrime(unsigned long long int numberToCheck) {
        if (numberToCheck == 1) return false;
        if (numberToCheck == 2) return true;
        for (long int i = 2; i * i <= numberToCheck; i++) {
            if ((numberToCheck % i) == 0) {
                return false;
            }
        }
        return true;
    }
}