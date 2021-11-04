#include "../connector.h"

namespace global {
    unsigned long long int reverseNumber(unsigned long long int num)
    {
        int base = 10, reversed = 0;

        while (num != 0)
        {
            unsigned long long int digit = num % base;                 //teilt die Ausgangszahl durch 10 und merkt sich den Rest
            //multipliziert die Zwischenwerte der umgedrehten Zahl mit 10 und hängt den Rest an
            reversed = reversed * base + digit;
            num /= base;                            // Rechnet den Quotienten der Ausgangszahl ganzzahlig und speichert den als Zwischenergebnis
        }
        return reversed;
    }
}
