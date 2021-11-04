#ifndef AOP_UEBUNGEN_AOPEXERCISES_H
#define AOP_UEBUNGEN_AOPEXERCISES_H

#include "../Exercises.h"

class AOPExercises : public Exercises
{
public:
    explicit AOPExercises(unsigned short int Number);
    void execute(){return action();}

private:
    std::function<void()> action;
};

namespace aop {
    unsigned long long int fakultaet();
    int multiplicationTable();
    double nullstellen();
    unsigned long long int fibonacci();

}

#endif //AOP_UEBUNGEN_AOPEXERCISES_H