#ifndef AOP_UEBUNGEN_EULERPROBLEM_H
#define AOP_UEBUNGEN_EULERPROBLEM_H


#include <string>
#include <vector>
#include <functional>

namespace euler {

    class Eulerproblem {
    public:
        Eulerproblem(int Number);

        Eulerproblem(Eulerproblem *pEulerproblem);

        int getNumber() { return euler_number; }
        std::string getDescription() { return description; }
        std::string getResult () {return action();};

    private:
        int euler_number;
        std::string description;
        std::function<std::string()> action;
    };


    std::vector<unsigned long long int> yieldPrimes(unsigned long long int maxValue);
    unsigned long long int reverseNumber (unsigned long long int numberToReverse);
    bool isPrime(unsigned long long int numberToCheck);


}


namespace eulerSolutions {
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
