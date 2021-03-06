#ifndef AOP_UEBUNGEN_AOPEXERCISES_H
#define AOP_UEBUNGEN_AOPEXERCISES_H

#include "../Exercises.h"

class AOPExercises : public Exercises
{
public:
    explicit AOPExercises(unsigned short int Number);
};

namespace aop {
    std::string factorial();
    std::string multiplicationTable();
    std::string nullstellen();
    std::string fibonacci();
    std::string SquareRootWithHeronAlgo();
    std::string CosinusWithLoop();
    std::string SinusWithLoop();

}

#endif //AOP_UEBUNGEN_AOPEXERCISES_H