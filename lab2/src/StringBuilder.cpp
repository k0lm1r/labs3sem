#include "StringBuilder.h"

StringBuilder::StringBuilder(const StringBuilder& other) : size(size) {
    std::copy(other.string, other.string + other.size, this->string);
}

void StringBuilder::setString(const char* string) {
    if (string != nullptr) {
        std::copy(string, string + strlen(string), this->string);
        this->size = strlen(string);
    }
}

bool StringBuilder::operator!() {
    return size == 0;
}

StringBuilder StringBuilder::operator()(int first, int last) {
    char *substr = new char[last - first];
    std::copy(this->string + first, this->string + last, substr);

    StringBuilder newString;
    newString.setString(substr);

    return newString;
}

char StringBuilder::operator[](int index) {
    return this->string[index];
}

std::ostream& operator<<(std::ostream& os, const StringBuilder& str) {
    os << str.string;
    return os;
}

std::istream& operator>>(std::istream& in, StringBuilder& str) {
    char* newString;

    
    
    str.setString(newString);
    return in;
}