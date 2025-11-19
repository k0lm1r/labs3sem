#pragma once
#include <string>
#include "Exceptions.h"

class SafeInput {
    public:
    template<typename T>
    static void input(std::istream& is, T& obj, std::string message = "") {
        if (!message.empty())
            std::cout << message << std::endl;
        is >> obj;
        if (is.fail()) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw InputException(3, "Неверный ввод.");
        }
    }

    static double inputDigit(std::istream& is, std::string message = "", double min = INT_MIN, double max = INT_MAX) {
        double result;
        input(is, result, message);
        if (result < min) 
            throw InputException(2, "Введенное число меньше заданного ограничения.");
        else if (result > max) 
            throw InputException(1, "Введенное число больше заданного ограничения.");
        return result;
    }
};