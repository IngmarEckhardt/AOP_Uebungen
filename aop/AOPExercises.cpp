#include "AOPExercises.h"

AOPExercises::AOPExercises(unsigned short int Number) {
    idNumber = Number;

    switch (Number)
    {
        case 1:
            description = "Fakultät berechnen";
            action = &aop::fakultaet;
            break;
        case 2:
            description = "Multiplikationstabelle";
            action = &aop::multiplicationTable;
            break;
        case 3:
            description = "Nullstellenberechung quadr. Funktionen";
            action = &aop::nullstellen;
            break;
        case 4:
            description = "Fibonacci-Zahlen";
            action = &aop::fibonacci;
            break;
        case 5:
            description = "Wurzelberechnung mit Heron-Verfahren";
            action = &aop::squareRoot;
    }
}