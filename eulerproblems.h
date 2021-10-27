#ifndef AOP_UEBUNGEN_EULERPROBLEMS_H
#define AOP_UEBUNGEN_EULERPROBLEMS_H

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
    cout << "Die Summe beträgt: " << sum << endl;
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
    cout << "Die Summe beträgt: " << sum << endl;
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
    int sum, step;
    for (int firstNumber=999; firstNumber >900; firstNumber--) {
        for (int secondNumber = 999; secondNumber>900; secondNumber--) {
            step = firstNumber * secondNumber;
            if ((step > sum) && (step == reverse_number(step))) sum = step;
        }
    }
    cout << "Das größte Palindrom ist: " << sum << endl;
}

namespace euler {
    void menu() {
        int menu;

        cout << "Wähle das Euler-Problem" << endl;
        cout << setw(51) << "Problem Eins (1)" << endl;
        cout << setw(51) << "Problem Zwei (2)" << endl;
        cout << setw(51) << "Problem Drei (3)" << endl;
        cout << setw(51) << "Problem Vier (4)" << endl;
        cout << setw(50) << "Zurück zum Hauptmenu (0)" << endl;
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

#endif //AOP_UEBUNGEN_EULERPROBLEMS_H
