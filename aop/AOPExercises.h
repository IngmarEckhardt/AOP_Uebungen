#ifndef AOP_UEBUNGEN_AOPEXERCISES_H
#define AOP_UEBUNGEN_AOPEXERCISES_H

#include "../Exercises.h"

class AOPExercises : public Exercises
{
public:
    explicit AOPExercises(unsigned short int Number);
    std::string execute(){return action();}

private:
    std::function<std::string()> action;
};

namespace aop {
    std::string fakultaet();
    std::string multiplicationTable();
    std::string nullstellen();
    std::string fibonacci();
    std::string squareRoot();

}

#endif //AOP_UEBUNGEN_AOPEXERCISES_H