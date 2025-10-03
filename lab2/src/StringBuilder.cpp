#include "StringBuilder.h"

StringBuilder::StringBuilder(const StringBuilder& other) : size(other.size) {
    std::copy(other.string, other.string + other.size, this->string);
}

StringBuilder::StringBuilder(const char* string) {
    this->setString(string);
}

void StringBuilder::setString(const char* string) {
    this->string = new char[strlen(string)];
    std::copy(string, string + strlen(string), this->string);
    this->size = strlen(string);
}

bool StringBuilder::operator!() {
    return size == 0;
}

StringBuilder StringBuilder::operator()(int first, int last) {
    char *substr = new char[last - first + 1];
    std::copy(this->string + first, this->string + last, substr);
    substr[last - first] = '\0';
    StringBuilder newString(substr);
    delete[] substr;
    return newString;
}

char StringBuilder::operator[](int index) {
    return this->string[index];
}

std::ostream& operator<<(std::ostream& os, const StringBuilder& str) {
    for (int i = 0; i < str.size; ++i) os << str.string[i];
    return os;
}

std::istream& operator>>(std::istream& in, StringBuilder& str) {
    int capacity = 5, index = 0;
    char* string = new char[capacity]; 
    char currentChar;

    currentChar = std::cin.get();
    while (currentChar != '\n') {
        if (index == capacity - 1) {
            capacity *= 2;
            char *newString = new char[capacity];
            std::copy(string, string + strlen(string), newString);
            delete[] string;
            string = newString;
        }
        string[index] = currentChar;
        currentChar = std::cin.get();
        index++;
    }
    string[index] = '\0';

    str.setString(string);
    delete[] string;
    return in;
}


StringBuilder::~StringBuilder() {
    if (string != nullptr) delete[] string;
}