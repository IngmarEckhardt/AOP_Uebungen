#include <vector>
#include <iostream>
#include "Eulerproblem.h"
#include "constants.h"
using std::to_string;

namespace eulerSolutions {

    std::string getSolutionOne() {

        int product;
        long int sum;

        for (int i = 1; i < 200; i++) {
            product = 5 * i;
            if (product % 3 != 0)
                sum += product;       //addiert die Vielfachen von 5, solange sie nicht durch 3 teilbar sind
        }
        for (int i = 1; i < 334; i++) {
            product = 3 * i;
            sum += product;                             //addiert alle vielfachen von drei auf die Summe drauf
        }
        return "Die Summe aller Zahlen bis 1000 die durch 3 oder 5 teilbar sind beträgt: "+ to_string(sum);
    }

    std::string getSolutionTwo() {
        int fib1{1}, fib2{1}, fibResult;
        long int sum{0};
        do {
            fibResult = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibResult;
            if (fibResult % 2 == 0)
                sum += fibResult;   //addiert die aktuelle Fibonacci-Zahl zur Summe, falls sie gerade ist
        } while (fibResult <= 4'000'000);

        return "Die Summe der geraden Fibonacci-Zahlen kleiner 4.000.000 beträgt: "+ to_string(sum);
    }

    std::string getSolutionThree() {
        std::vector<unsigned long long int> primeNumbers;
        long long int factor;
        long long int primefactor;

        //ausgangswert der Zerlegung, später als Zwischenergebnis zum Merken der Quotienten
        long long int product{600851475143};
        //Merkzettel für den größten gefundenen Faktor

        primeNumbers = euler::yieldPrimes(100'000);
        //erhöht i in jedem Durchlauf um die Primefaktoren zu finden, solange der Quotient nicht eins ist
        for (int i = 0; product > 1; i++) {
            if (i < primeNumbers.size()) primefactor = primeNumbers[i];
            else primefactor++;

            //while-Schleife sorgt dafür dass der aktuelle Primefaktor i mehrfach genutzt wird
            while (product % primefactor == 0) {
                //dividiert die Ausgangswert bzw die sich dann ergebenden Quotienten durch den Primefaktor, speichert den Quotienten als Zwischenschritt in Product
                product /= primefactor;
                factor = primefactor;                         //merkt sich den letzten verwendeten Primefactor
            }
        }
        return "\nPrime-Factorizing of n = "+to_string(product) + "\nDer größte Primfaktor ist: "+to_string(factor);
    }

    std::string getSolutionFour() {
        unsigned long long int product=1, intermediateResult;
        for (int firstNumber = 999; firstNumber > 900; firstNumber--) {
            for (int secondNumber = 999; secondNumber > 900; secondNumber--) {
                intermediateResult = firstNumber * secondNumber;
                if ((intermediateResult > product) &&
                    (intermediateResult == euler::reverseNumber(intermediateResult))) {
                    product = intermediateResult;
                }
            }
        }

        return "\nDas größte Palindrom zweier dreistelliger Faktoren ist: "+ to_string(product);
    }

    std::string getSolutionFive() {
        unsigned long int product;
        int i = 0;
        while (true) {
            product = ++i * 20;
            if (product % 19 != 0 || product % 18 != 0 || product % 17 != 0 || product % 16 != 0 || product % 15 != 0 ||
                product % 14 != 0 || product % 13 != 0 || product % 12 != 0 || product % 11 != 0) continue;
            return "\nDie kleinste Zahl die ohne Rest durch alle Zahlen von 1 bis 20 teilbar ist, ist: "+to_string(product);
        }
    }

    std::string getSolutionSix() {
        constexpr unsigned short int digit{100};
        constexpr unsigned long int squareOfSum = (((digit * digit) + digit) * ((digit * digit) + digit) / 4);
        constexpr unsigned long int sumOfSquares = (digit * (digit + 1) * (2 * digit + 1)) / 6;
        constexpr unsigned long int difference = (squareOfSum - sumOfSquares);
        return "Die Differenz zwischen der quadratieren Summe aller Zahlen bis 100 und der Summe der Quadrate dieser Zahlen ist:\n"+ std::to_string(difference);
    }

    std::string getSolutionSeven() {
        std::vector<unsigned long long int>primeNumbers = euler::yieldPrimes(250'000);

        return "Die 10.001te Primzahl ist die: " + to_string(primeNumbers[10'000]);
    }


    std::string getSolutionEight (){
        std::string number = eulerConst::numberProblem8;
        unsigned long long product = 0;
        for (int start = 0; start + 13 < 1000; start++)
        {
            unsigned long long step = 1;
            for (unsigned int i = 0; i < 13; i++)
            {
                step *= number[start + i] - '0';
            }
            if (product < step) product = step;
        }
        return"Das größte Produkt ist: " + to_string(product);
    }

    std::string getSolutionNine () {
        for (short int c = 500; c>0; c--)
        {
            for (unsigned short int b = 499; b > 0; b--)
            {
                for (unsigned short int a = 498; a > 0; a--)
                {
                    if (((a + b + c) == 1000) && ((c * c) == (a * a) + (b * b)))
                    {
                        return "Bedingung: a<b<c; a²+b²=c², a+b+c=1000\na ist gleich = "+to_string(a)+
                        "\nb ist gleich = "+to_string(b)+"\nc ist gleich = " + to_string(c);
                    }
                }
            }
        }
        return "failed";
    }

    std::string getSolutionTen (){
        unsigned long long int sum=0;
        std::vector<unsigned long long int>primeNumbers = euler::yieldPrimes(2'000'000);

        for (const auto &e: primeNumbers) sum +=e;

        return "Die Summe aller Primzahlen bis 2.000.000 ist: "+ to_string(sum);
    }
}