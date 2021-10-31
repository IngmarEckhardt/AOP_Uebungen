#include "Eulerproblem.h"

namespace euler {
    Eulerproblem::Eulerproblem(int Number) {
        euler_number = Number;

        switch (Number) {
            case 1:
                description = "Summe durch 3 u. 5 teilbarer Zahlen";
                break;
            case 2:
                description = "Summe gerader Fibonacci-Zahlen";
                case 3:
                description = "Primfaktorenzerlegung";
                case 4:
                description = "das größte Palindrom";
                case 5:
                description = "die kleinste teilbare Zahl";
                case 6:
                description = "Quadratsumme minus summierte Quadrate";
                case 7:
                description = "Die 10.001te Primzahl";
                case 8:
                description = "Das größte Produkt von 13 Ziffern";
                case 9:
                description = "Pythagoras Triple";
                case 10:
                description = "Summe der Primzahlen bis zur Größe 2Mio";
        }
    }

    std::string Eulerproblem::getResult() {
        switch (euler_number) {
            case 1:
                return eulerSolutions::getSolutionOne();
            case 2:
                return eulerSolutions::getSolutionTwo();
            case 3:
                return eulerSolutions::getSolutionThree();
            case 4:
                return eulerSolutions::getSolutionFour();
            case 5:
                return eulerSolutions::getSolutionFive();
            case 6:
                return eulerSolutions::getSolutionSix();
            case 7:
                return eulerSolutions::getSolutionSeven();
            case 8:
                return eulerSolutions::getSolutionEight();
            case 9:
                return eulerSolutions::getSolutionNine();
            case 10:
                return eulerSolutions::getSolutionTen();
        }
    }

    Eulerproblem::Eulerproblem(Eulerproblem *pEulerproblem) {

    }
}