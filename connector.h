#ifndef AOP_UEBUNGEN_CONNECTOR_H
#define AOP_UEBUNGEN_CONNECTOR_H
#include <vector>
#include <string>

namespace euler {
    void eulerMenu();
}

namespace repository {
    void writeVectorToFile(std::vector<unsigned long long int> vectorToSafe, std::string fileName);
    std::vector<unsigned long long int> readPrimesFromFile();
}

#endif //AOP_UEBUNGEN_CONNECTOR_H