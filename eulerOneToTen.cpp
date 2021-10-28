#include "connector.h"
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <bitset>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::setw;


long int eulerOne()
{
    int product;
    long int sum;

    for (int i = 1; i < 200; i++)
    {
        product = 5 * i;
        if (product % 3 != 0)
            sum += product;       //addiert die Vielfachen von 5, solange sie nicht durch 3 teilbar sind
    }
    for (int i = 1; i < 334; i++)
    {
        product = 3 * i;
        sum += product;                             //addiert alle vielfachen von drei auf die Summe drauf
    }
    cout << "Die Summe aller Zahlen bis 1000 die durch 3 oder 5 teilbar sind beträgt: " << sum << endl;

    return sum;
}

long int eulerTwo()
{
    int fib1{1}, fib2{1}, fibResult;
    long int sum{0};
    do
    {
        fibResult = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibResult;
        if (fibResult % 2 == 0)
            sum += fibResult;   //addiert die aktuelle Fibonacci-Zahl zur Summe, falls sie gerade ist
    } while (fibResult <= 4'000'000);
    cout << "Die Summe der geraden Fibonacci-Zahlen kleiner 4.000.000 beträgt: " << sum << endl;

    return sum;
}

long int eulerThree()
{
    cout << "Prime-Factorizing of n = 600851475143" << endl;
    //ausgangswert der Zerlegung, später als Zwischenergebnis zum Merken der Quotienten
    long long int product{600851475143};
    //Merkzettel für den größten gefundenen Faktor
    long int factor;
    //erhöht i in jedem Durchlauf um die Primefaktoren zu finden, solange der Quotient nicht eins ist
    for (int i = 2; product > 1; i++)
    {
        //while-Schleife sorgt dafür dass der aktuelle Primefaktor i mehrfach genutzt wird
        while (product % i == 0)
        {
            //dividiert die Ausgangswert bzw die sich dann ergebenden Quotienten durch den Primefaktor, speichert den Quotienten als Zwischenschritt in Product
            product /= i;
            factor = i;                         //merkt sich den letzten verwendeten Primefactor
        }
    }
    cout << "Der größte Primfaktor ist: " << factor << endl;

    return factor;
}

int reverse_number(int num)
{
    int base = 10, reversed = 0;

    while (num != 0)
    {
        int digit = num % base;                 //teilt die Ausgangszahl durch 10 und merkt sich den Rest
        //multipliziert die Zwischenwerte der umgedrehten Zahl mit 10 und hängt den Rest an
        reversed = reversed * base + digit;
        num /= base;                            // Rechnet den Quotienten der Ausgangszahl ganzzahlig und speichert den als Zwischenergebnis
    }
    return reversed;
}

long int eulerFour()
{
    long int product, intermediateResult;
    for (int firstNumber = 999; firstNumber > 900; firstNumber--)
    {
        for (int secondNumber = 999; secondNumber > 900; secondNumber--)
        {
            intermediateResult = firstNumber * secondNumber;
            if ((intermediateResult > product) && (intermediateResult == reverse_number(intermediateResult)))
            {
                product = intermediateResult;
            }
        }
    }
    cout << "Das größte Palindrom zweier dreistelliger Faktoren ist: " << product << endl;

    return product;
}

unsigned long int eulerFive()
{
    unsigned long int product;
    int i = 0;
    bool flag = false;
    do
    {
        product = ++i * 20;
        if (product % 19 != 0 || product % 18 != 0 || product % 17 != 0 || product % 16 != 0 || product % 15 != 0 ||
            product % 14 != 0 || product % 13 != 0 || product % 12 != 0 || product % 11 != 0)
            continue;
        else flag = true;
        cout << "Die kleinste Zahl die ohne Rest durch alle Zahlen von 1 bis 20 teilbar ist, ist: " << product << endl;
    } while (!flag);
    return product;
}

unsigned long int eulerSix()
{
    constexpr unsigned short int digit{100};
    constexpr unsigned long int squareOfSum = (((digit * digit) + digit) * ((digit * digit) + digit) / 4);
    constexpr unsigned long int sumOfSquares = (digit * (digit + 1) * (2 * digit + 1)) / 6;
    constexpr unsigned long int difference = (squareOfSum - sumOfSquares);
    cout
            << "Die Differenz zwischen der quadratieren Summe aller Zahlen bis 100 und der Summe der Quadrate dieser Zahlen ist:\n"
            << difference << endl;
    return difference;
}

bool isPrime(long int numberToCheck)
{
    if (numberToCheck == 1) return false;
    if (numberToCheck == 2) return true;
    for (long int i = 2; i * i <= numberToCheck; i++)
    {
        if ((numberToCheck % i) == 0)
        {
            return false;
        }
    }
    return true;
}

unsigned long int eulerSeven()
{
    unsigned short int countPrimes = 1;
    unsigned long int index = 1;

    while (countPrimes < 10001)
    {
        index += 2;
        if (isPrime(index)) countPrimes++;
    }
    cout << "Die 10.001te Primzahl ist die: " << index << endl;
    return index;
}

unsigned long long int eulerEight()
{
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
    cout << "Das größte Produkt ist: " << product << endl;
    return product;
}

bool eulerNine()
{
    bool flag = false;
    for (short int c = 500; !flag; c--)
    {
        for (unsigned short int b = 499; !flag && b > 0; b--)
        {
            for (unsigned short int a = (b - 1); !flag && a > 0; a--)
            {
                if (((a + b + c) == 1000) && ((c * c) == (a * a) + (b * b)))
                {
                    cout << "Bedingung: a<b<c; a²+b²=c², a+b+c=1000\n";
                    cout << "a ist gleich = " << a << "\nb ist gleich = " << b << "\nc ist gleich = " << c << endl;
                    flag = true;
                }
            }
        }
    }
    return flag;
}

unsigned long long eulerTen()
{
    clock_t eulerTenClock = clock();
    unsigned long long sum = 2;

    for (unsigned int i = 1; i < 2'000'000; i += 2)
    {
        if (isPrime(i)) sum += i;
    }
    eulerTenClock = clock() - eulerTenClock;
    cout << "Die Summe aller Primzahlen bis 2.000.000 ist: " << sum << endl << "Bruteforce brauchte " << eulerTenClock << " klicks" << endl;
    return sum;
}

unsigned long long eulerTenWithEratosthenes()
{
    clock_t erasthonesClock = clock();
    unsigned long long sum = 0;

    std::bitset<2000000> bitVector;
    bitVector.set();
    bitVector.set(0, false);
    bitVector.set(1, false);
    const int range = sqrt(2'000'000) + 1;
    for (int i = 2; i < range; i++)
    {
        if (!bitVector[i]) continue;
        int rangeTwo = 1'999'999 / i + 1;
        for (int j = 2; j < rangeTwo; j++)
        {
            bitVector.set(i * j, false);
        }
    }
    for (int k = 0; k < 2000000; k++)
    {
        if (bitVector[k])
        {
            sum += k;
        }
    }
    erasthonesClock = clock() - erasthonesClock;
    cout << "Die Summe aller Primzahlen bis 2.000.000 ist: " << sum << "\nEratosthenes brauchte " << erasthonesClock << " klicks" << endl;
    return sum;
}

namespace euler
{
    void menuOneToTen()
    {
        int menu;

        cout << "\nWähle das Euler-Problem" << endl;
        cout << setw(71) << "Problem Eins -Summe durch 3 u. 5 teilbarer Zahlen (1)" << endl;
        cout << setw(71) << "Problem Zwei - Summe gerader Fibonacci-Zahlen (2)" << endl;
        cout << setw(71) << "Problem Drei - Primfaktorenzerlegung (3)" << endl;
        cout << setw(73) << "Problem Vier - das größte Palindrom (4)" << endl;
        cout << setw(72) << "Problem Fünf - die kleinste teilbare Zahl (5)" << endl;
        cout << setw(71) << "Problem Sechs - Quadratsumme minus summierte Quadrate (6)" << endl;
        cout << setw(71) << "Problem Sieben- Die 10.001te Primzahl (7)" << endl;
        cout << setw(73) << "Problem Acht- Das größte Produkt von 13 Ziffern (8)" << endl;
        cout << setw(71) << "Problem Neun- Pythagoras Triple (9)" << endl;
        cout << setw(71) << "Problem Zehn- Summe der Primzahlen bis zur Größe 2Mio (10)" << endl;
        cout << setw(71) << "Problem Zehn- Summe der Primzahlen, Sieb des Erastothenes (11)" << endl;
        cout << setw(72) << "Zurück zum Eulermenu (0)" << endl;
        cin >> menu;

        switch (menu)
        {
            case 1:
                eulerOne();
                euler::menuOneToTen();
                break;
            case 2:
                eulerTwo();
                euler::menuOneToTen();
                break;
            case 3:
                eulerThree();
                euler::menuOneToTen();
                break;
            case 4:
                eulerFour();
                euler::menuOneToTen();
                break;
            case 5:
                eulerFive();
                euler::menuOneToTen();
                break;
            case 6:
                eulerSix();
                euler::menuOneToTen();
                break;
            case 7:
                eulerSeven();
                euler::menuOneToTen();
                break;
            case 8:
                eulerEight();
                euler::menuOneToTen();
                break;
            case 9:
                eulerNine();
                euler::menuOneToTen();
                break;
            case 10:
                eulerTen();
                euler::menuOneToTen();
                break;
            case 11:
                eulerTenWithEratosthenes();
                euler::menuOneToTen();
                break;
            case 0:
                break;
        }
    }
}