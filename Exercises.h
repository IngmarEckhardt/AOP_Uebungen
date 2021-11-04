
#ifndef AOP_UEBUNGEN_EXERCISES_H
#define AOP_UEBUNGEN_EXERCISES_H
#include <string>
#include <functional>

class Exercises
{
public:
    Exercises() {}
    int execute();
    std::string getDescription() { return description;}
    unsigned short int getID () {return idNumber;}

protected:
    unsigned short int idNumber;
    std::string description;

};


#endif //AOP_UEBUNGEN_EXERCISES_H