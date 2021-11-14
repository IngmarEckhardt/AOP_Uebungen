#ifndef AOP_UEBUNGEN_EULERPROBLEM_H
#define AOP_UEBUNGEN_EULERPROBLEM_H

#include <string>
#include <vector>
#include <functional>
#include "../Exercises.h"

class Eulerproblem: public Exercises
{
public:
    Eulerproblem(int Number);
};

namespace euler
{
    std::string getSolutionOne();
    std::string getSolutionTwo();
    std::string getSolutionThree();
    std::string getSolutionFour();
    std::string getSolutionFive();
    std::string getSolutionSix();
    std::string getSolutionSeven();
    std::string getSolutionEight();
    std::string getSolutionNine();
    std::string getSolutionTen();
}
#endif //AOP_UEBUNGEN_EULERPROBLEM_H