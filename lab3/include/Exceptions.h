#pragma once
#include <stdexcept>

class Exception : public std::runtime_error {
    protected:
        int code = 0x6566;

    public:
        Exception(int code, std::string message) : std::runtime_error("Код: " + code + message), code(code) {}
};

class InputException : public Exception {
    public:
        InputException(int code, std::string message) : Exception(code, "Ошибка ввода: " + message) {}
};

class FileException : public Exception {
    public:
        FileException(int code, std::string message) : Exception(code, "Ошибка в файле: " + message) {}
};

class ContainerException : public Exception {
    public:
        ContainerException(int code, std::string message) : Exception(code, "Ошибка контейнера " + message) {}
};