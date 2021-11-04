#include "../connector.h"
#include <string>

namespace service {
    bool isStringANumber(const std::string &input)
    {

        unsigned int range = input.size();
        for (int i = 0; i < range; i++)
        {
            if (input[i] < 48 || input[i] > 57) return false;
        }
        return true;
    }
    bool isStringADouble(const std::string &input)
    {
        bool oneDecPoint = false;
        unsigned int range = input.size();
        if (input[0] < 48 || input[0] > 57) return false;
        for (int i = 1; i < range; i++)
        {
            if (input[i] < 46 || input[i] == 47 || input[i] > 57) return false;
            if (oneDecPoint && input[i] == '.') return false;
            if (input[i] == '.') oneDecPoint = true;
        }
        return true;
    }
}