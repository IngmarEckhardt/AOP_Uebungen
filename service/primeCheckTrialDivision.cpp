#include "../euler/Eulerproblem.h"

namespace global {
    bool isPrime(long int numberToCheck) {
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