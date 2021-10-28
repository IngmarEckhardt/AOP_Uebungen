#include "connector.h"
#include <iostream>
#include <iomanip>


using std::cout;
using std::cin;
using std::endl;
using std::setw;


void eulerOne() {
    int product;
    long int sum;

    for (int i = 1; i < 200; i++) {
        product = 5 * i;
        if (product % 3 != 0) sum += product;
    }
    for (int i = 1; i < 334; i++) {
        product = 3 * i;
        sum += product;
    }
    cout << "Die Summe aller Zahlen bis 1000 die durch 3 oder 5 teilbar sind beträgt: " << sum << endl;
}

void eulerTwo() {
    int fib1 = 1, fib2 = 1, fibResult;
    long int sum = 0;
    do {
        fibResult = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibResult;
        if (fibResult % 2 == 0) sum += fibResult;
    } while (fibResult <= 4'000'000);
    cout << "Die Summe der geraden Fibonacci-Zahlen kleiner 4.000.000 beträgt: " << sum << endl;
}

void eulerThree() {
    cout << "Prime-Factorizing of n = 600851475143" << endl;
    long long int product{600851475143};
    long int factor;
    for (int i = 2; product > 1; i++) {
        while (product % i == 0) {
            product /= i;
            factor = i;
        }
    }
    cout << "Der größte Primfaktor ist: " << factor << endl;
}

int reverse_number(int num) {
    int base = 10, reversed = 0;

    while (num != 0) {
        int digit = num % base;
        reversed = reversed * base + digit;
        num /= base;
    }
    return reversed;
}

void eulerFour() {
    long int sum, step;
    for (int firstNumber = 999; firstNumber > 900; firstNumber--) {
        for (int secondNumber = 999; secondNumber > 900; secondNumber--) {
            step = firstNumber * secondNumber;
            if ((step > sum) && (step == reverse_number(step))) sum = step;
        }
    }
    cout << "Das größte Palindrom zweier dreistelliger Faktoren ist: " << sum << endl;
}
namespace euler {
    void menu() {
        int menu;

        cout << "\nWähle das Euler-Problem" << endl;
        cout << setw(71) << "Problem Eins -Summe durch 3 u. 5 teilbarer Zahlen (1)" << endl;
        cout << setw(71) << "Problem Zwei - Summe gerader Fibonacci-Zahlen (2)" << endl;
        cout << setw(71) << "Problem Drei - Primfaktorenzerlegung (3)" << endl;
        cout << setw(73) << "Problem Vier - das größte Palindrom (4)" << endl;
        cout << setw(72) << "Zurück zum Hauptmenu (0)" << endl;
        cin >> menu;

        switch (menu) {
            case 1:
                eulerOne();
                euler::menu();
                break;
            case 2:
                eulerTwo();
                euler::menu();
                break;
            case 3:
                eulerThree();
                euler::menu();
                break;
            case 4:
                eulerFour();
                euler::menu();
                break;
            case 0:
                break;
            default:
                euler::menu();
        }
    }
}
