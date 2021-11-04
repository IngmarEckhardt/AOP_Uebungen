#include "Eulerproblem.h"

Eulerproblem::Eulerproblem(int Number)
    {
        idNumber = Number;

        switch (Number)
        {
            case 1:
                description = "Summe durch 3 u. 5 teilbarer Zahlen";
                action = &eulerSolutions::getSolutionOne;
                break;
            case 2:
                description = "Summe gerader Fibonacci-Zahlen";
                action = &eulerSolutions::getSolutionTwo;
                break;
            case 3:
                description = "Primfaktorenzerlegung";
                action = &eulerSolutions::getSolutionThree;
                break;
            case 4:
                description = "das größte Palindrom";
                action = &eulerSolutions::getSolutionFour;
                break;
            case 5:
                description = "die kleinste teilbare Zahl";
                action = &eulerSolutions::getSolutionFive;
                break;
            case 6:
                description = "Quadratsumme minus summierte Quadrate";
                action = &eulerSolutions::getSolutionSix;
                break;
            case 7:
                description = "Die 10.001te Primzahl";
                action = &eulerSolutions::getSolutionSeven;
                break;
            case 8:
                description = "Das größte Produkt von 13 Ziffern";
                action = &eulerSolutions::getSolutionEight;
                break;
            case 9:
                description = "Pythagoras Triple";
                action = &eulerSolutions::getSolutionNine;
                break;
            case 10:
                description = "Summe der Primzahlen bis zur Größe 2Mio";
                action = &eulerSolutions::getSolutionTen;
                break;
        }
    }

    Eulerproblem::Eulerproblem(Eulerproblem *pEulerproblem)
    {

    }